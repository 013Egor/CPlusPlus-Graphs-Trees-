#include "Cruscala.h"
#include <fstream>
#include <queue>
#include <iostream>
using namespace std;


void Cruscala::load(const string& filename) {
	ifstream fin(filename);
	if (!fin)
		exit(1);

	char parent, child;
	int weight = 0;

	while (!fin.eof()) {
		fin >> parent;
		fin >> child;
		fin >> weight;
		vertex.insert(child);
		vertex.insert(parent);
		edges.push_back(Edge(parent, child, weight));
		fin >> ws;
	}

	set<char>::iterator it = vertex.begin();
	for (int i = 0; i < vertex.size(); i++) 
		con_vert.push_back(vector<char>(1, *it++));
}


void Cruscala::save(const std::string& filename) {
	ofstream fout(filename);
	char parent, child;
	int weight;

	fout << "digraph G{\n";
	for (int i = 0; i < final_tree.size(); i++){
		parent = final_tree[i].get_parent();
		child = final_tree[i].get_child();
		weight = final_tree[i].get_weight();

		fout << parent << " -> " << child << "[label=" << weight << ", arrowhead=none];\n";
		}
	fout << "}";
}

void Cruscala::save_origin_graph(const std::string& filename) {
	ofstream fout("origin_" + filename);
	char parent, child;
	int weight;

	fout << "digraph G{\n";
	for (int i = 0; i < edges.size(); i++){
		parent = edges[i].get_parent();
		child = edges[i].get_child();
		weight = edges[i].get_weight();

		fout << parent << " -> " << child << "[label=" << weight << ", arrowhead=none];\n";
		}
	fout << "}";
}

struct cmp {//компаратор. Нужен для сравниваний ребер в очереди с приоритетом
	bool operator()(Edge& e1, Edge& e2) {
		return e1 > e2;
	}
};

void Cruscala::start() {
	Edge temp;
	priority_queue<Edge, vector<Edge>, cmp> queue;

	for (int i = 0; i < edges.size(); i++) 
		queue.push(edges[i]);

	while (!queue.empty()) {
		temp = queue.top();
		queue.pop();
		if (!is_connected(temp.get_child(), temp.get_parent()))
			final_tree.push_back(temp);
	}
}

bool Cruscala::is_connected(char v, char u) {
	int count = 0;
	int id1 = -1, id2 = -1;


	for (int i = 0; i < con_vert.size(); i++) {
		for (int j = 0; j < con_vert[i].size(); j++) {
			if (con_vert[i][j] == v || con_vert[i][j] == u)
				count++;
			if (count == 2)
				return true;
		}

		if (count == 1 && id1 == -1)
			id1 = i;
		else if (count == 1 && id2 == -1)
			id2 = i;

		count = 0;
	}
	if (id1 == -1 || id2 == -1)
		return false;

	for (int i = 0; i < con_vert[id2].size(); i++) 
		con_vert[id1].push_back(con_vert[id2][i]);
	con_vert[id2].clear();

	return false;
}