#include <iostream>
#include <string>

int main() {
	std::string input;

	std::cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
	std::getline(std::cin, input);

	if (input.length() != 0) {
		for (int index = 0; index <= input.length() - 1; index++) {
			if (input.at(index) >= 'a' && input.at(index) <= 'z') {
				input.insert(index + 1, 1, input.at(index));
				index++;
			} else if (input.at(index) >= 'A' && input.at(index) <= 'Z') {
				input.insert(index + 1, 2, input.at(index));
				index = index + 2;
			} else if (input.at(index) >= '0' && input.at(index) <= '9') {
				input.at(index) = '.';
			} else if (input.at(index) == '?' || input.at(index) == '!') {
				if (input.length() > 1) {
					input.erase(index, 1);
					index--;
				} else {
					input.at(index) = ' ';
				}
			} else if (input.at(index) == ' ') {
				input.at(index) = '_';
			}
		}

		if (input == " ") {
			std::cout << "Der Text nach der Umwandlung:" << input << std::endl;
		} else {
			std::cout << "Der Text nach der Umwandlung: " << input << std::endl;
		}
		
	} else {
		input = " ";
		std::cout << "Der Text nach der Umwandlung:" << input << std::endl;
	}

	std::system("PAUSE");
	return 0;
}