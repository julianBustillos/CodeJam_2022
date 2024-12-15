#include <iostream>
#include <string>
#include <bitset>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits>
#include <algorithm>
#include <functional>
#include <random>

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;


struct Word
{
    std::string _val;
    bool _unique = true;
};

bool find(std::list<Word>& tower, std::string& result)
{
    if (tower.empty())
        return false;

    auto foundIter = tower.end();
    bool start = false;
    for (auto iter = tower.begin(); iter != tower.end(); iter++)
    {
        if (iter->_val.front() == result.back())
        {
            if (iter->_unique)
            {
                foundIter = iter;
                break;
            }
            if (foundIter != tower.end())
            {
                return true;
            }
            foundIter = iter;
        }
    }

    if (foundIter == tower.end())
    {
        start = true;
        for (auto iter = tower.begin(); iter != tower.end(); iter++)
        {
            if (iter->_val.back() == result.front())
            {
                if (iter->_unique)
                {
                    foundIter = iter;
                    break;
                }
                if (foundIter != tower.end())
                {
                    return true;
                }
                foundIter = iter;
            }
        }
    }

    if (foundIter != tower.end())
    {
        result = start ? foundIter->_val + result : result + foundIter->_val;
        tower.erase(foundIter);
        return find(tower, result);
    }
    return false;
}

bool contiguous(std::string result)
{
    std::set<char> checkSet;

    char prev = ' ';
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] != prev)
        {
            auto res = checkSet.insert(result[i]);
            if (res.second == false)
            {
                return false;
            }
            prev = result[i];
        }
    }
    return true;
}

void solve()
{
    int N;
    std::cin >> N;

    std::list<Word> tower;
    for (int i = 0; i < N; i++)
    {
        Word word;
        std::cin >> word._val;
        tower.push_back(word);
    }

    for (auto& word : tower)
    {
        for (int j = 1; word._unique && j < word._val.size(); j++)
        {
            if (word._val[j] != word._val[0])
            {
                word._unique = false;
            }
        }
    }

    std::string result = "";
    while (!tower.empty())
    {
        std::string temp = tower.begin()->_val;
        tower.erase(tower.begin());
        bool impossible = find(tower, temp);
        if (impossible)
        {
            std::cout << "IMPOSSIBLE" << std::endl;
            return;
        }
        result += temp;
    }

    if (!contiguous(result))
    {
        std::cout << "IMPOSSIBLE" << std::endl;
        return;
    }

    std::cout << result << std::endl;
}