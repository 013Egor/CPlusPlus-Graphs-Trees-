#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Edge.h"
#include "priority_queue.h"

/*!\brief Алгоритм Дейкстра За O(Elog(V)) Операций
* Класс для выполнения быстрого варианта алгоритма Дейкстра.
*/
class Dijkstra {
	char start_point, finish_point;
	int edge_amount;
	std::vector<std::vector<Edge>> list;
	std::map<char, int> index;
	std::map<char, char> path;
	std::map<char, int> cost;
	std::set<char> visited;
	PriorityQueue queue;
public:
	///Загружает граф из файла
	void load(const std::string&);
	///Сохраняет исходный файл
	void save_graph(const std::string&);
	///Сохраняет граф после выполнения алгоритма Дейкстра
	void save(const std::string&);
	///Метод для создания очереди с приоритетом
	void make_queue();
	///Метод для выполнения алгоритма Дейкстра
	/*!
	* До выполнения этого метода должен быть загружен список смежности.
	*/
	void start();
	///Метод для обновления стоимости ребер
	void relax(Edge&);
	///Метод, проверяющий существования пути из вершины А в вершину Б
	bool path_exist();
};