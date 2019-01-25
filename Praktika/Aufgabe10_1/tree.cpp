#include <iostream>
#include <vector>
#include "tree.h"

namespace binaryTree {
	void add(int number, Knot *childKnot, Knot *prev, Knot *&anker) {
		if (childKnot == nullptr) {
			Knot *knot = new Knot;
			knot->val = number;
			knot->leftChild = 0;
			knot->rightChild = 0;

			if (prev == nullptr) {
				anker = knot;
			} else {
				if (knot->val < prev->val) {
					prev->leftChild = knot;
				} else {
					prev->rightChild = knot;
				}
			}

			childKnot = knot;
			return;
		} else if (number < childKnot->val) {
			add(number, childKnot->leftChild, childKnot, anker);
		} else if (number > childKnot->val) {
			add(number, childKnot->rightChild, childKnot, anker);
		} else if (number == childKnot->val) {
			return;
		}
	}

	void print(Knot *&anker) {
		if (anker == nullptr) {
			std::cout << "Leerer Baum." << std::endl;
			return;
		}
		printKnot(anker, 0);
	}

	void printKnot(Knot *&knot, int depth) {
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
