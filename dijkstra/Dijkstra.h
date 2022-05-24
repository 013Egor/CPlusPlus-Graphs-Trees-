#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Edge.h"
#include "priority_queue.h"

/*!\brief �������� �������� �� O(Elog(V)) ��������
* ����� ��� ���������� �������� �������� ��������� ��������.
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
	///��������� ���� �� �����
	void load(const std::string&);
	///��������� �������� ����
	void save_graph(const std::string&);
	///��������� ���� ����� ���������� ��������� ��������
	void save(const std::string&);
	///����� ��� �������� ������� � �����������
	void make_queue();
	///����� ��� ���������� ��������� ��������
	/*!
	* �� ���������� ����� ������ ������ ���� �������� ������ ���������.
	*/
	void start();
	///����� ��� ���������� ��������� �����
	void relax(Edge&);
	///�����, ����������� ������������� ���� �� ������� � � ������� �
	bool path_exist();
};