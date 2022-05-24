#include "priority_queue.h"
#include <fstream>
#include <iostream>
using namespace std;

/*!
* \param i ������, � �������� ���������� �������������� �������� 
*/
void PriorityQueue::low_heapify(int i) {
	if (i >= size)
		return;

	int l, r;
	int lowest = i;
	l = left(i);
	r = right(i);
	if (l < size && queue[l] < queue[i])
		lowest = l;
	if (r < size && queue[r] < queue[lowest])
		lowest = r;

	if (lowest != i) {
		swap(lowest, i);
		low_heapify(lowest);
	}
}

/*!
* \param i, j ������� ���������, ������� ���� �������� �������
*/
void PriorityQueue::swap(int i, int j) {
	if (i >= size || j >= size)
		return;
	Edge temp = queue[i];
	queue[i] = queue[j];
	queue[j] = temp;
}

void PriorityQueue::build_queue() {
	for (int i = size / 2;i >= 0; i--)
		low_heapify(i);
}

/*!
* \param v �����, ���������� � �������
*/
void PriorityQueue::insert(const Edge& v) {
	if (size >= capacity)
		return;
	queue[size++] = v;

	int i = size - 1;
	while (queue[parent(i)] > queue[i]) {
		swap(parent(i), i);
		i = parent(i);
	}
}

/*!
* \return ����������� ������� � �������
*/
Edge PriorityQueue::pop() {
	Edge min;
	min = queue[0];
	queue[0] = queue[size - 1];
	size--;
	low_heapify(0);

	return min;
}

PriorityQueue::PriorityQueue() {
	size = 0;
	capacity = 0;
	t = 0;
}

PriorityQueue::~PriorityQueue() {
	size = capacity = 0;
	delete[]queue;
}


/*!
* \return ���������� ��������� � �������
*/
void PriorityQueue::set_size(int s) {
	capacity = s;
	size = 0;
	queue = new Edge[s];
}

void PriorityQueue::s() {
	for (int i = 0; i < size;i++)
		cout << queue[i].get_parent() << '-' << queue[i].get_child() << ':' << queue[i].get_weight() << " ; ";
	cout << endl;
}