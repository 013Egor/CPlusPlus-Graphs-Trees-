#include "ArticulationPoint.h"

int main(int argc, char *argv[]) {
    if (argc != 3)
        exit(1);

    ArticulationPoint graph;

    graph.load(argv[1]);
    graph.dfs(0, -1);
    graph.save_dot(argv[2]);

    return 0;
}
