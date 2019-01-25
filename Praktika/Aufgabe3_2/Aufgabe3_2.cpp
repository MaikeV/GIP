#include <iostream>

int main() {
	int input = 0;
	int	indexH = 0;
	int	indexL = 0;
	int high = 0;
	int low = 0;

	for (int index = 0; index <= 4; index++) {
		std::cout << "Bitte geben Sie die " << index + 1 << ". Zahl ein: ? ";
		std::cin >> input;

		if (index == 0) {
			low = input;
			indexL = index + 1;
			high = input;
			indexH = index + 1;
		}

		if (input > high) {
			high = input;
			indexH = index + 1;
		} else if (input < low) {
			low = input;
			indexL = index + 1;
		}
	}

	std::cout << "Die " << indexL << ". Zahl war die kleinste der eingegebenen Zahlen und lautet: " << low << std::endl;
	std::cout << "Die " << indexH << ". Zahl war die groesste der eingegebenen Zahlen und lautet: " << high << std::endl;

	std::system("PAUSE");

	return 0;
}