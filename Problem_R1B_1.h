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


void solve()
{
    int N;
    std::cin >> N;
    std::deque<ull> pancakes;

    for (int i = 0; i < N; i++)
    {
        ull D;
        std::cin >> D;
        pancakes.push_back(D);
    }

    int nbPay = 0;
    ull maxD = 0;
    while (!pancakes.empty())
    {
        ull frontD = pancakes.front();
        ull backD = pancakes.back();
        ull chosenD = 0;
        if (frontD < backD)
        {
            chosenD = frontD;
            pancakes.pop_front();
        }
        else
        {
            chosenD = backD;
            pancakes.pop_back();
        }

        if (chosenD >= maxD)
        {
            maxD = chosenD;
            nbPay++;
        }
    }

    std::cout << nbPay << std::endl;
}