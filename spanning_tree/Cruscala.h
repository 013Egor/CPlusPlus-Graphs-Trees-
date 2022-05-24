#pragma once
#include <string>
#include <vector>
#include <set>
#include "Edge.h"

class Cruscala {
	std::vector<Edge> edges; //������ ��� ����� ���������� �����
	std::vector<Edge> final_tree; //����� ��������� �����(�������� ������)
	std::set<char> vertex; //��������� ��� �������� ������
	std::vector<std::vector<char>> con_vert; //�� ���� ��� �������, �� ��� ����� ��� ��������� ��������� ������, ����� �������� ������ � �����
public:
	void load(const std::string&);
	void save(const std::string&);
	void save_origin_graph(const std::string&);
	void start();//������ ���������
	bool is_connected(char, char);//��������������� ������� ��� ���������, ��� �������� �� ������������� ������
};