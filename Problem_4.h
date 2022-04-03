// Chain reactions

#include <iostream>
#include <vector>
#include <stack>


struct Module
{
    unsigned long _funFactor = 0;
    int _next = 0;
    unsigned long _best = 0;
    std::vector<int> _prev;
};

void solve4()
{
    int nbModules;
    std::cin >> nbModules;

    std::vector<Module> modules(nbModules);
    for (int i = 0; i < nbModules; i++)
    {
        std::cin >> modules[i]._funFactor;
    }
    for (int i = 0; i < nbModules; i++)
    {
        std::cin >> modules[i]._next;
    }

    for (int i = 0; i < nbModules; i++)
    {
        int next = modules[i]._next;
        if (next > 0)
        {
            modules[next - 1]._prev.push_back(i + 1);
        }
    }

    int remaining = nbModules;
    std::vector<int> roots;
    for (int i = 0; i < nbModules; i++)
    {
        int next = modules[i]._next;

        if (modules[i]._next == 0)
        {
            roots.push_back(i + 1);
        }
    }

    unsigned long funSum = 0;
    std::vector<bool> called(nbModules, false);
    for (int root : roots)
    {
        std::stack<int> tree;
        tree.push(root);
        while (!tree.empty())
        {
            int curr = tree.top();
            if (modules[curr - 1]._prev.size() == 0)
            {
                modules[curr - 1]._best = modules[curr - 1]._funFactor;
                tree.pop();
            }
            else
            {
                if (called[curr - 1])
                {
                    unsigned long minBest = 1e10;
                    int minPrev = 0;
                    for (int prev : modules[curr - 1]._prev)
                    {
                        if (modules[prev - 1]._best < minBest)
                        {
                            minBest = modules[prev - 1]._best;
                            minPrev = prev;
                        }
                        funSum += modules[prev - 1]._best;
                    }

                    funSum -= minBest;
                    modules[curr - 1]._best = std::max(modules[curr - 1]._funFactor, minBest);
                    tree.pop();
                }
                else
                {
                    for (int prev : modules[curr - 1]._prev)
                    {
                        tree.push(prev);
                    }
                }
            }

            called[curr - 1] = true;
        }
        funSum += modules[root - 1]._best;
    }

    std::cout << funSum << std::endl;
}

