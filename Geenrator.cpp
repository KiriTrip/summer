#include "Generator.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <fstream>

void Generator::genLinear(int size) {
	std::vector<int> arr(size);
	std::ofstream out;

	out.open("C:\\Users\\Student\\Desktop\\genLinear.txt");
	for (int i = 0; i < size; ++i) {
		arr[i] = i;
		out << arr[i] << "\n";
	}
	out.close();
}

void Generator::genUnLinear(int size) {
	std::vector<int> arr(size);
	std::ofstream out;

	out.open("C:\\Users\\Student\\Desktop\\genUnLinear.txt");
	for (int i = size; i > 0; --i) {
		arr[size-i] = i;
		out << arr[i] << "\n";
	}
	out.close();
}

void Generator::genEven(int size) {
	std::vector<int> arr(size);
	std::ofstream out;

	out.open("C:\\Users\\Student\\Desktop\\genEven.txt");
	for (int i = 0; i < size; ++i) {
		arr[i] = (i + 1) * 2;
		out << arr[i] << "\n";
	}
	out.close();
}

void Generator::genOdd(int size) {
	std::vector<int> arr(size);
	std::ofstream out;

	out.open("C:\\Users\\Student\\Desktop\\genOdd.txt");
	for (int i  = 0; i < size; ++i) {
		arr[i] = 2 * i + 1;
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
	for (int i = 0; i < arr.size(); ++i) {
		arr[i] = distr(generator);
		out << arr[i] << "\n";
	}
	out.close();
}
