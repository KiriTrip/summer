#include "AvlTree.hpp"
#include "Generator.hpp"
#include <chrono>
#include <ctime>
#include <iostream>

void GearData(int size) {
	int cnt = 0;
	//std::ofstream out;
	//out.open("C:\\Users\\Student\\Desktop\\genOdd.txt");
	AvlTree testTree;

	for (int i = 0; i < size; ++i)
	{
		if (size >= 100)
		{
			if (cnt < 25) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				testTree.insRec(i);
				//out << arg << std::endl;
				cnt++;

			}
			if (cnt >= 25) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				testTree.insRec(i);
				//out << arg << std::endl;
				cnt++;
			}
			if (cnt > 50) { cnt = 0; }
		}

		if (size < 100)
		{
			if (i % 2 == 0) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				testTree.insRec(i);
				//out << arg << std::endl;
				cnt++;
			}
			if (i % 2 != 0) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				testTree.insRec(i);

				//out << arg << std::endl;
				cnt++;
			}
		}
	}
	std::cout << testTree.rootHeight();
	//out.close();
}

int main() {
	
	AvlTree tTree;
	GearData(1000000000);
	


	return 0;
}
