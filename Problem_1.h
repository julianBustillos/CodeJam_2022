// Punched cards

#include <iostream>


void solve1()
{
    std::cout << std::endl;
    int R = 0, C = 0;
    std::cin >> R;
    std::cin >> C;

    std::cout << "..+";
    for (int col = 1; col < C; col++)
    {
        std::cout << "-+";
    }
    std::cout << std::endl;

    for (int row = 0; row < R; row++)
    {
        std::cout << (row == 0 ? "." : "|");
        for (int col = 0; col < C; col++)
        {
            std::cout << ".|";
        }
        std::cout << std::endl;

        std::cout << "+";
        for (int col = 0; col < C; col++)
        {
            std::cout << "-+";
        }
        std::cout << std::endl;
    }

}
