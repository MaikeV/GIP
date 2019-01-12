#include <iostream>
#include <string>

struct T_Morse_Data {
	char letter;
	std::string morse_code;
};

const T_Morse_Data morse_data[] = {
	{ 'a', ".-" },
	{ 'b', "-..." },
	{ 'c', "-.-." },
	{ 'd', "-.." },
	{ 'e', "." },
	{ 'f', "..-." },
	{ 'g', "--." },
	{ 'h', "...." },
	{ 'i', ".." },
	{ 'j', ".---" },
	{ 'k', "-.-" },
	{ 'l', ".-.." },
	{ 'm', "--" },
	{ 'n', "-." },
	{ 'o', "---" },
	{ 'p', ".--." },
	{ 'q', "--.-" },
	{ 'r', ".-." },
	{ 's', "..." },
	{ 't', "-" },
	{ 'u', "..-" },
	{ 'v', "...-" },
	{ 'w', ".--" },
	{ 'x', "-..-" },
	{ 'y', "-.--" },
	{ 'z', "--.." },
	{ '0', "-----" },
	{ '1', ".----" },
	{ '2', "..---" },
	{ '3', "...--" },
	{ '4', "....-" },
	{ '5', "....." },
	{ '6', "-...." },
	{ '7', "--..." },
	{ '8', "---.." },
	{ '9', "----." },
	// Leerzeichen zur Worttrennung werden im Morsecode
	// durch einen Slash '/' umgeben von Leerzeichen
	// dargestellt ...
	// (Alternative: Trennung durch 3 Leerzeichen)
	// Hier bei uns, um die Testläufe eindeutiger zu
	// machen: Trennung mittels drei Slashes
	{ ' ', "///" },
	{ '.', ".-.-.-" },
	{ ',', "--..--" },
	{ ':', "---..." },
	{ '?', "..--.." },
	{ '-', "-....-" },
	{ '/', "-..-." },
	{ '@', ".--.-." },
	{ '=', "-...-" }
};

const int morse_data_len = 44;

int main() {
	std::string input;

	std::cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
	std::getline(std::cin, input);

	if (!input.empty()) {
		for (int index = 0; index <= input.length() - 1; index++) {
			//std::cout << input.at(index);
			if (input.at(index) >= 'A' && input.at(index) <= 'Z') {
				input.at(index) += 32;
				//std::cout << input.at(index);
			}

			for (int iter = 0; iter <= morse_data_len; iter++) {
				//std::cout << morse_data[iter].letter;
				if (input.at(index) == morse_data[iter].letter) {
					//std::cout << "bla";
					std::cout << morse_data[iter].morse_code << "#";
					break;
				}
			}
		}
	}

	std::cout << std::endl;

	std::system("PAUSE");
	return 0;
}