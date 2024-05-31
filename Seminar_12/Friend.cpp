#include "Friend.h"
#include<cstring>

Friend::Friend() {
	phoneNumber = nullptr;
	dateBirth = nullptr;
	address = nullptr;
}

Friend::Friend(const char* x, const char* y, const char* z) {
	phoneNumber = new char[strlen(x)];
	dateBirth = new char[strlen(y)];
	address = new char[strlen(z)];
	strcpy(phoneNumber, x);
	strcpy(dateBirth, y);
	strcpy(address, z);
}