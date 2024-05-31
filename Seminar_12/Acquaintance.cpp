#include "Acquaintance.h"
#include<cstring>

Acquaintance::Acquaintance() {
	phoneNumber = nullptr;
}
Acquaintance::Acquaintance(char* x) {
	phoneNumber = new char[strlen(x)];
	strcpy(phoneNumber, x);
}