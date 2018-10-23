#include <iostream>

int main() {
	double length = 0.0;

	std::cout << "Bitte geben Sie die Seitenlaenge ein (in cm): ? ";
	std::cin >> length;

	double scope = length * 4;

	std::cout << "Der Umfang des Quadrats betraegt (in cm): " << scope << std::endl;

	double area = length * length;

	std::cout << "Die Flaeche des Quadrats betraegt (in cm*cm): " << area << std::endl;
	std::system("PAUSE");

	return 0;
}