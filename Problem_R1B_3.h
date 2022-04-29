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


void fillP(std::vector<std::vector<int>>& P, int index)
{
    if (index == 0)
    {
        P[index].push_back(1);
    }
    else
    {
        fillP(P, index - 1);

        int size = P[index - 1].size();
        std::vector<int> zeros(size);
        std::vector<int> copy(size);
        for (int i = 0; i < size; i++)
        {
            int shift = 1 << (index - 1);
            zeros[i] = P[index - 1][i] << shift;
            copy[i] = (P[index - 1][i] << shift) + P[index - 1][i];
        }

        P[index] = copy;
        for (int i = 0; i < size; i++)
        {
            P[index].push_back(zeros[i]);
            P[index].insert(P[index].end(), copy.begin(), copy.end());
        }
    }
}

void solve()
{
    uint N = 1;
    std::vector<std::vector<int>> P(4, std::vector<int>());
    fillP(P, 3);

    int step = 0;
    while (N > 0)
    {
        for (int i = 7; i >= 0; i--)
        {
            if (P[3][step] & (1 << i))
            {
                std::cout << 1;
            }
            else
            {
                std::cout << 0;
            }
        }
        std::cout << std::endl;

        if (step + 1 < P[3].size())
            step++;

        std::cin >> N;
    }
}
