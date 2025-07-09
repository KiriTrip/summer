#include <iostream>
#include "Tree.h"

int main() {
	TreeInt Int;

	int size, elem, cnt = 0;
	std::cin >> size >> elem;
	//std::cout << sizeof(int);

	
	for (int i = 0; i < size; ++i)
	{
		if (size > 100)
		{
			if (cnt < 25) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				Int.insert(arg);
				cnt++;
			}
			if (cnt >= 25) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				Int.insert(arg);
				cnt++;
			}
			if (cnt > 50) { cnt = 0; }
		}

		if (size < 100)
		{
			if (i % 2 == 0) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				Int.insert(arg);
				cnt++;
			}
			if (i % 2 != 0) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				Int.insert(arg);
				cnt++;
			}
		}
	}

	Int.print();
	
	if (Int.search(elem)) std::cout << "YES" << std::endl;
	
	else std::cout << "NO" << std::endl;

	std::cout << Int.height();

	return 0;
}