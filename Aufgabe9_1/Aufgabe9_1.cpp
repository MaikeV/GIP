#include <iostream>
#include <string>

struct TListenKnoten {
	int data;
	TListenKnoten *next;
	TListenKnoten *prev;
};

void printListBackwards(TListenKnoten* anker) {
	TListenKnoten *ptr = anker;
	std::string resultat = "";

	if (anker == nullptr) {
		resultat = "Leere Liste.";
	} else {
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
	
		resultat += "[ ";

		do {
			resultat += std::to_string(ptr->data);

			if (ptr->prev != nullptr) {
				resultat += " , ";
			} else {
				resultat += " ";
			}

			ptr = ptr->prev;
		} while (ptr != nullptr);

		resultat += "]";
	}
	
	std::cout << resultat << std::endl;
}

void hinten_anfuegen (TListenKnoten *&anker, const int wert) {
	TListenKnoten *neuer_eintrag = new TListenKnoten;
	neuer_eintrag->data = wert;
	neuer_eintrag->next = nullptr;
	neuer_eintrag->prev = nullptr;
	
	if (anker == nullptr) {
		anker = neuer_eintrag;
		return;
	}

	TListenKnoten *ptr = anker;
		
	while (ptr->next != nullptr) {
		ptr = ptr->next;
	}

	neuer_eintrag->prev = ptr;
	ptr->next = neuer_eintrag;
}

void deleteList(TListenKnoten *&anker) {
	TListenKnoten *ptr = anker;
	TListenKnoten *temp;

	if (anker != nullptr) {
		while (ptr->next != nullptr) {
			temp = ptr->next;
			delete ptr;
			ptr = temp;
		}

		anker = nullptr;
	}
}

void addToList (TListenKnoten* &anker, int newVal, int before) {
	TListenKnoten *ptr = anker;
	TListenKnoten *temp;
	TListenKnoten *newEntry = new TListenKnoten;
	newEntry->data = newVal;
	newEntry->next = nullptr;
	newEntry->prev = nullptr;

	if (anker == nullptr) {
		anker = newEntry;
		return;
	}

	if (anker->data == before) {
		newEntry->next = anker;
		anker->prev = newEntry;
		anker = newEntry;
		return;
	}

	while (ptr->next != nullptr && ptr->next->data != before) {
		ptr = ptr->next;
	}

	if (ptr->next != nullptr) {
		temp = ptr->next;
		ptr->next = newEntry;
		newEntry->prev = ptr;
		newEntry->next = temp;
		temp->prev = newEntry;
		return;
	}

	ptr->next = newEntry;
	newEntry->prev = ptr;
}

std::string liste_als_string(TListenKnoten * anker) {
	std::string resultat = "";

	if (anker == nullptr) {
		return "Leere Liste.";
	} else {
		resultat += "[ ";
		TListenKnoten *ptr = anker;

		do {
			resultat += std::to_string(ptr->data);
			
			if (ptr->next != nullptr) {
				resultat += " , ";
			} else {
				resultat += " ";
			}

			ptr = ptr->next;
		} while (ptr != nullptr);

		resultat += "]";
	}
	return resultat;
}

void liste_ausgeben(TListenKnoten * anker) {
	std::cout << liste_als_string(anker) << std::endl;
}

/*int main() {
	const int laenge = 10;
	TListenKnoten *anker = nullptr;
	int newVal, before;

	for (int i = 0; i < laenge; i++) {
		addToList(anker, i*i, 9999);
	}
		
	liste_ausgeben(anker);
	printListBackwards(anker);
	
	std::cout << "Einzufuegender Wert: "; 
	std::cin >> newVal;
	std::cout << "Vor welchem Wert? "; 
	std::cin >> before;

	addToList(anker, newVal, before);
	liste_ausgeben(anker);
	printListBackwards(anker);

	system("PAUSE");
	return 0;
} */

int main() {
	const int laenge = 10;
	TListenKnoten *anker = nullptr;
	liste_ausgeben(anker);
	deleteList(anker);

	for (int i = 0; i < laenge; i++) {
		addToList(anker, i*i, 9999);
	}
		
	liste_ausgeben(anker);
	printListBackwards(anker);

	addToList(anker, 99, 0);
	addToList(anker, 99, 25);
	addToList(anker, 99, 81);
	addToList(anker, 99, 9999);

	liste_ausgeben(anker);
	printListBackwards(anker);
	deleteList(anker);
	liste_ausgeben(anker);
	printListBackwards(anker);

	system("PAUSE");
	return 0;
}