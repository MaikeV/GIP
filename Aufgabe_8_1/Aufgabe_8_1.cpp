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
	} while (option != 'j' || option != 'n');

	return option;
}

void addPerson(Person person) {

}

int main() {
	Person personen[100];
	int anzahl_personen = 0;
	char option, sex;
	int age;
	std::string lastName, firstName;

	option = askForPerson();
	Person person;

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

		addPerson(person);
		askForPerson();

	case 'n':
	}

	std::system("PAUSE");
	return 0;
}