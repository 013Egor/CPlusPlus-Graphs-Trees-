#include "Header.h"

int main(int argc, char *argv[]) {
	if (argc != 3)
		exit(1);
	topological_sort graph;
	graph.load(argv[1]);
	graph.start();
	graph.save(argv[2]);
	graph.save_origin(argv[2]);

	return 0;
}