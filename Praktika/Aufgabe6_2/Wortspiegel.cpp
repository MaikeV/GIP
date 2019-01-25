#include <iostream>
#include <string>

void wortspiegel(std::string &text, int pos) {
	char temp;
	int first, last;

	for (int toLast = pos; toLast <= text.length(); toLast++) {
		if (toLast != text.length()) {
			if (text.at(toLast + 1) == ' ' || text.at(toLast + 1) == '.' || toLast + 1 == (text.length() - 1)) {
				last = toLast;
				break;
			}
		} else {
			last = text.length();
		}
	}

	for (int toFirst = pos; toFirst >= 0; toFirst--) {
		if (toFirst != 0) {
			if (text.at(toFirst - 1) == ' ' || text.at(toFirst - 1) == '.' || toFirst - 1 == 0) {
				first = toFirst;
				break;
			}
		} else {
			first = 0;
		}
	}

	int counter = 0;
	int length = (last - first) + 1;
	int swapper = length / 2;

	if (length % 2 != 0) {
		for (int index = first; index <= first + swapper; index++) {
			temp = text.at(index);
			text.at(index) = text.at(last - counter);
			text.at(last - counter) = temp;
			counter++;
		}
	} else {
		for (int index = first; index < first + swapper; index++) {
			temp = text.at(index);
			text.at(index) = text.at(last - counter);
			text.at(last - counter) = temp;
			counter++;
		}
	}
	
}
