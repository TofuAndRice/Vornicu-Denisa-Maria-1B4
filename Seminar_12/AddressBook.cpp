#include "AddressBook.h"
#include "Friend.h"
#include "Contact.h"
#include<cstring>
using namespace std;

AddressBook::AddressBook() {
	people = new Contact[100]; //ar trebui sa realoc memoria cand se depaseste size-ul de 100...
	size = 0;
}

Friend* AddressBook::listFriends() {
	Friend* list = new Friend [100];
	int j = 0;
	for (int i = 0; i < size; i++) {
		list[j] = people[i]->friends;
		j++;
	}
	return list;
}
int AddressBook::searchName(char* x) {
	for (int i = 0; i < size; i++) {
		if (strcmp(people[i]->getName(), x) == 0) {
			return 1;
		}
	}
	return 0;
}

void AddressBook::deleteName(char* x) {
	for (int i = 0; i < size; i++) {
		if (strcmp(people[i]->getName(), x) == 0) {
			for (int j = i; j < size - 1; j++) {
				people[j] = people[j + 1];
			}
			size--;
			break;
		}
	}
}

void AddressBook::addName(Contact x) {
	people[size] = x;
	size++;
}

