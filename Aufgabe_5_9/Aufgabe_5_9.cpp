#include <iostream>
#include <string>

std::string trimme(std::string s) {
	std::string output = "";
	int begin = 0;
	int end = 0;
	bool beginning = false;
	bool ending = false;

	for (int index = 0; index <= s.length() - 1; index++) {
		if (s.at(index) != '+' && !beginning) {
			begin = index;
			beginning = true;
		}

		if (s.at(s.length() - 1 - index) != '+' && !ending) {
			end = s.length() - 1 - index;
			ending = true;
		}

		if (beginning && ending) {
			break;
		}
	}

	if (!(!beginning && !ending)) {
		for (int index = begin; index <= end; index++) {
			output += s.at(index);
		}
	}
	return output;
}

int main()
{
	std::string s = "";
	std::cout << "Bitte geben Sie die Textzeile ein: ? ";
	std::getline(std::cin, s);
	std::cout << "Vorher: " << s << std::endl;
	std::cout << "Nachher: " << trimme(s) << std::endl;
	
	system("PAUSE");
	return 0;
}