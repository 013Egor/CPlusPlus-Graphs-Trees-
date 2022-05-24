#pragma once
#include <string>
#include <vector>
#include <set>
#include "Edge.h"

class Cruscala {
	std::vector<Edge> edges; //Хранит все ребра начального графа
	std::vector<Edge> final_tree; //Ребра конечного графа(Оставное дерево)
	std::set<char> vertex; //Множество для хранения вершин
	std::vector<std::vector<char>> con_vert; //Не знаю как назвать, но это нужно для просмотра множества вершин, чтобы избедать циклов в графе
public:
	void load(const std::string&);
	void save(const std::string&);
	void save_origin_graph(const std::string&);
	void start();//Основа алгоритма
	bool is_connected(char, char);//вспомогательная функция для алгоритма, для проверки на соединенность вершин
};