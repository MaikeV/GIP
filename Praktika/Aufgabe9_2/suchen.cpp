#include <iostream>
#include <string>
#include "suchen.h"

int getLength(const char text[]) {
	for (int index = 0; index < 20; index++) {
		if (text[index] == '\0') {
			return index;
		}
	}
}

int suchen(const char text[], const char subtext[]) {
	int subIndex = 0;
	int returnCode = -1;
	int index = 0;

	int subLength = getLength(subtext);
	int length = getLength(text);

	if (subLength > length) {
		return -1;
	}

	while (text[index] != '\0') {
		if (text[index] == subtext[subIndex]) {
			if (subIndex == 0) {
				returnCode = index;
			} 
			
			if (subIndex == subLength - 1) {
				break;
			} else if ((length - index) < (subLength - subIndex)) {
				return -1;
			}
				
			subIndex++;
		} else {
			subIndex = 0;
			returnCode = -1;
		}

		index++;
	}

	return returnCode;
}