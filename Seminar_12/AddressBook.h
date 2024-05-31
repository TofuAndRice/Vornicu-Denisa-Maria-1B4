#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

class AddressBook
{
private:
	Contact* people;
	int size;
public:
	AddressBook();
	int searchName(char* x);
	Friend* listFriends();
	void deleteName(char* x);
	void addName(Contact x);
};

#endif

