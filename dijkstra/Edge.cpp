#include "Edge.h"
#include <iostream>
Edge::Edge() {
	this->weight = 0;
}

Edge::Edge(char v1, char v2, int w) {
	this->parent = v1;
	this->child = v2;
	this->weight = w;
}

/*!
* \param edge - ребро, с которым сравнивается вес
* \return true - если вес ребра слева меньше ребра справа; false - если вес ребра слева больше ребра справа
*/
bool Edge::operator<(const Edge& edge) {
	return this->weight < edge.weight;
}

/*!
* \param edge - ребро, с которым сравнивается вес
* \return true - если вес ребра слева больше ребра справа; false - если вес ребра слева меньше ребра справа
*/
bool Edge::operator>(const Edge& edge) {
	return this->weight > edge.weight;
}

/*!
* \param e - ребро, значение которого нужно присвоить вызывающему объекту
* \return объект класса Edge с присвонными значениями
*/
Edge& Edge::operator=(const Edge& e) {
	parent = e.parent;
	child = e.child;
	weight = e.weight;

	return *this;
}