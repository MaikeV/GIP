#include "MyString2.h"

MyString2& MyString2::operator =(const MyString2 &orig) {
	delete_internal();

	CharListenKnoten *ptr = orig.get_anker();
	
	while (ptr != nullptr) {
		append_internal(ptr->get_data());
		ptr = ptr->get_next();
	}
	
	return *this;
}

void MyString2::append_internal(char p_data) {
	CharListenKnoten *ptr = this->anker;
	CharListenKnoten *newEntry = new CharListenKnoten;
	newEntry->set_data(p_data);
	newEntry->set_next(nullptr);

	if (anker == nullptr) {
		anker = newEntry;
		return;
	}

	while (ptr->get_next() != nullptr) {
		ptr = ptr->get_next();
	}

	ptr->set_next(newEntry);
}

void MyString2::delete_internal() {
	CharListenKnoten *ptr = this->anker;
	CharListenKnoten *temp;
	
	if (anker != nullptr) {
		while (ptr->get_next() != nullptr) {
			temp = ptr->get_next();
			delete ptr;
			ptr = temp;
		}

		anker = nullptr;
	}
}

CharListenKnoten* MyString2::deep_copy_internal() const {
	if (this->anker == nullptr) {
		return nullptr;
	}

	CharListenKnoten *ptr = this->anker;
	MyString2 *str = new MyString2();

	while (ptr->get_next() != nullptr) {
		str->append_internal(ptr->get_data());
		ptr = ptr->get_next();
	}

	str->append_internal(ptr->get_data());

	return str->get_anker();
}

unsigned int MyString2::length() {
	CharListenKnoten *ptr = this->anker;

	unsigned int length = 0;

	while (ptr != nullptr) {
		length++;
		ptr = ptr->get_next();
	}

	return length;
}

char MyString2::at(unsigned int pos) {
	CharListenKnoten *ptr = this->anker;

	if (pos > this->length()) {
		return '\0';
	}

	for (int index = 0; index < pos; index++) {
		ptr = ptr->get_next();
	}

	return ptr ? ptr->get_data() : '\0';
}

MyString2 MyString2::operator +(char c) const {
	MyString2 str = MyString2{*this};
	str.append_internal(c);

	return str;
}

std::string MyString2::to_string() {
	CharListenKnoten *ptr = this->anker;
	int length = this->length();
	std::string str;

	while (ptr != nullptr) {
		str += ptr->get_data();
		ptr = ptr->get_next();
	}

	return str;
}