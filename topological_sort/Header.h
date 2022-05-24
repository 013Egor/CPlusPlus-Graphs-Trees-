#pragma once
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <fstream>
#include <iostream>

/*!\brief Алгоритм топологической сортировки
* Класс для выполнения топологической сортировки.
*/
class topological_sort {
	std::vector<std::vector<int>> matrix;
	std::vector<char> vertex;
	std::multimap<int, int> edges;
	std::stack<int> mystack;
	std::vector<int> visited;
	int start_point;
public:
	void load(const std::string&);
	void save(const std::string&);
	void save_origin(const std::string&);
	void dfs(int);
	//метод для запуска алгортма сортировки
	void start();
};