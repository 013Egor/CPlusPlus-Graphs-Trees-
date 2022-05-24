#include "BlackRedTree.h"
#include "Node.h"

using namespace std;

bool Tree::load(const string& filename) {

	ifstream fin(filename);
	if (!fin)
		return false;

	int tempNum;
	int pos = 0;

	while (!fin.eof()) {
		fin >> tempNum;
		insert(tempNum, pos++);
	}

	return true;
}

bool Tree::save(const std::string& filename) {
	ofstream fout(filename);
	if (!fout)
		return false;

	makeGraph(root);
	multimap<int, int>::iterator iterator_for_graph = graph.begin();
	map<int, bool>::iterator iterator_for_colors = colors.begin();
	set<int>::iterator iterator_for_last_nodes = last.begin();

	fout << "digraph G{\n";
	makeLabel(root, fout);
	while (iterator_for_colors != colors.end()) {
		fout << iterator_for_colors->first << "[fontcolor=white,style=filled, color=";
		if (iterator_for_colors->second)
			fout << "red];\n";
		else
			fout << "black];\n";
		iterator_for_colors++;
	}

	fout << "ROOT -> " << root->get_position() << "[style=dotted];\n";
	while (iterator_for_graph != graph.end()) {
		fout << iterator_for_graph->first << " -> " << iterator_for_graph->second  << ";\n";
		iterator_for_graph++;
	}


	while (iterator_for_last_nodes != last.end()) {
		fout << *iterator_for_last_nodes << " -> " << "NIL;\n";
		iterator_for_last_nodes++;
	}
	fout << "NIL[fontcolor=white,style=filled, color=black];\n";
	fout << "ROOT[fontcolor=black,style=filled, color=green];\n";
	fout << '}';
}

bool Tree::find(int num) {
	Node* cur = root;
	while (cur != NULL) {
		if (num == cur->get_key())
			return true;
		else if (cur->get_key() > num)
			cur = cur->get_left();
		else
			cur = cur->get_right();
	}
	return false;
}

void Tree::insert(int num, int pos) {
	Node* new_num = new Node;
	Node* parent_of_new_number = NULL, *temp = root;
	new_num->set_key(num);
	new_num->set_position(pos);

	while (temp) {
		parent_of_new_number = temp;
		if (num < temp->get_key())
			temp = temp->get_left();
		else
			temp = temp->get_right();
	}

	new_num->set_parent(parent_of_new_number);

	if (parent_of_new_number == NULL)
		root = new_num;
	else
		if (num < parent_of_new_number->get_key())
			parent_of_new_number->set_left(new_num);
		else
			parent_of_new_number->set_right(new_num);

	new_num->set_left(NULL);
	new_num->set_right(NULL);
	new_num->set_red();
	colorFix(new_num);
}

void Tree::leftRotate(Node* turn_point) {
	if (turn_point == NULL || turn_point->get_right() == NULL)
		return;
	Node* changer = turn_point->get_right();
	Node* temp;

	turn_point->set_right(changer->get_left());

	if (changer->get_left()) {
		temp = changer->get_left();
		temp->set_parent(turn_point);
	}

	changer->set_parent(turn_point->get_parent());
	if (turn_point->get_parent() == NULL)
		root = changer;
	else {
		temp = turn_point->get_parent();
		if (turn_point == temp->get_left())
			temp->set_left(changer);
		else
			temp->set_right(changer);
	}

	changer->set_left(turn_point);
	turn_point->set_parent(changer);
}

void Tree::rightRotate(Node* turn_point) {
	if (turn_point == NULL || turn_point->get_left() == NULL)
		return;
	Node* changer = turn_point->get_left();
	Node* temp;

	turn_point->set_left(changer->get_right());

	if (changer && changer->get_right()) {
		temp = changer->get_right();
		temp->set_parent(turn_point);
	}

	changer->set_parent(turn_point->get_parent());
	if (turn_point->get_parent() == NULL)
		root = changer;
	else {
		temp = turn_point->get_parent();
		if (turn_point == temp->get_right())
			temp->set_right(changer);
		else
			temp->set_left(changer);
	}

	changer->set_right(turn_point);
	turn_point->set_parent(changer);
}

void Tree::colorFix(Node* node_to_check) {
	Node* node_to_check_parent = node_to_check->get_parent();
	Node* sibling;
	while (node_to_check && node_to_check->get_parents_color()) {
		if (node_to_check_parent && node_to_check_parent == node_to_check_parent->get_parents_left()) {
			sibling = node_to_check_parent->get_parents_right();

			if (sibling && sibling->get_color()) {
				node_to_check_parent->set_black();
				sibling->set_black();
				node_to_check_parent = node_to_check_parent->get_parent();
				if (node_to_check_parent)
					node_to_check_parent->set_red();
				node_to_check = node_to_check_parent;
			}
			else {
				if (node_to_check == node_to_check_parent->get_right()) {
					node_to_check = node_to_check_parent;
					node_to_check_parent = node_to_check->get_parent();
					leftRotate(node_to_check);
				}
				node_to_check_parent->set_black();
				node_to_check_parent = node_to_check_parent->get_parent();
				if (node_to_check_parent)
					node_to_check_parent->set_red();
				rightRotate(node_to_check_parent);
			}
		}
		else {
			sibling = node_to_check_parent->get_parents_left();
			if (sibling && sibling->get_color()) {
				node_to_check_parent->set_black();
				sibling->set_black();
				node_to_check_parent = node_to_check_parent->get_parent();
				if (node_to_check_parent)
					node_to_check_parent->set_red();
				node_to_check = node_to_check_parent;
			}
			else {
				if (node_to_check == node_to_check_parent->get_left()) {
					node_to_check = node_to_check_parent;
					node_to_check_parent = node_to_check->get_parent();
					rightRotate(node_to_check);
				}
				node_to_check_parent->set_black();
				node_to_check_parent = node_to_check_parent->get_parent();
				if (node_to_check_parent)
					node_to_check_parent->set_red();
				leftRotate(node_to_check_parent);
			}
		}
		if (node_to_check)
			node_to_check_parent = node_to_check->get_parent();
	}
	root->set_black();
}

void Tree::deleteTree(Node* cur) {
	Node* right = cur->get_right();
	Node* left = cur->get_left();

	if (right)
		deleteTree(right);
	if (left)
		deleteTree(left);
	if (cur)
		delete cur;
}

void Tree::makeGraph(Node* cur) {
	Node* right = cur->get_right();
	Node* left = cur->get_left();
	colors.insert(pair<int, bool>(cur->get_position(), cur->get_color()));

	if (cur->get_right())
		makeGraph(right);
	else
		last.insert(cur->get_position());

	if (cur->get_left())
		makeGraph(left);
	else
		last.insert(cur->get_position());

	if (cur->get_parent())
		graph.insert(pair<int, int>(cur->get_parent()->get_position(), cur->get_position()));
}

//Need to change this
void Tree::makeLabel(Node* cur, ofstream& fout) {
	Node* right = cur->get_right();
	Node* left = cur->get_left();
	fout << cur->get_position() << " [label=" << cur->get_key() << "];\n";

	if (cur->get_right())
		makeLabel(right, fout);

	if (cur->get_left())
		makeLabel(left, fout);
}
