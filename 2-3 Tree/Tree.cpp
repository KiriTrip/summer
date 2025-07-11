#include "Tree.h"
#include <limits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fcntl.h>
#include<Windows.h>
#include<io.h>

#include <random>
#include <cstdlib>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

NodeInt::NodeInt(bool leaf)
{
	is_leaf = leaf;
	keys.clear();
	child.clear();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

NodeInt::~NodeInt()
{
	;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

TreeInt::TreeInt()
{
	root = nullptr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

TreeInt::~TreeInt()
{
	delete root;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TreeInt::insert(int key)
{
	if (!root)
	{
		root = new NodeInt(true);
		root->keys.push_back(key);
	}
	else {
		int promotedkey = 0;
		NodeInt* newChild = nullptr;
		NodeInt* newroot = insert(root, key, promotedkey, newChild);

		if (newroot) {
			NodeInt* newInt = new NodeInt(false);
			newInt->keys.push_back(promotedkey);
			newInt->child.push_back(root);
			newInt->child.push_back(newChild);
			root = newInt;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

NodeInt* TreeInt::insert(NodeInt* node, int key, int& promotedKey, NodeInt*& NewChild)
{
	if (node->is_leaf)
	{
		node->keys.push_back(key);

		std::sort(node->keys.begin(), node->keys.end());
		auto last = std::unique(node->keys.begin(), node->keys.end());
		node->keys.erase(last, node->keys.end());

		if (node->keys.size() <= 2) { return nullptr; }

		NodeInt* tree = new NodeInt(true);
		promotedKey = node->keys[1];

		tree->keys.push_back(node->keys[2]);
		node->keys.erase(node->keys.begin() + 1, node->keys.end());

		NewChild = tree;
		return node;

	}
	int i = 0;
	for (; i < node->keys.size() && key > node->keys[i]; ++i) { ; }

	int innerPromotedKey = 0;
	NodeInt* split = nullptr;


	NodeInt* child0 = insert(node->child[i], key, innerPromotedKey, split);
	if (!child0) { return nullptr; }

	node->keys.insert(node->keys.begin() + i, innerPromotedKey);
	node->child.insert(node->child.begin() + i + 1, split);


	if (node->keys.size() <= 2) { return nullptr; }

	NodeInt* tree = new NodeInt(false);
	promotedKey = node->keys[1];


	tree->keys.push_back(node->keys[2]);
	tree->child.push_back(node->child[2]);
	tree->child.push_back(node->child[3]);

	node->keys.erase(node->keys.begin() + 1, node->keys.end());
	node->child.erase(node->child.begin() + 2, node->child.end());

	NewChild = tree;
	return node;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool TreeInt::search(int x)
{
	NodeInt* curr = root;

	while (curr) {
		for (int k : curr->keys) {
			if (x == k) { return true; }
		}
		
		if (curr->is_leaf) { return false; }

		int i = 0;
		for (; i < curr->keys.size() && x > curr->keys[i]; i++) { ; }

		curr = curr->child[i];
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TreeInt::print(NodeInt* node, const std::string& prefix, bool isLast) {
	SetConsoleCP(CP_UTF8);

	std::locale::global(std::locale("en_US.UTF-8"));
	std::cout.imbue(std::locale());


	std::cout << prefix;

	// └── или ├──
	std::cout << (isLast ? "└── " : "├── ");

	// Печать ключей
	std::cout << "[";
	for (size_t i = 0; i < node->keys.size(); ++i) {
		std::cout << node->keys[i];
		if (i + 1 != node->keys.size()) std::cout << ", ";
	}
	std::cout << "]" << std::endl;

	// Переход к детям
	for (size_t i = 0; i < node->child.size(); ++i) {
		bool lastChild = (i == node->child.size() - 1);
		print(node->child[i], prefix + (isLast ? "    " : "│   "), lastChild);
	}


}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int TreeInt::height()
{
	NodeInt* curr = root;
	int hei = 0;

	while (curr && !curr->is_leaf) {
			++hei;
			curr = curr->child[0];
		}

		return hei;
	}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TreeInt::print() {
	print(root, "", true);
	std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TreeInt::genLinear(int size) {
	std::vector<int> arr(size);

	for (int i = 0; i < size; ++i) {
		//
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TreeInt::genRand(int size) {
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<> distr(0, size);

	for (int i = 0; i < size; ++i) {
		//
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TreeInt::GearData(int size) {
	int cnt = 0;
	for (int i = 0; i < size; ++i)
	{
		if (size > 100)
		{
			if (cnt < 25) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				//
				cnt++;
			}
			if (cnt >= 25) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				//
				cnt++;
			}
			if (cnt > 50) { cnt = 0; }
		}

		if (size < 100)
		{
			if (i % 2 == 0) {
				int arg = (0 + std::rand() % ((i + 1) * 2 - 0));
				//
				cnt++;
			}
			if (i % 2 != 0) {
				int arg = (i * 2 + std::rand() % ((i + 1) * 2 - 10));
				//
				cnt++;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


