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
    int E, W;
    std::cin >> E >> W;

    std::vector<std::vector<int>> exercices(E);
    for (int e = 0; e < E; e++)
    {
        exercices[e].resize(W);
        for (int w = 0; w < W; w++)
        {
            std::cin >> exercices[e][w];
        }
    }

    std::vector<std::vector<int>> common(E, std::vector<int>(E, 0));
    for (int ei = 0; ei < E; ei++)
    {
        std::vector<int> accMin(W, std::numeric_limits<int>::max());
        for (int ej = ei; ej < E; ej++)
        {
            for (int w = 0; w < W; w++)
            {
                accMin[w] = std::min(accMin[w], exercices[ej][w]);
                common[ei][ej] += accMin[w];
            }
        }
    }

    std::vector<std::vector<int>> DP(E, std::vector<int>(E, 0));
    for (int ei = E; ei >= 0; ei--)
    {
        for (int ej = ei + 1; ej < E; ej++)
        {
            DP[ei][ej] = std::numeric_limits<int>::max();
            for (int ek = ei; ek < ej; ek++)
            {
                DP[ei][ej] = std::min(DP[ei][ej], DP[ei][ek] + DP[ek + 1][ej] + common[ei][ek] + common[ek + 1][ej] - 2 * common[ei][ej]);
            }
        }
    }

    std::cout << 2 * (DP[0][E - 1] + common[0][E - 1]) << std::endl;
}