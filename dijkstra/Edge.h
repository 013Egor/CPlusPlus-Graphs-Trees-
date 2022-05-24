#pragma once

/**\brief Класс для хранения ребра
* Класс хранит две соединенные ребром вершины и вес ребра
*/
class Edge {
	char parent;
	char child;
	int weight;
public:
	///Конструктор
	Edge();
	///Деструктор
	Edge(char, char, int);
	///Метод, возвращающий имя вершины-родителя
	/*!
	* /return имя вершины-родителя
	*/
	char get_parent() { return parent; }
	///Метод, возвращающий имя вершины-потомка
	/*!
	* /return имя вершины-потомка
	*/
	char get_child() { return child; }
	//*Метод, возвращающий вес ребра
	/*!
	* /return вес ребра
	*/
	int get_weight() { return weight; }
	///Перегруженный оператор для сравнения весов ребер
	bool operator<(const Edge&);
	///Перегруженный оператор для сравнения весов ребер
	bool operator>(const Edge&);
	///Перегруженный оператор для присваивания ребра
	Edge& operator=(const Edge&);
};