#include "Header.h"
using namespace std;

///Загружает граф из файла
/*!
* \param filename имя исходного файла
*/
void topological_sort::load(const std::string& filename) {
	std::ifstream fin(filename);

	int size, to_temp;
	char for_vertex, start_node;
	std::vector<int> temp;

	fin >> start_node;
	fin >> size;
	visited.resize(size);

	for (int i = 0; i < size; i++) {
		fin >> for_vertex;
		if (for_vertex == start_node)
			start_point = vertex.size();
		vertex.push_back(for_vertex);
	}

	for (int i = 0; i < size;i++) {
		for (int j = 0; j < size;j++) {
			fin >> to_temp;
			temp.push_back(to_temp);
		}
		matrix.push_back(temp);
		temp.clear();
	}
}

///Сохраняет граф после топологической сортировки
/*!
* \param filename имя выходного файла
*/
void topological_sort::save(const std::string& filename) {
	ofstream fout(filename);
	int count = 0;

	fout << "digraph G{\n";
	while (!mystack.empty()) {
		fout << mystack.top() << "[label=\"" << count++ << " | " << vertex[mystack.top()] << "\"];\n";
		mystack.pop();
	}

	multimap<int, int>::iterator it = edges.begin();

	while (it != edges.end()) {
		fout << it->first << "->" << it->second << ";\n";
		it++;
	}

	fout << "}";
}

///Сохраняет исходный граф
/*!
* \param filename имя выходного файла
*/
void topological_sort::save_origin(const std::string& filename) {
	ofstream fout("origin_" + filename);

	fout << "digraph G{\n";
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] != 0) {
				fout << vertex[i] << " -> " << vertex[j] << ";\n";
			}
		}
	}

	fout << "}";
}

//Метод для обхода в глубину
/*!
* \param start вершина с которой начинается обход
*/
void topological_sort::dfs(int start) {
	visited[start] = 1;
	for (int i = 0; i < matrix[start].size(); i++) {
		if (matrix[start][i] != 0 && visited[i] == 0) {
			edges.insert(pair<int, int>(start, i));
			dfs(i);
		}
	}
	mystack.push(start);
}

void topological_sort::start() {
	dfs(start_point);
}