#include "AvlTree.hpp"
#include <iostream>

Node::Node() {
	int value = 0;
	l = r = nullptr;

	height = 1;
}

Node::Node(int value) {
	this->value = value;

	l = r = nullptr;
	height = 1;
}

Node::Node(int value, Node* l, Node* r) {
	this->value = value;

	this->l = l;
	this->r = r;
	height = 1 + std::max(r->height, l->height);
}

Node::~Node() {
	delete l;
	delete r;
}


AvlTree::AvlTree() {
	root = nullptr;
	size = 0;
}

AvlTree::AvlTree(int value) {
	size += 1;
	root = new Node(value);
}

AvlTree::AvlTree(Node* root) {
	this->root = root;
}

AvlTree::~AvlTree() {
	delete root;
}

Node* AvlTree::leftRotate(Node* node) {
	Node* c_node = node->r;
	node->r = c_node->l;
	c_node->l = node;
	updateHeight(node);
	updateHeight(c_node);
	return c_node;
}

Node* AvlTree::rigthRotate(Node* node) {
	Node* c_node = node->l;
	node->l = c_node->r;
	c_node->r = node;
	updateHeight(node);
	updateHeight(c_node);
	return c_node;
}

void AvlTree::insRec(int value) {
	root = recInsert(root, value);
	size++;
}

int position;

int AvlTree::search(int index, Node* node) {
	int buf;
	if (node->l != nullptr) {
		if ((buf = search(index, node->l)) != std::numeric_limits<int>::max()) {
			return buf;
		}
	}
	if (position == index) {
		return node->value;
	}
	position += 1;
	if (node->r != nullptr) {
		if ((buf = search(index, node->r)) != std::numeric_limits<int>::max()) {
			return buf;
		}
	}
}

int AvlTree::select(int index) {
	position = 0;	
	if (root == nullptr) {
		return std::numeric_limits<int>::max();
	}
	return search(index, root);
}

Node* AvlTree::recInsert(Node* node, int value) {
	if (!node) return new Node(value);

	if (value < node->value) {
		node->l = recInsert(node->l, value);
	}
	else node->r = recInsert(node->r, value);

	updateHeight(node);
	//rebalance(node);

	return rebalance(node);
}

int AvlTree::getHeight(Node* node) {
	return node ? node->height : 0;
}

int AvlTree::rootHeight() {
	return getHeight(root);
}

void AvlTree::updateHeight(Node* node) {
	if (node) {
		node->height = 1 + std::max(getHeight(node->l), getHeight(node->r));
	}
}

int AvlTree::bal_factor(Node* node) {
	return (getHeight(node->l) - getHeight(node->r));
}

bool AvlTree::remove(int value) {
	bool is_found = false, is_deleted = false;
	Node* c_node = root, *parent = nullptr, *buffer;

	if (root == nullptr) {
		return false;
	}



}

Node* AvlTree::rebalance(Node* node) {
	int bal_res = bal_factor(node);
	if (bal_res == 2) {
		if (bal_factor(node->l) < 0) {
			node->l = leftRotate(node->r);
		}
		return rigthRotate(node);
	}
	if (bal_res == -2) {
		if (bal_factor(node->r) > 0) {
			node->r = rigthRotate(node -> l);
		}
		return leftRotate(node);
	}

	return node;
}
