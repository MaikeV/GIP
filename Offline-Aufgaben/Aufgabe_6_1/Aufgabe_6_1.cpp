#include <iostream>
#include <string>

void spalte_ab_erstem(char zeichen, std::string eingabe, std::string& erster_teil, std::string& zweiter_teil) {
	int cut;
	bool contains = false;

	for (int index = 0; index <= eingabe.length() - 1; index++) {
		if (zeichen == eingabe[index]) {
			cut = index;
			contains = true;
			break;
		}
	}

	if (contains) {
		for (int index = 0; index < cut; index++) {
			erster_teil += eingabe[index];
		}

		for (int index = cut + 1; index <= eingabe.length() - 1; index++) {
			zweiter_teil += eingabe[index];
		}
	} else {
		erster_teil = eingabe;
	}
}

int main() {
	char character;
	std::string input, firstPart, secondPart;

	std::cout << "Bitte geben Sie die einzeilige Zeichenkette ein: ? ";
	std::getline(std::cin, input);
	std::cout << "Bitte geben Sie das Zeichen ein: ? ";
	std::cin >> character;

	spalte_ab_erstem(character, input, firstPart, secondPart);

	std::cout << "Der erste Teil der Zeichenkette lautet: " << firstPart << std::endl;
	std::cout << "Der zweite Teil der Zeichenkette lautet: " << secondPart << std::endl; // Leerzeichen ueberpruefen!

	std::system("PAUSE");
	return 0;
}