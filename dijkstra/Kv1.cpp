/**
*Алгоритм Дейкстра За O(Elog(V)) Операций
*
*Реализовать быстрый вариант алгоритма Дейкстра. Выходной файл должен быть в формате graphviz.
*/

#include "Dijkstra.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	Dijkstra t;
	if (argc != 3)
		exit(1);
	t.load(argv[1]);
	t.start();
	t.save(argv[2]);
	t.save_graph("graph.dot");

	return 0; 
}