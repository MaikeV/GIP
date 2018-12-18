#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <string>
#include "suchen.h"
#include "catch.h"

int main() {
	if (Catch::Session().run()) {
		system("PAUSE");
		return 1;
	}

	const int length = 20;
	char* text = new char[20];
	char* subtext = new char[20];
	int returnCode = -1;
	int subLength = 0;

	std::cout << "Bitte geben Sie den Text ein: ";
	std::cin.getline(text, length);

	while (subLength == 0) {
		std::cout << "Bitte geben Sie die zu suchende Zeichenkette ein: ";
		std::cin.getline(subtext, length);
		subLength = getLength(subtext);
	}

	returnCode = suchen(text, subtext);

	if (returnCode == -1) {
		std::cout << "Die Zeichenkette '" << subtext << "' ist NICHT in dem Text '" << text << "' enthalten." << std::endl;
	} else {
		std::cout << "Die Zeichenkette '" << subtext << "' ist in dem Text '" << text << "' enthalten." << std::endl << 
			"Sie startet ab Zeichen " << returnCode << " (bei Zaehlung ab 0)." << std::endl;	
	}

	std::system("PAUSE");
	return returnCode;
}