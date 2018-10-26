#include <iostream>

int main() {
	char num1;
	char num2;
	int ret = 0;
	int Inum1, Inum2;

	std::cout << "Bitte geben Sie die erste Ziffer ein: ? ";
	std::cin >> num1;
	std::cout << "Bitte geben Sie die zweite Ziffer ein: ? ";
	std::cin >> num2;

	if (num1 == 'q' || num2 == 'q') {
		std::cout << "Das Programm wurde durch Eingabe von q beendet." << std::endl;
		ret = 1;
	} else {
		Inum1 = num1 - '0';
		Inum2 = num2 - '0';
		std::cout << Inum1 << " + " << Inum2 << " = " << Inum1 + Inum2 << std::endl;
	}

	std::system("PAUSE");

	return ret;
}