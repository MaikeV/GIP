#include <iostream>
#include <string>

int main() {
	std::string input[4] = {"", "", "", ""};
	int index = -1;
	int length = 0;

	do {
		index++;
		std::cout << "Textzeile = ? ";
		std::getline(std::cin, input[index]);
		
	} while (index < 3 && input[index] != "");

	for (int counter = 0; counter <= index; counter++) {
		if (input[counter].length() > length) {
			length = input[counter].length();
		}
	}

	if (length != 0) {
		for (int counter = 0; counter <= index; counter++) {
			if (input[counter] != "") {
				while (input[counter].length() < length) {
					input[counter] = "+" + input[counter];
				}

				std::cout << input[counter] << std::endl;
			}
		}
	}
	
	std::system("PAUSE");
	return 0;
}