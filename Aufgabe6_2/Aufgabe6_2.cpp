#include <iostream>
#include <string>
#include "Wortspiegel.h"

int main() {
	std::string text;
	char input = 'a';
	bool finished = false;
	unsigned int pos = 0;

	std::cout << "Bitte geben Sie den Text ein: ? ";
	std::getline(std::cin, text);

	while (!finished) {
		for (int index = 0; index <= text.length() - 1; index++) {
			std::cout << text << std::endl;
			for (int counter = 0; counter <= pos; counter++) {
				if (counter == pos) {
					std::cout << "*" << std::endl;
				} else {
					std::cout << " ";
				}
			}

			std::cout << "Befehl (l: links, r: rechts, s: spiegeln, q: Ende) ?- ";
			std::cin >> input;

			if (input == 'l' && pos != 0) {
				pos--;
			} else if (input == 'r' && pos < (text.length() - 1)) {
				pos++;
			} else if (input == 's' && text.at(pos) != '.' && text.at(pos) != ' ') {
				wortspiegel(text, pos);
			} else if (input == 'q') {
				finished = true;
				break;
			} else {
				std::cout << std::endl;
			}
		}
	}

	std::system("PAUSE");
	return 0;
}