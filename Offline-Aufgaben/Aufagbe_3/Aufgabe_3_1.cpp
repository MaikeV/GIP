#include <iostream>

int main() {
	int input = 0;
	int high = 0;
	int low = 0;

	for (int index = 0; index <= 2; index++) {
		std::cout << "Bitte geben Sie die " << index + 1 << ". Zahl ein: ? ";
		std::cin >> input;

		if (index == 0) {
			high = input;
			low = input;
		}

		if (input > high) {
			high = input;
		}
		else if (input < low) {
			low = input;
		}
	}

	std::cout << "Die kleinste eingegebene Zahl lautet: " << low << std::endl;
	std::cout << "Die groesste eingegebene Zahl lautet: " << high << std::endl;

	std::system("PAUSE");
	
	return 0;
}