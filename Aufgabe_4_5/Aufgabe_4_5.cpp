#include <iostream>
#include <string>

int main() {
	std::string input;
	bool isPalindrom = true;
	bool containsIllegalChar = false;

	do {
		std::cout << "Text: ? ";
		std::getline(std::cin, input);

		for (int index = 0; index <= input.length() - 1; index++) {
			if (input.at(index) < 'a' || input.at(index) > 'z') {
				containsIllegalChar = true;
				break;
			} else {
				containsIllegalChar = false;
			}
		}
	} while (containsIllegalChar);

	for (int index = 0; index <= input.length() - 1; index++) {
		if (!(input.at(index) == input.at((input.length() - 1) - index))) {
			isPalindrom = false;
			break;
		}
	}

	if (isPalindrom) {
		std::cout << "Das eingegebene Wort ist ein Palindrom." << std::endl;
	} else {
		std::cout << "Das eingegebene Wort ist KEIN Palindrom." << std::endl;
	}

	std::system("PAUSE");
	return 0;
}