#include <iostream>

int main() {
	int width = 2;
	int height = 2;
	std::cout << "Bitte geben Sie die Breite des Parallelogramms ein: ? ";
	std::cin >> width;
	std::cout << "Bitte geben Sie die Hoehe des Parallelogramms ein: ? ";
	std::cin >> height;

	for (int indexH = 0; indexH <= height - 1; indexH++) {
		for (int indexW = 0; indexW <= width - 1; indexW++) {
			if (indexH > 0 && indexW == 0) {
				for (int indexD = 1; indexD <= indexH; indexD++) {
					std::cout << ".";
				}
			}
			
			if (indexH == 0 || indexH == height - 1) {
				std::cout << "*";
			} else if (indexW == 0 || indexW == width - 1) {
				std::cout << "*";
			} else {
				std::cout << "+";
			}

			if (indexW == width - 1) {
				std::cout << std::endl;
			}
		}
	}
	std::cout << std::endl;	
	std::system("PAUSE");
	return 0;
}