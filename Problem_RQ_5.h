// Twinsty little passages

#include <iostream>
#include <vector>


struct Room
{
    long long _nbPassages = 0;
    bool _walked = false;
};

void solve()
{
    long long nbRooms, nbSteps;
    std::cin >> nbRooms >> nbSteps;

    std::vector<Room> rooms(nbRooms);
    long long firstUnknown = 0;

    for (long long step = 0; step <= nbSteps; step++)
    {
        long long R, P;
        std::cin >> R >> P;

        Room& currRoom = rooms[R - 1];
        currRoom._nbPassages = P;
        if (step % 2 == 0 && step > 1)
        {
            currRoom._walked = true;
        }

        if (step < nbSteps)
        {
            if (step % 2 == 0)
            {
                long long nextR = firstUnknown;
                for (nextR; nextR < nbRooms; nextR++)
                {
                    if (rooms[nextR]._nbPassages == 0)
                    {
                        nextR++;
                        break;
                    }
                }

                std::cout << "T " << nextR << std::endl;
            }
            else
            {
                std::cout << "W " << std::endl;
            }
        }
    }

    long long nbTeleported = 0, nbWalked = 0, nbUnknown = 0;
    long long sumPTeleported = 0, sumPSumWalked = 0;
    for (long long R = 0; R < nbRooms; R++)
    {
        if (rooms[R]._nbPassages == 0)
        {
            nbUnknown++;
        }
        else if (rooms[R]._walked)
        {
            nbWalked++;
            sumPSumWalked += rooms[R]._nbPassages;
        }
        else
        {
            nbTeleported++;
            sumPTeleported += rooms[R]._nbPassages;
        }
    }
    long long averagePTeleported = sumPTeleported / nbTeleported;

    long long result = (sumPSumWalked + sumPTeleported + nbUnknown * averagePTeleported) / 2;

    std::cout << "E " << result << std::endl;
}

