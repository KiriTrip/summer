#include "AvlTree.hpp"
#include "Generator.hpp"
#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using clocks = std::chrono::high_resolution_clock;
using nanoseconds = std::chrono::nanoseconds;

//void GearData(int size) {
//	int cnt = 0;
//	std::set<int> s1;
//	std::ofstream out;
//	//AvlTree testTree;
//
//	out.open("C:\\Users\\Student\\Desktop\\sharkTestSet.txt");
//	for (int i = 0; i < size; ++i)
//	{
//		if (size >= 100)
//		{
//			if (cnt < 25) {
//				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
//				auto start1 = clocks::now();
//				s1.insert(i);
//				auto elapsed1 = clocks::now() - start1;
//				out << std::chrono::duration_cast<nanoseconds>(elapsed1).count() /*arg*/ << std::endl;
//				cnt++;
//
//			}
//			if (cnt >= 25) {
//				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
//				auto start2 = clocks::now();
//				s1.insert(i);
//				auto elapsed2 = clocks::now() - start2;
//				out << std::chrono::duration_cast<nanoseconds>(elapsed2).count() /*arg*/ << std::endl;
//				cnt++;
//			}
//			if (cnt > 50) { cnt = 0; }
//		}
//
//		if (size < 100)
//		{
//			if (i % 2 == 0) {
//				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
//				auto start3 = clocks::now();
//				s1.insert(i);
//				auto elapsed3 = clocks::now() - start3;
//				out << std::chrono::duration_cast<nanoseconds>(elapsed3).count() /*arg*/ << std::endl;
//				cnt++;
//			}
//			if (i % 2 != 0) {
//				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
//				auto start4 = clocks::now();
//				s1.insert(i);
//				auto elapsed4 = clocks::now() - start4;
//				out << std::chrono::duration_cast<nanoseconds>(elapsed4).count() /*arg*/ << std::endl;
//				cnt++;
//			}
//		}
//	}
//	//std::cout << testTree.rootHeight();
//	out.close();
//}

//void genEven(int size) {
//	//AvlTree testTree;
//	std::set<int> s1;
//	std::ofstream out;
//
//
//	out.open("C:\\Users\\Student\\Desktop\\evenTestSet.txt");
//	for (int i = 0; i < size; ++i) {
//		auto start1 = clocks::now();
//		int count = (i + 1) * 2;
//		s1.insert(count);
//		auto elapsed1 = clocks::now() - start1;
//		out << std::chrono::duration_cast<nanoseconds>(elapsed1).count() << "\n";
//	}
//	out.close();
//}

// Заполнение массива чётными

//void genEven(int size) {
//	AvlTree testTree;
//	std::set<int> s1;
//
//	for (int i = 0; i < size; ++i) {
//		int count = (i + 1) * 2;
//		s1.insert(count);
//	}

// Удаляем из массива

	/*std::cout << tTree.rootHeight() << "\n";

	out.open("C:\\Users\\Student\\Desktop\\removeTestAvl.txt");
	for (int i = 0; i < size; ++i) {
		auto start1 = clocks::now();
		s1.erase(i);
		auto elapsed1 = clocks::now() - start1;
		out << std::chrono::duration_cast<nanoseconds>(elapsed1).count() << "\n";
	}

	std::cout << tTree.rootHeight() << "\n";*/
//}

void GearData(int size) {
	int cnt = 0;
	std::set<int> s1;
	std::ofstream out;
	AvlTree testTree;

	//out.open("C:\\Users\\Student\\Desktop\\sharkTestSet.txt");
	for (int i = 0; i < size; ++i)
	{
		if (size >= 100)
		{
			if (cnt < 25) {	
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				auto start1 = clocks::now();
				testTree.insRec(i);
				auto elapsed1 = clocks::now() - start1;
				//out << std::chrono::duration_cast<nanoseconds>(elapsed1).count() /*arg*/ << std::endl;
				cnt++;

			}
			if (cnt >= 25) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				auto start2 = clocks::now();
				testTree.insRec(i);
				auto elapsed2 = clocks::now() - start2;
				//out << std::chrono::duration_cast<nanoseconds>(elapsed2).count() /*arg*/ << std::endl;
				cnt++;
			}
			if (cnt > 50) { cnt = 0; }
		}

		if (size < 100)
		{
			if (i % 2 == 0) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				auto start3 = clocks::now();
				testTree.insRec(i);
				auto elapsed3 = clocks::now() - start3;
				//out << std::chrono::duration_cast<nanoseconds>(elapsed3).count() /*arg*/ << std::endl;
				cnt++;
			}
			if (i % 2 != 0) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				auto start4 = clocks::now();
				testTree.insRec(i);
				auto elapsed4 = clocks::now() - start4;
				//out << std::chrono::duration_cast<nanoseconds>(elapsed4).count() /*arg*/ << std::endl;
				cnt++;
			}
		}
	}
	//std::cout << testTree.rootHeight();
	//out.close();
}

int main() {
	AvlTree testTree;
	std::set<int> s1;
	std::ofstream out;
	
	int cnt = 0;
	int size = 1e6;

	// Заполняем массив

	for (int i = 0; i < size; ++i)
	{
		if (size >= 100)
		{
			if (cnt < 25) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				auto start1 = clocks::now();
				testTree.insRec(i);
				auto elapsed1 = clocks::now() - start1;
				//out << std::chrono::duration_cast<nanoseconds>(elapsed1).count() /*arg*/ << std::endl;
				cnt++;

			}
			if (cnt >= 25) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				auto start2 = clocks::now();
				testTree.insRec(i);
				auto elapsed2 = clocks::now() - start2;
				//out << std::chrono::duration_cast<nanoseconds>(elapsed2).count() /*arg*/ << std::endl;
				cnt++;
			}
			if (cnt > 50) { cnt = 0; }
		}

		if (size < 100)
		{
			if (i % 2 == 0) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				auto start3 = clocks::now();
				testTree.insRec(i);
				auto elapsed3 = clocks::now() - start3;
				//out << std::chrono::duration_cast<nanoseconds>(elapsed3).count() /*arg*/ << std::endl;
				cnt++;
			}
			if (i % 2 != 0) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				auto start4 = clocks::now();
				testTree.insRec(i);
				auto elapsed4 = clocks::now() - start4;
				//out << std::chrono::duration_cast<nanoseconds>(elapsed4).count() /*arg*/ << std::endl;
				cnt++;
			}
		}
	}

	// Ищем элемент
	
	out.open("C:\\Users\\Student\\Desktop\\searchTestSet.txt");
	for (int i = 0; i < size; ++i) {
		auto start = clocks::now();
		testTree.select(0);
		auto elapsed = clocks::now() - start;
		out << std::chrono::duration_cast<nanoseconds>(elapsed).count() << "\n";
	}
	out.close();
	return 0;
}
