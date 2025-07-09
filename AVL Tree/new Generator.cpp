#include "Generator.hpp"
#include "AvlTree.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <ctime>

void Generator::genLinear(int size) {
	std::vector<int> arr(size);
	AvlTree testTree;
	std::ofstream out;

	out.open("C:\\Users\\Student\\Desktop\\genLinear.txt");
	for (int i = 0; i < size; ++i) {
		
	}
	out.close();
}

void Generator::genUnLinear(int size) {
	std::vector<int> arr(size);
	std::ofstream out;

	out.open("C:\\Users\\Student\\Desktop\\genUnLinear.txt");
	for (int i = size; i > 0; --i) {
		arr.push_back(i);
		out << arr[i] << "\n";
	}
	out.close();
}

void Generator::genEven(int size) {
	std::vector<int> arr(size);
	std::ofstream out;


	out.open("C:\\Users\\Student\\Desktop\\genEven.txt");
	for (int i = 0; i < size; ++i) {
		int count = (i + 1) * 2;
		arr[i] = count;
		std::cout << arr[i] << "\n";
		out << arr[i] << "\n";
	}
	out.close();
}

void Generator::genOdd(int size) {
	std::vector<int> arr(size);
	std::ofstream out;

	out.open("C:\\Users\\Student\\Desktop\\genOdd.txt");
	for (int i = 0; i < size; ++i) {
		arr[i] = (2 * i + 1);
		out << arr[i] << "\n";
	}
	out.close();
}

void Generator::genRand(int size) {
	std::vector<int> arr(size);
	std::ofstream out;

	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<> distr(0, size);

	out.open("C:\\Users\\Student\\Desktop\\genRand.txt");
	for (int i = 0; i < size; ++i) {
		arr[i] = distr(generator);
		out << arr[i] << "\n";
	}
	out.close();
}

void Generator::GearData(int size) {
	int cnt = 0;
	std::ofstream out;
	out.open("C:\\Users\\Student\\Desktop\\genOdd.txt");

	for (int i = 0; i < size; ++i)
	{
		if (size > 100)
		{
			if (cnt < 25) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				out << arg << std::endl;
				cnt++;
			}
			if (cnt >= 25) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				out << arg << std::endl;
				cnt++;
			}
			if (cnt > 50) { cnt = 0; }
		}

		if (size < 100)
		{
			if (i % 2 == 0) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				out << arg << std::endl;
				cnt++;
			}
			if (i % 2 != 0) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				out << arg << std::endl;
				cnt++;
			}
		}
	}
	out.close();
}

//void TreeInt::print(NodeInt* node, const std::string& prefix, bool isLast) {
//	std::cout << prefix;
//
//	// └── или ├──
//	std::cout << (isLast ? "└── " : "├── ");
//
//	// Печать ключей
//	std::cout << "[";
//	for (size_t i = 0; i < node->keys.size(); ++i) {
//		std::cout << node->keys[i];
//		if (i + 1 != node->keys.size()) std::cout << ", ";
//	}
//	std::cout << "]" << std::endl;
//
//	// Переход к детям
//	for (size_t i = 0; i < node->child.size(); ++i) {
//		bool lastChild = (i == node->child.size() - 1);
//		print(node->child[i], prefix + (isLast ? "    " : "│   "), lastChild);
//	}
//}
//
//void TreeInt::print() {
//	print(root, "", true);
//}
