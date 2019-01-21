#pragma once

class CharListenKnoten {
private:
	char data;
	CharListenKnoten *next;

public:
	CharListenKnoten() {
		data = '\0';
		next = nullptr;
	}

	CharListenKnoten (char data, CharListenKnoten *next) {
		this->data = data;
		this->next = next;
	}

	~CharListenKnoten() {}

	void set_data(char data) {
		this->data = data;
	}

	void set_next(CharListenKnoten *next) {
		this->next = next;
	}

	char get_data() const { return data; }
	CharListenKnoten* get_next() const { return next; }
};