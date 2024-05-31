#include "Contact.h"
#include "Friend.h"
#include<cstring>

Contact::Contact() {
	name = nullptr;
	friends = new Friend[100];
	position = 0;
}

Contact::Contact(const char* x) {
	name = new char[strlen(x)];
	strcpy(name, x);
	friends = new Friend[100];
	position = 0;
}

void Contact::addFriend(Friend* x) {
	friends[position] = *x;
	position++;
}
