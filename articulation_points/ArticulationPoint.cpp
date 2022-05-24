#include "ArticulationPoint.h"
using namespace std;

bool ArticulationPoint::load(const string& filename) {

	ifstream fin(filename);

	if (!fin)
		return false;

	int amount = 0, size = 0;
	int child;
	fin >> amount;

	graph.resize(amount);
	low.resize(amount);
	dfnumber.resize(amount);
	visited.resize(amount);

	fin >> ws;

	for (int i = 0; i < amount; i++) {

		fin >> size;
		for (int j = 0; j < size; j++) {
			fin >> child;
			graph[i].push_back(child);
		}
	}
}

bool ArticulationPoint::save_dot (const string& filename) {

	ofstream fout(filename);

	if (!fout)
		return false;

	fout << "digraph G{\n";

	for (int i = 0; i < vertex.size(); i++)
		fout << vertex[i] << "[style = filled, color = red];\n";

	for (int i = 0; i < graph.size(); i++)
		for (int j = 0; j < graph[i].size(); j++)
			if (i != graph[i][j])
				fout << i << " -> " << graph[i][j] << ";\n";

	fout << "}";
}

void ArticulationPoint::dfs (int curent_vertex, int parent) {

	visited[curent_vertex] = true;
	dfnumber[curent_vertex] = low[curent_vertex] = timer++;
	int count = 0;

	for (size_t i = 0; i < graph[curent_vertex].size(); i++) {
		int to = graph[curent_vertex][i];
		if (to == parent)
			continue;

		if (visited[to])
			low[curent_vertex] = min(low[curent_vertex], dfnumber[to]);
		else {
			count++;
			dfs(to, curent_vertex);
			low[curent_vertex] = min(low[curent_vertex], low[to]);
			if (low[to] >= dfnumber[curent_vertex] && parent != -1)
				vertex.push_back(curent_vertex);
		}
	}

	if (parent == -1 && count >= 2)
		vertex.push_back(curent_vertex);
}
