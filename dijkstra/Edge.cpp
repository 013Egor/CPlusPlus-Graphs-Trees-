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
* \param edge - �����, � ������� ������������ ���
* \return true - ���� ��� ����� ����� ������ ����� ������; false - ���� ��� ����� ����� ������ ����� ������
*/
bool Edge::operator<(const Edge& edge) {
	return this->weight < edge.weight;
}

/*!
* \param edge - �����, � ������� ������������ ���
* \return true - ���� ��� ����� ����� ������ ����� ������; false - ���� ��� ����� ����� ������ ����� ������
*/
bool Edge::operator>(const Edge& edge) {
	return this->weight > edge.weight;
}

/*!
* \param e - �����, �������� �������� ����� ��������� ����������� �������
* \return ������ ������ Edge � ����������� ����������
*/
Edge& Edge::operator=(const Edge& e) {
	parent = e.parent;
	child = e.child;
	weight = e.weight;

	return *this;
}