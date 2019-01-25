#include <iostream>

int main() {
	int input = 0;
	int inpArr[5];

	for (int index = 1; index <= 5; index++) {
		do {
			std::cout << "Bitte geben Sie die " << index << ". Zahl ein: ? ";
			std::cin >> input;
		} while (input < 1 || input > 9);

		inpArr[index - 1] = input;
	}

	for (int index = 9; index >= 1; index--) { // Zeilen
		std::cout << index;
		for (int innerIndex = 0; innerIndex <= 4; innerIndex++) { // Spalten
			if (inpArr[innerIndex] == index) {
				std::cout << "*";
			} else if (inpArr[innerIndex] < index) {
				std::cout << ".";
			} else if (inpArr[innerIndex] > index) {
				std::cout << "+";
			} else {
				std::cout << std::endl;
			}

			
		}
		std::cout << std::endl;

		if (index == 1) {
			std::cout << " ";
			for (int counter = 1; counter <= 5; counter++) {
				std::cout << counter;
			}

			std::cout << std::endl;
		}
	}


	std::system("PAUSE");
	return 0;
}