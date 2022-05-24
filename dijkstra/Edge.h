#pragma once

/**\brief ����� ��� �������� �����
* ����� ������ ��� ����������� ������ ������� � ��� �����
*/
class Edge {
	char parent;
	char child;
	int weight;
public:
	///�����������
	Edge();
	///����������
	Edge(char, char, int);
	///�����, ������������ ��� �������-��������
	/*!
	* /return ��� �������-��������
	*/
	char get_parent() { return parent; }
	///�����, ������������ ��� �������-�������
	/*!
	* /return ��� �������-�������
	*/
	char get_child() { return child; }
	//*�����, ������������ ��� �����
	/*!
	* /return ��� �����
	*/
	int get_weight() { return weight; }
	///������������� �������� ��� ��������� ����� �����
	bool operator<(const Edge&);
	///������������� �������� ��� ��������� ����� �����
	bool operator>(const Edge&);
	///������������� �������� ��� ������������ �����
	Edge& operator=(const Edge&);
};