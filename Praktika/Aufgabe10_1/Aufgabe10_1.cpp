#include <iostream>
#include <vector>
#include "tree.h"

int main() {
	int input;
	binaryTree::Knot *anker = nullptr;
	
	binaryTree::print(anker);

	do {
		std::cout << "Naechster Wert (99 beendet): ? ";
		std::cin >> input;

		if (input != 99) {
			binaryTree::add(input, anker, nullptr, anker);
		}
		
	} while (input != 99);

	binaryTree::print(anker);

	std::system("PAUSE");
	return 0;
}