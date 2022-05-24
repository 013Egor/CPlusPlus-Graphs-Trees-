#include "Cruscala.h"

int main(int argc, char* argv[]) {
	Cruscala graph;
	if (argc != 3)
		exit(1);
	graph.load(argv[1]);
	graph.start();
	graph.save(argv[2]);
	graph.save_origin_graph(argv[2]);

	return 0;
}
