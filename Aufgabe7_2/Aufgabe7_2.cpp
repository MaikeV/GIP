#include <iostream>
#include <string>
#include <fstream>
#include "person.h";

std::string createShort(Person person) {
	std::string shortText;

	shortText = "<b>" + person.lastName + "</b>, " + person.firstName + "<br/>";

	return shortText;
}

std::string createLong(Person person) {
	std::string longText;

	longText = "<b>" + person.firstName + " " + person.lastName + "</b>, " + person.birthday + "<br/>";

	return longText;
}

int main() {
	std::string htmlLine;
	std::string html;
	std::string line;
	std::string shortText;
	std::string longText;
	Person person;

	std::fstream dataFile("personendaten.txt", std::ios::in);
	std::fstream htmlTemp("webseite.html.tmpl", std::ios::in);
	std::fstream htmlOutp("website.html", std::ios::out);

	while (std::getline(dataFile, line)) {
		person = extractPerson(line);
		shortText = shortText.append(createShort(person));
		longText = longText.append(createLong(person));

		std::cout << shortText << " " << longText << std::endl;
	}

	dataFile.close();

	while (std::getline(htmlTemp, htmlLine)) {
		if (htmlLine == "<p>%</p>") {
			htmlLine = htmlLine.replace(3, 1, shortText);
		} else if (htmlLine == "<p>$</p>") {
			htmlLine = htmlLine.replace(3, 1, longText);
		}
		
		html = html.append(htmlLine);
		std::cout << html;
	}

	htmlTemp.close();
	
	htmlOutp << html;
	
	htmlOutp.close();

	std::system("PAUSE");
	return 0;
}