#include "AvlTree.hpp"
#include "Generator.hpp"
#include <iostream>
#include <vector>

int main()
{
    AvlTree testTree;
    std::vector<int> arr(10);

    // Generator::genEven(arr.size());

    for (int i = 0; i < 1e7; ++i) {


        testTree.insRec(i);
        if (i % 10000 == 0) {
            std::cout << testTree.rootHeight() << "\n";
        }
    }
}