// d1000000

#include <iostream>
#include <algorithm>
#include <vector>


void solve()
{
    int nbDices;
    std::cin >> nbDices;

    std::vector<int> dices(nbDices);
    for (int i = 0; i < nbDices; i++)
    {
        std::cin >> dices[i];
    }
    std::sort(dices.begin(), dices.end());

    int straightSize = 0;
    int nextNumber = 1;
    for (int i = 0; i < nbDices; i++)
    {
        if (dices[i] >= nextNumber)
        {
            straightSize++;
            nextNumber++;
        }
    }

    std::cout << straightSize << std::endl;
}
