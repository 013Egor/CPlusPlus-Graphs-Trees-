#pragma once
#include <vector>
#include <string>
#include <fstream>

class ArticulationPoint {

	std::vector<std::vector<int>> graph;
	std::vector<int> vertex;
	std::vector<bool> visited;
	std::vector<int> dfnumber, low;
	int timer;

public:
	ArticulationPoint() { timer = 0; }
	bool save_dot(const std::string& filename);
	bool load(const std::string& filename);
	void dfs(int curent_vertex, int parent);
};
