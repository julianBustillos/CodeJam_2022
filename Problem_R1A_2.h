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
#include <algorithm>
#include <functional>
#include <random>

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;


void solve()
{
    uint N;
    std::cin >> N;

    std::vector<ull> numbers(2 * N);
    uint limit = std::min(N, (uint)30);
    ull sum = 0;

    for (uint i = 0; i < limit; i++)
    {
        numbers[i] = ((ull)1 << (ull)i);
        sum += numbers[i];
        std::cout << numbers[i] << " ";
    }
    for (uint i = limit; i < N; i++)
    {
        numbers[i] = numbers[29] + i - 29;
        sum += numbers[i];
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    for (uint i = N; i < 2 * N; i++)
    {
        std::cin >> numbers[i];
        sum += numbers[i];
    }

    sum /= 2;

    for (uint i = limit; i < 2 * N; i++)
    {
        if (numbers[i] <= sum)
        {
            sum -= numbers[i];
            std::cout << numbers[i] << " ";
        }
    }

    for (uint i = 0; i < limit; i++)
    {
        if (numbers[i] & sum)
        {
            std::cout << numbers[i] << " ";
        }
    }

    std::cout << std::endl;
}