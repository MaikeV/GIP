#include <iostream>

int main() {
	double input = 0.0;
	int sel = 1;

	std::cout << "Ihre Eingabe: ? ";
	std::cin >> input;
	std::cout << "Ihre Auswahl der Umwandlung: " << std::endl << "1 - Celsius in Fahrenheit\n2 - Meter in Fuss\n3 - Euro in US Dollar" << std::endl;
	std::cin >> sel;

	//1
	double fahrenheit = input * 1.8 + 32;
	int faktor1 = 1 - (1 % sel);
	std::cout << "1: " << faktor1 << std::endl;

	//2
	double fuss = input * 3.2808;
	int faktor2 = ((sel +1) % 2);
	std::cout << "2: " << faktor2 << std::endl;

	//3
	double dollar = input * 1.2957;
	int faktor3 = ((1 - ((sel - 1) % 3)) * (-1) + 1) / 2;
	std::cout << "3: " << faktor3 << std::endl;

	double output = faktor1 * fahrenheit + faktor2 * fuss + faktor3 * dollar;

	std::cout << output << std::endl;

	std::system("PAUSE");

	return 0;
}