// 3D Printing
#include <iostream>


void solve()
{
    int printer[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cin >> printer[i][j];
        }
    }

    const int maxUnit = 1000000;
    int min[4] = { maxUnit, maxUnit, maxUnit, maxUnit };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (printer[i][j] < min[j])
            {
                min[j] = printer[i][j];
            }
        }
    }

    int minSum = min[0] + min[1] + min[2] + min[3];
    if (minSum >= maxUnit)
    {
        int currentSum = 0;
        for (int j = 0; j < 4; j++)
        {
            if (currentSum + min[j] <= maxUnit)
            {
                std::cout << " " << min[j];
                currentSum += min[j];
            }
            else
            {
                std::cout << " " << (maxUnit - currentSum);
                currentSum = maxUnit;
            }
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << " IMPOSSIBLE" << std::endl;
    }
}
