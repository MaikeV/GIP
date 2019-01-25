#include <iostream>
#include <string>
#include "Person.h";

Person extractPerson(std::string line) {
	int wordCount = 0;
	int nextWord = 0;
	Person person;
	int wordIndex = 0;

	for (int index = 0; index <= line.length() - 1; index++) {
		if (line.at(index) == ',' || index == line.length() - 1) {
			if (wordCount == 0) {
				for (int wordIndex = 0; wordIndex < index; wordIndex++) {
					person.lastName = person.lastName.append(1, line.at(wordIndex));
				}
			} else if (wordCount == 1) {
				for (int wordIndex = nextWord; wordIndex < index; wordIndex++) {
					person.firstName = person.firstName.append(1, line.at(wordIndex));
				}
			} else if (wordCount == 2) {
				for (int wordIndex = nextWord; wordIndex < line.length(); wordIndex++) {
					person.birthday = person.birthday.append(1, line.at(wordIndex));
				}
			}

			wordCount++;
			nextWord = index + 2;
		} 
	}

	return person;
}