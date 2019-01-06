#include <iostream>
#include <vector>
#include "tree.h"

namespace binaryTree {
	void searchPos(int number, Knot *childKnot, Knot *prev) {
		if (childKnot == nullptr) {
			Knot *knot = new Knot;
			knot->val = number;
			knot->leftChild = 0;
			knot->rightChild = 0;

			if (knot->val < prev->val) {
				prev->leftChild = knot;
			} else {
				prev->rightChild = knot;
			}

			childKnot = knot;
			return;
		} else if (number < childKnot->val) {
			searchPos(number, childKnot->leftChild, childKnot);
		} else if (number > childKnot->val) {
			searchPos(number, childKnot->rightChild, childKnot);
		} else if (number == childKnot->val) {
			return;
		}
	}

	void add(int number, Knot *&anker) {
		Knot *knot = new Knot;
		knot->val = number;
		knot->leftChild = 0;
		knot->rightChild = 0;

		if (anker == nullptr) {
			anker = knot;
		} else if (number < anker->val) {
			searchPos(number, anker->leftChild, anker);
		} else if (number > anker->val) {
			searchPos(number, anker->rightChild, anker);
		}
	}

	void print(Knot *&anker) {
		Knot *ptr = anker;

		printKnot(anker, 0);
	}

	void printKnot(Knot *&knot, int depth) {
		if (knot == nullptr) {
			std::cout << "Leerer Baum." << std::endl;
			return;
		}

		if (knot->rightChild != nullptr) {
			printKnot(knot->rightChild, depth+1);
		}
		for (int index = 0; index < depth; index++) {
			std::cout << "++";
		}

		std::cout << knot->val << std::endl;

		if (knot->leftChild != nullptr) {
			printKnot(knot->leftChild, depth+1);
		}

	}
}
