#include <iostream>

int main() {
	int hour = 0;
	int minute = 0;
	int interval = 0;
	
	do {
		std::cout << "Bitte geben Sie die Stunden der Startuhrzeit ein: ";
		std::cin >> hour;
	} while (hour < 0 || hour > 23);

	do {
		std::cout << "Bitte geben Sie die Minuten der Startuhrzeit ein: ";
		std::cin >> minute;
	} while (minute < 0 || minute > 59);

	std::cout << "Der erste Bus faehrt also um " << hour << ":" << minute << " Uhr" << std::endl;

	do {
		std::cout << "Bitte geben Sie die Taktzeit in Minuten ein: ";
		std::cin >> interval;
	} while (interval < 0 || interval > 180);

	std::cout << hour << ":" << minute << " ";

	while (hour <= 23) {
		if (minute + interval > 59) {
			minute += interval;

			while (minute > 59 && hour <= 23) {
				minute -= 60;
				hour++;
			}
			std::cout << std::endl;
		} else {
			minute += interval;
		}

		if (hour < 24) {
			std::cout << hour << ":" << minute << " ";
		}
	}

	std::system("PAUSE");
	return 0;
}