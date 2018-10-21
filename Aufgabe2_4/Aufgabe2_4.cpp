#include <iostream>

int main() {
	double euro;

	std::cout << "Bitte geben Sie die Geldmenge in Euro ein: ?";
	std::cin >> euro;

	double dollar = euro * 1.2957;

	std::cout << "Die Geldmenge in US Dollar lautet: " << dollar << std::endl;

	std::system("PAUSE");

	return 0;
}