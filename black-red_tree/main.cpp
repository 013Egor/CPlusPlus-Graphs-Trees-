#include "BlackRedTree.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3)
		exit(1);

	Tree a;
	int to_find;

	a.load(argv[1]);

	cout << "Enter number to find: ";
	cin >> to_find;
	if (a.find(to_find))
		cout << "Number " << to_find << " is exists\n";
	else
		cout << "Cant find number\n";

	a.save(argv[2]);
	return 0;
}