#include <iostream>

int main() {
	int day1, day2, month1, month2, year1, year2 = 0;

	std::cout << "Bitte geben Sie den Tag des ersten Datums ein: ";
	std::cin >> day1;
	std::cout << "Bitte geben Sie den Monat des ersten Datums ein: ";
	std::cin >> month1;
	std::cout << "Bitte geben Sie das Jahr des ersten Datums ein: ";
	std::cin >> year1;

	std::cout << "Bitte geben Sie den Tag des zweiten Datums ein: ";
	std::cin >> day2;
	std::cout << "Bitte geben Sie den Monat des zweiten Datums ein: ";
	std::cin >> month2;
	std::cout << "Bitte geben Sie das Jahr des zweiten Datums ein: ";
	std::cin >> year2;

	if (year1 > year2) {
		std::cout << "Das zweite Datum liegt vor dem ersten Datum.";
	} else if (year1 < year2) {
		std::cout << "Das erste Datum liegt vor dem zweiten Datum.";
	} else {
		if (month1 > month2) {
			std::cout << "Das zweite Datum liegt vor dem ersten Datum.";
		} else if (month1 < month2) {
			std::cout << "Das erste Datum liegt vor dem zweiten Datum.";
		} else {
			if (day1 > day2) {
				std::cout << "Das zweite Datum liegt vor dem ersten Datum.";
			} else if (day1 < day2) {
				std::cout << "Das erste Datum liegt vor dem zweiten Datum.";
			} else {
				std::cout << "Beide Datumsangaben sind gleich.";
			}
		}
	}
	std::cout << std::endl;

	std::system("PAUSE");

	return 0;
}