#include <iostream>
#include "Tree.h"

int main() {
	TreeInt Int;

	int cnt = 0;
	int size;
	std::cin >> size;

	for (int i = 0; i < size; ++i)
	{
		if (size > 100)
		{
			if (cnt < 25) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				Int.insert(arg);
				Int.print();
				cnt++;
			}
			if (cnt >= 25) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				Int.insert(arg);
				Int.print();
				cnt++;
			}
			if (cnt > 50) { cnt = 0; }
		}

		if (size < 100)
		{
			if (i % 2 == 0) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				Int.insert(arg);
				Int.print();
				cnt++;
			}
			if (i % 2 != 0) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				Int.insert(arg);
				Int.print();
				cnt++;
			}
		}
	}
	
	//Int.print();
	return 0;
}