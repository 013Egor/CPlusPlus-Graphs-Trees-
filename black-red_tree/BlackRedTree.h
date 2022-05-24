#pragma once
#include "Node.h"
#include <string>
#include <map>
#include <set>
#include <fstream>

class Tree {
	Node* root;
	std::multimap<int, int> graph;
	std::map<int, bool> colors;
	std::set<int> last;
public:
	Tree() { root = NULL; }
	~Tree() { deleteTree(root); }

	bool load(const std::string& filename);
	bool save(const std::string& filename);

	bool find(int num);

	void insert(int num, int pos);

	void leftRotate(Node* turn_point);
	void rightRotate(Node* turn_point);
	void colorFix(Node* node_to_check);
	void deleteTree(Node* cur);

	void makeGraph(Node* cur);
	void makeLabel(Node* cur, std::ofstream& fout);
};
