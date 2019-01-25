#include <iostream>
#include <string>

struct Person {
	std::string nachname, vorname;
	int alter;
	char geschlecht;
};

char askForPerson() {
	char option;

	do {
		std::cout << "Eine weitere Person eingeben (j/n)? ";
		std::cin >> option;
	} while (option != 'j' && option != 'n');

	return option;
}

void filter(Person personen[100], int anzahl_personen) {
	int option;
	int filterCounter = 0;
	std::cout << "Ihre Auswahl:" << std::endl << "1 - Weibliche Erwachsene" << std::endl << "2 - Maennliche Erwachsene" << std::endl <<
		"3 - Weibliche Kinder" << std::endl << "4 - Maennliche Kinder" << std::endl << "? ";
	std::cin >> option;

	switch (option) {
	case 1:
		for (int index = 0; index <= anzahl_personen - 1; index++) {
			if (personen[index].alter >= 18 && personen[index].geschlecht == 'w') {
				std::cout << personen[index].nachname << ", " << personen[index].vorname << ", "
					<< personen[index].geschlecht << ", " << personen[index].alter << std::endl;
				filterCounter++;
			}
		}
		std::cout << "Summe: " << filterCounter << std::endl;
		break;
	case 2:
		for (int index = 0; index <= anzahl_personen - 1; index++) {
			if (personen[index].alter >= 18 && personen[index].geschlecht == 'm') {
				std::cout << personen[index].nachname << ", " << personen[index].vorname << ", "
					<< personen[index].geschlecht << ", " << personen[index].alter << std::endl;
				filterCounter++;
			}
		}
		std::cout << "Summe: " << filterCounter << std::endl;
		break;
	case 3:
		for (int index = 0; index <= anzahl_personen - 1; index++) {
			if (personen[index].alter < 18 && personen[index].geschlecht == 'w') {
				std::cout << personen[index].nachname << ", " << personen[index].vorname << ", "
					<< personen[index].geschlecht << ", " << personen[index].alter << std::endl;
				filterCounter++;
			}
		}
		std::cout << "Summe: " << filterCounter << std::endl;
		break;
	case 4:
		for (int index = 0; index <= anzahl_personen - 1; index++) {
			if (personen[index].alter < 18 && personen[index].geschlecht == 'm') {
				std::cout << personen[index].nachname << ", " << personen[index].vorname << ", "
					<< personen[index].geschlecht << ", " << personen[index].alter << std::endl;
				filterCounter++;
			}
		}
		std::cout << "Summe: " << filterCounter << std::endl;
		break;
	}
}

int main() {
	Person personen[100] = {
		{ "Musterfrau1", "Petra1", 18, 'w' },
		{ "Mustermann1", "Klaus1", 18, 'm' },
		{ "Mustermaedchen1", "Lisa1", 1, 'w' },
		{ "Musterjunge1", "Jan1", 1, 'm' },
		{ "Musterfrau2", "Petra2", 19, 'w' },
		{ "Mustermann2", "Klaus2", 19, 'm' },
		{ "Mustermaedchen2", "Lisa2", 2, 'w' },
		{ "Musterjunge2", "Jan2", 2, 'm' },
		{ "Musterfrau3", "Petra3", 20, 'w' },
		{ "Mustermann3", "Klaus3", 20, 'm' },
		{ "Mustermaedchen3", "Lisa3", 3, 'w' },
		{ "Musterjunge3", "Jan3", 3, 'm' },
		{ "Musterfrau4", "Petra4", 21, 'w' },
		{ "Mustermann4", "Klaus4", 21, 'm' },
		{ "Mustermaedchen4", "Lisa4", 4, 'w' },
		{ "Musterjunge4", "Jan4", 4, 'm' },
		{ "Musterfrau5", "Petra5", 22, 'w' },
		{ "Mustermann5", "Klaus5", 22, 'm' },
		{ "Mustermaedchen5", "Lisa5", 5, 'w' },
		{ "Musterjunge5", "Jan5", 5, 'm' },
		{ "Musterfrau6", "Petra6", 23, 'w' },
		{ "Mustermann6", "Klaus6", 23, 'm' },
		{ "Mustermaedchen6", "Lisa6", 6, 'w' },
		{ "Musterjunge6", "Jan6", 6, 'm' },
		{ "Musterfrau7", "Petra7", 24, 'w' },
		{ "Mustermann7", "Klaus7", 24, 'm' },
		{ "Mustermaedchen7", "Lisa7", 7, 'w' },
		{ "Musterjunge7", "Jan7", 7, 'm' },
		{ "Musterfrau8", "Petra8", 25, 'w' },
		{ "Mustermann8", "Klaus8", 25, 'm' },
		{ "Mustermaedchen8", "Lisa8", 8, 'w' },
		{ "Musterjunge8", "Jan8", 8, 'm' }
	};
	int anzahl_personen = 32;
	char option, sex;
	int age;
	std::string lastName, firstName;
	Person person;
	bool looping = true;
	
	option = askForPerson();
	
	while (looping) {
		switch (option) {
		case 'j':
			std::cout << "Bitte den Nachnamen der " << anzahl_personen + 1 << ". Person eingeben: ? ";
			std::cin >> lastName;
			std::cout << "Bitte den Vornamen der " << anzahl_personen + 1 << ". Person eingeben: ? ";
			std::cin >> firstName;
			std::cout << "Bitte das Alter der " << anzahl_personen + 1 << ". Person eingeben: ? ";
			std::cin >> age;
			std::cout << "Bitte das Geschlecht der " << anzahl_personen + 1 << ". Person eingeben: ? ";
			std::cin >> sex;

			person.nachname = lastName;
			person.vorname = firstName;
			person.alter = age;
			person.geschlecht = sex;

			personen[anzahl_personen] = person;
			anzahl_personen++;

			option = askForPerson();
			break;
		case 'n':
			filter(personen, anzahl_personen);
			looping = false;
			break;
		}
	}
	
	std::system("PAUSE");
	return 0;
}