#pragma once
#include <string>
#include <iostream>

struct Person {
	std::string firstName;
	std::string lastName;
	std::string birthday;
};

Person extractPerson(std::string line);