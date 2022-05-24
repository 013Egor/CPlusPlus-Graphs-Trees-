#include "Dijkstra.h"
#include <fstream>
#include <iostream>
using namespace std;

/*!
* \return true - если путь из начальной вершины существует; false - если путь из начальной вершины не существует
*/
bool Dijkstra::path_exist() {
char temp = finish_point;
	int count = 0;
	while (temp != start_point) {
		temp = path[temp];
		count++;
		if (count > edge_amount) {
			return false;
		}
	}
	return true;
}

/*!
* \param filename имя исходного файла
*/
void Dijkstra::load(const string& filename) {
	ifstream fin(filename);
	if (!fin)
		exit(1);

	char parent, child;
	int weight_node = 0, size = 0, id = 0;
	vector<Edge> temp_str;

	fin >> start_point;
	fin >> finish_point;
	edge_amount = 0;

	while (!fin.eof()) {
		fin >> size;
		fin >> parent;
		index.insert(pair<char, int>(parent, id++));
		for (int i = 0; i < size; i++) {
			edge_amount++;
			fin >> weight_node;
			fin >> child;
			temp_str.push_back(Edge(parent, child, weight_node));
		}
		list.push_back(temp_str);
		temp_str.clear();
		fin >> ws;
	}
}

/*!
* \param filename имя выходного файла с кратчайшими путями
*/
void Dijkstra::save(const string& filename) {
	ofstream fout(filename);
	map<char, char>::iterator it;
	char temp, p = finish_point;

	if (!path_exist()) {
		fout << "digraph G{\n error;\n}";
		return;
	}
	
	fout << "digraph G{\n";
	while (p != start_point) {
		fout << path[p] << "->" << p << "[color=red, label=" << cost[p] << "];\n";
		temp = path[p];
		path.erase(p);
		p = temp;
	}
	it = path.begin();
	while (it != path.end()) {
		fout << it->second << " -> " << it->first << "[label=" << cost[it->first] << "];\n";
		it++;
	}
	fout << start_point << " -> " << finish_point << "[label=\"Min: " << cost[finish_point] << "\",color = purple, arrowhead=\"none\"];\n";
	fout << '}';
}

/*!
* \param filename имя выходного файла с начальным графом
*/
void Dijkstra::save_graph(const std::string& filename) {
	ofstream fout("graph.dot");
	char parent, child;
	int weight;

	fout << "digraph G{\n";
	for (int i = 0; i < list.size(); i++) 
		for (int j = 0; j < list[i].size(); j++) {
			parent = list[i][j].get_parent();
			child = list[i][j].get_child();
			weight = list[i][j].get_weight();
			fout << parent << " -> " << child << "[label=" << weight << "];\n";
		}
	fout << "}";
}

void Dijkstra::make_queue() {
	queue.set_size(edge_amount);
	int id = index[start_point];
	char child, parent = start_point;
	int weight;

	for (int i = 0; i < list[id].size();i++) {
		child = list[id][i].get_child();
		weight = list[id][i].get_weight();
		queue.insert(Edge(parent, child, weight));
	}
}

void Dijkstra::start() {
	make_queue();
	Edge v;
	
	while(!queue.empty()) {
		v = queue.pop();
		if (visited.find(v.get_child()) == visited.end() && v.get_child() != start_point) {
			path[v.get_child()] = v.get_parent();
			visited.insert(v.get_child());
			cost[v.get_child()] = v.get_weight();
			relax(v);
		}
	}
}

/*!
* \param v ребро, по потомку которого будет происходить обновление стоимостей вершин
*/
void Dijkstra::relax(Edge& v) {
	map<char, int>::iterator it = index.find(v.get_child());
	if (it == index.end())
		return;

	int id = it->second;
	char child, parent = v.get_child();
	int weight;

	for (int i = 0; i < list[id].size();i++) {
		child = list[id][i].get_child();
		weight = v.get_weight() + list[id][i].get_weight();
		queue.insert(Edge(parent, child, weight));
	}
}