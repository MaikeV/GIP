#pragma once

namespace binaryTree {
	struct Knot {
		Knot *parent;
		int val;
		Knot *leftChild;
		Knot *rightChild;
	};

	void add(int number, Knot *childKnot, Knot *prev, Knot *&anker);
	//void add(int number, Knot *&anker);
	void print(Knot *&anker);
	void printKnot(Knot *&knot, int depth);
}
