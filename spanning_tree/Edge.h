#pragma once

class Edge {
	char parent;
	char child;
	int weight;
public:
	Edge();
	Edge(char, char, int);
	char get_parent() { return parent; }
	char get_child() { return child; }
	int get_weight() { return weight; }
	bool operator<(const Edge&);
	bool operator>(const Edge&);
	bool operator==(const Edge&);
	Edge& operator=(const Edge&);
};