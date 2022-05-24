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

bool Edge::operator<(const Edge& edge) {
	return this->weight < edge.weight;
}

bool Edge::operator>(const Edge& edge) {
	return this->weight > edge.weight;
}

bool Edge::operator==(const Edge& edge) {
	return parent == edge.parent && child == edge.child || parent == edge.child && child == edge.parent;
}

Edge& Edge::operator=(const Edge& e) {
	parent = e.parent;
	child = e.child;
	weight = e.weight;

	return *this;
}