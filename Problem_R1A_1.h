#include <iostream>
#include <string>


void solve()
{
    std::string word;
    std::cin >> word;

    int sameLetterCount = 0;
    for (int i = 0; i < word.size() - 1; i++)
    {
        int letter = (int)word[i] - (int)'A';
        int letterNext = (int)word[i + 1] - (int)'A';

        if (letter == letterNext)
        {
            sameLetterCount++;
        }
        else
        {
            if (letter < letterNext)
            {
                for (int k = 0; k < sameLetterCount + 1; k++)
                {
                    std::cout << word[i] << word[i];
                }
            }
            else
            {
                for (int k = 0; k < sameLetterCount + 1; k++)
                {
                    std::cout << word[i];
                }
            }
            sameLetterCount = 0;
        }
    }

    for (int k = 0; k < sameLetterCount; k++)
    {
        std::cout << word.back();
    }

    std::cout << word.back() << std::endl;
}
