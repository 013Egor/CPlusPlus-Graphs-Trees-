#pragma once

class Node {
	Node* parent;
	Node* left;
	Node* right;
	int key;
	int position;
	bool color;
public:

	Node() { parent = left = right = 0; key = 0; }
	Node* get_parent() { return parent; }
	Node* get_left() { return left; }
	Node* get_right() { return right; }
	int get_key() { return key; }
	void set_left(Node* l) { left = l; }
	void set_right(Node* r) { right = r; }
	void set_key(int k) { key = k; }
	void set_parent(Node* p) { parent = p; }
	void set_red() { color = true; }
	void set_black() { color = false; }
	bool get_color() { return color; }
	bool get_parents_color() {
		if (parent)
			return parent->color;
		else 
			return 0;
	}
	Node* get_parents_left() {
		if (parent)
			return parent->left;
		else
			return 0;
	}
	Node* get_parents_right() {
		if (parent)
			return parent->right;
		else
			return 0;
	}
	void set_position(int pos) { position = pos; };
	int get_position() { return position; }
};