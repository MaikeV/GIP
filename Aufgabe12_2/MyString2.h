#pragma once
#include <string>
#include "CharListenKnoten.h"

class MyString2 {
	friend void friend_append_internal(MyString2& s, char p_data);
	friend void friend_delete_internal(MyString2& s);
	friend CharListenKnoten* friend_deep_copy_internal(MyString2& s);
private:
	CharListenKnoten *anker;

	void append_internal(char p_data);
	void delete_internal();
	CharListenKnoten* deep_copy_internal() const;
public:
	MyString2() {}; // Konstruktor
	MyString2(CharListenKnoten *anker) {
		this->anker = anker;
	}

	MyString2(std::string str) { // Konstruktor aus std::string
		for (int index = 0; index <= str.length() - 1; index++) {
			append_internal(str.at(index));
		}
	}

	MyString2(const MyString2& sourceString) { // Copy-Konstruktor
		deep_copy_internal();
	}

	~MyString2() { // Destruktor
		delete_internal();
	}

	MyString2& operator = (const MyString2 &orig); // Assignment-Operator

	// getter
	CharListenKnoten* get_anker() const { return anker; }

	// setter
	void set_anker(CharListenKnoten *anker) { 
		this->anker = anker;
	}

	// functions
	unsigned int length();
	char at(unsigned int pos);
	MyString2 operator +(char c);
	std::string to_string();
};