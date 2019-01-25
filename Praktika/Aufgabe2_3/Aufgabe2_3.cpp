#include <iostream>

int main() {
	double meter;
	
	std::cout << "Bitte geben Sie die Laenge in Metern ein: ? ";
	std::cin >> meter;

	double fuss = meter * 3.2808;

	std::cout << "Die Laenge in Fuss lautet: " << fuss << std::endl;

	std::system("PAUSE");

	return 0;
}