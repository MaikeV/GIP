#include <iostream>

int main() {
	int highest = 100;
	int lowest = 1;
	int middle;
	bool isSolved = false;
	char input;

	std::cout << "Merken Sie sich eine Zahl zwischen 1 (inklusive) und 100 (exklusive)" << std::endl;

	while (!isSolved) {
		middle = (lowest + highest) / 2;
		std::cout << "Aktueller Ratebereich: " << lowest << " bis " << highest << std::endl;
		std::cout << "Ist " << middle << " Ihre Zahl?" << std::endl;
		std::cout << "(j) ja, gleich," << std::endl << "(k) nein: meine Zahl ist kleiner," << std::endl << "(g) nein: meine Zahl ist groesser" << std::endl;
		std::cin >> input;

		if (input == 'j') {
			isSolved = true;
		} else if (input == 'k') {
			highest = middle;
		} else if (input == 'g') {
			lowest = middle;
		}
	}

	std::system("PAUSE");
	return 0;
}