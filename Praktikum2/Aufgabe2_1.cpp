#include <iostream>

int main() {
	char input;
	int position = 97;

	std::cout << "Bitte einen Buchstaben eingeben: ";
	std::cin >> input;

	int result = int(input) - 'a' + 1;

	std::cout << "Der Buchstabe " << input << " hat die Postition " << result << " im Alphabet." << std::endl;
	std::system("PAUSE");
	
	return 0;
}