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
    int N, P;
    std::cin >> N >> P;

    std::vector<std::vector<ll>> customers(N, std::vector<ll>(P));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < P; j++)
        {
            std::cin >> customers[i][j];
        }
        std::sort(customers[i].begin(), customers[i].end());
    }

    std::vector<std::vector<ll>> DP(N, std::vector<ll>(2, 0));
    DP[0][0] = customers[0][0] + customers[0][P - 1] - customers[0][0];
    DP[0][1] = customers[0][P - 1] + customers[0][P - 1] - customers[0][0];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int index = j == 0 ? 0 : P - 1;
            ll val0 = std::abs(customers[i][index] - customers[i - 1][0]) + DP[i - 1][1];
            ll val1 = std::abs(customers[i][index] - customers[i - 1][P - 1]) + DP[i - 1][0];
            DP[i][j] = std::min(val0, val1) + customers[i][P - 1] - customers[i][0];
        }
    }

    int minID = DP[N - 1][0] < DP[N - 1][1] ? 0 : 1;

    std::cout << DP[N - 1][minID] << std::endl;
}