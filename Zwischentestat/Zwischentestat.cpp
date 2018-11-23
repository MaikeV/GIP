#include <iostream>
#include <string>

int main() {
	std::string input;
	char inputLetter;
	int counter = 0;
	int position = 0;

	std::cout << "Bitte den Text eingeben: ? ";
	std::getline(std::cin, input);
	std::cout << "Bitte den Buchstaben eingeben: ? ";
	std::cin >> inputLetter;

	if (input.length() != 0) {
		for (int index = 0; index <= input.length() - 1; index++) {
			if (input.at(index) == inputLetter) {
				counter++;
				position = index;
			}
		}
	}

	if (counter == 0) {
		std::cout << "Der Buchstabe " << inputLetter << " kommt nicht im Text vor." << std::endl;
	} else {
		std::cout << "Der Buchstabe " << inputLetter << " kommt an der Position " << position << " vor." << std::endl;
	}

	std::system("PAUSE");
	return 0;
}