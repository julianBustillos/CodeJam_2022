#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <stack>
#include <cmath>

#include "Problem_RQ_5.h"


int main(int argc, char* argv[])
{
    int nbTests = 0;
    std::cin >> nbTests;

    for (int test = 1; test <= nbTests; test++)
    {
        //std::cout << "Case #" << std::to_string(test) << ": ";
        solve();
    }
}


