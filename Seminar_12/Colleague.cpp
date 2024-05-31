#include "Colleague.h"
#include<cstring>

Colleague::Colleague() {
	phoneNumber = nullptr;
	company = nullptr;
	address = nullptr;
}

Colleague::Colleague(char* x, char* y, char* z) {
	phoneNumber = new char[strlen(x)];
	company = new char[strlen(y)];
	address = new char[strlen(z)];
	strcpy(phoneNumber, x);
	strcpy(company, y);
	strcpy(address, z);
}