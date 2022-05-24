# Articulation point

Articulation point is a C++ programm. This programm finds articulation points in graph.

## Installation

Compile .cpp and .h files from command line or IDE.

## Usage

You need to make .txt file with graph and from command line run programm with .txt file as an argument.

# How to make .txt file 

Graph consist of integers.

1) First value is amount of graph`s points
2) Next values is parent-point and child-points 

Example of .txt file:
5  

1
1

2
0 2

2
1 3

2
2 4

1
3

# How to run executable file from command line

Example(you may have different name of executable file):
./articulation_point test_graph_2.txt final.dot

--first argument - executable file
--second argument - input file (.txt) with graph
--third ardument - output file (.dot) with graph with highlighted points

# If you want to convert .dot file into picture, you should install Graphviz and convert .dot file
