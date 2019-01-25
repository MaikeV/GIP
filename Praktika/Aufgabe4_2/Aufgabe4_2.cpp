#include <iostream>
#include <string>

int main() {
	std::string input;
	int shift;

	std::cout << "Bitte geben Sie den zu verschluesselnden Text ein: ";
	std::getline(std::cin, input);
	std::cout << "Bitte geben Sie die Anzahl Verschiebepositionen ein (als positive ganze Zahl): ";
	std::cin >> shift;

	int rounds = shift % 26;

	for (int index = 0; index <= input.length() - 1; index++) {
		if ((input.at(index) < 'A' || input.at(index) > 'z') || (input.at(index) > 'Z' && input.at(index) < 'a')) {
			//input.at(index) = input.at(index);
		} else if ((input.at(index) + shift) > 'Z' && input.at(index) <= 'Z') {
			input.at(index) = (input.at(index) + rounds);

			if (input.at(index) > 'Z') {
				input.at(index) -= 26;
			}
		} else if ((input.at(index) + shift) > 'z' && input.at(index) <= 'z') {
			input.at(index) = (input.at(index) + rounds);

			if (input.at(index) > 'z') {
				input.at(index) -= 26;
			}
		} else {
			input.at(index) += shift;
		}
	}

	std::cout << input << std::endl;
	std::system("PAUSE");

	return 0;
}