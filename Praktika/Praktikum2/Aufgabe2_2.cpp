#include <iostream>

int main() {
	double celsius;

	std::cout << "Bitte geben Sie die Temperatur in Grad Celsius ein: ?";
	std::cin >> celsius;

	double fahrenheit = celsius * 1.8 + 32;

	std::cout << "Die Temperatur in Fahrenheit lautet: " << fahrenheit << std::endl;
	std::system("PAUSE");

	return 0;
}