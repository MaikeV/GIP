#include <iostream>
#include <string>

char* my_strconcat(const char *ptr1, const char *ptr2) {
	char *result = new char[40];
	int start = 0;
	//char *ptr11 = new char[20]{ *ptr1 };
	//char *ptr22 = new char[20]{ *ptr2 };

	while (*ptr1 != '\0') {
		result[start++] = *ptr1;
		ptr1++;
	}

	while (*ptr2 != '\0') {
		result[start++] = *ptr2;
		ptr2++;
	}
	if (start < 40)
		result[start] = '\0';
	return result;
}

int main() {
	std::string part1, part2;
	char ptr1[20], ptr2[20];
	char *result = new char[40];

	std::cout << "Bitte ersten Text eingeben (ggfs. mit Leerzeichen): ? ";
	std::cin.getline(ptr1, 20);
	std::cout << "Bitte zweiten Text eingeben (ggfs. mit Leerzeichen): ? ";
	std::cin.getline(ptr2, 20);

	result = my_strconcat(ptr1, ptr2);

	std::cout << "Ergebnis my_strconcat(): " << result << std::endl;
	
	std::system("PAUSE");
	return 0;
}