#pragma once

class Node {
public:
	int value;
	int height;
	Node* l, * r;

	Node();
	Node(int value);
	Node(int value, Node* l, Node* r);
	~Node();

};

class AvlTree {
public:

	AvlTree();
	AvlTree(int value);
	AvlTree(Node* root);
	~AvlTree();

	void insRec(int value);

	int rootHeight();

	int select(int index);

	bool remove(int value);

private:

	Node* root;
	int size;

	int getHeight(Node* node);
	void updateHeight(Node* node);
	int bal_factor(Node* node);
	int search(int index, Node* node);

	Node* rebalance(Node* node);
	Node* leftRotate(Node* node);
	Node* rigthRotate(Node* node);

	Node* recInsert(Node* node, int val);


};