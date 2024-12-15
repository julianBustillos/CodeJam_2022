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
    int N, K;
    std::cin >> N >> K;

    std::vector<ll> elements(N);
    ll S = 0, SQ = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> elements[i];
        S += elements[i];
        SQ += elements[i] * elements[i];
    }

    std::vector<ll> answer;
    ll A = 2 * S;
    ll B = SQ - S * S;

    if (A == 0 && B == 0)
    {
        answer.push_back(0);
    }
    else if (A != 0 && B % A == 0)
    {
        ll X = B / A;
        answer.push_back(X);
    }
    else if (K > 1)
    {
        ll C = 1 - S;
        ll D = (SQ - S * S) / 2 - C * S;
        answer.push_back(C);
        answer.push_back(D);
    }

    if (!answer.empty())
    {
        for (int x : answer)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "IMPOSSIBLE" << std::endl;
    }
}
