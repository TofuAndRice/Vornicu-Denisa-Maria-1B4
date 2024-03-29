#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Number.h"

using namespace std;

Number::Number() { //default constructor, din motive experimentale
    sir = new char[100];
    sir[0] = 0;
    nrBase = 0;
    sirLen = 0;
}

Number::Number(const char* value, int base) { //constructor
    sir = new char[100]; //sau cu strlen(value) SAU sir = (char*) malloc(100 * sizeof(char));
	strcpy_s(sir, 100, value);
	nrBase = base;
    sirLen = strlen(sir);
}

Number::~Number() { //deconstructor
    delete[] sir;
    sir = nullptr;
}

Number::Number(const Number& x) { //copy constructor
    this->sir = new char[100];
    strcpy_s(this->sir, 100, x.sir);
    this->nrBase = x.nrBase;
    this->sirLen = x.sirLen;
}

Number::Number(const Number&& x) { //move constructor
    this->sir = new char[100];
    strcpy_s(this->sir, 100, x.sir);
    this->nrBase = x.nrBase;
    this->sirLen = x.sirLen;
}

Number& Number::operator=(Number&& x) { // !!!!! move assignemnt operator
    this->sir = new char[100];
    strcpy_s(this->sir, 100, x.sir);
    this->nrBase = x.nrBase;
    this->sirLen = x.sirLen;
    return *this;
}


int Number::GetDigitsCount() {
	return strlen(sir);
}

int Number::GetBase() {
	return nrBase;
}


void Number::Print() {
    printf("%s, in base %d \n", sir, nrBase);
}

int GetBase10Number(char* sir, int nrBase, int sirLen) 
{
    unsigned int result = 0, power = 1;
    int i;
    for (i = sirLen - 1; i >= 0; i--) {
        if (sir[i] >= '0' && sir[i] <= '9') {
            result = result + (sir[i] - '0') * power;
        }
        else {
            result = result + (sir[i] - 'A' + 10) * power;
        }
        power = power * nrBase;
    }
    return result;
}

char* GetChar(int num, int base) //Transforma (int)"num" in baza "base", ca sir de caractere
{

    char* base_num = new char[100];
    int index = 0;
    while (num > 0)
    {
        int dig = int(num % base);
        if (dig < 10) base_num[index++] = '0' + dig;
        else base_num[index++] = 'A' + dig - 10;
        num /= base;
    }
    base_num[index] = '\0';
    for (int i = 0, j = index - 1; i < j; ++i, --j) {
        char temp = base_num[i];
        base_num[i] = base_num[j];
        base_num[j] = temp;
    }
    return base_num;
}


Number::Number(int x) {
    sir = new char[100];
    strcpy_s(sir, 100, GetChar(x, 10));
    nrBase = 10;
    sirLen = strlen(sir);
}

Number& Number::operator=(int x) {
    if (nrBase == 0) {
        strcpy_s(sir, 100, GetChar(x, 10));
        nrBase = 10;
        sirLen = strlen(sir);
    }
    else {
        strcpy_s(sir, 100, GetChar(x, this->nrBase));
        sirLen = strlen(sir);
    }
    return *this;
}

void Number::SwitchBase(int newBase) {
    printf("%s (in base %d) is: ", sir, nrBase);
    int x = GetBase10Number(sir, nrBase, sirLen);
    strcpy_s(sir, 100, GetChar(x, newBase));
    nrBase = newBase;
}

Number operator+(Number x1, Number x2) {
    int aux1 = GetBase10Number(x1.sir, x1.nrBase, x1.sirLen);
    int aux2 = GetBase10Number(x2.sir, x2.nrBase, x2.sirLen);
    int sum = aux1 + aux2;
    printf("%d (base 10) + %d (base 10) = %d (base 10) \n", aux1, aux2, sum);
    int maximum_base;
    if (x1.nrBase > x2.nrBase) maximum_base = x1.nrBase;
    else maximum_base = x2.nrBase;
    return Number(GetChar(sum, maximum_base), maximum_base);
}

Number operator-(Number x1, Number x2) {
    int aux1 = GetBase10Number(x1.sir, x1.nrBase, x1.sirLen);
    int aux2 = GetBase10Number(x2.sir, x2.nrBase, x2.sirLen);
    int sum = aux1 - aux2;
    printf("%d (base 10) - %d (base 10) = %d (base 10) \n", aux1, aux2, sum);
    int maximum_base;
    if (x1.nrBase > x2.nrBase) maximum_base = x1.nrBase;
    else maximum_base = x2.nrBase;
    return Number(GetChar(sum, maximum_base), maximum_base);
}

Number& Number::operator+=(Number& x) {
    int aux1 = GetBase10Number(sir, nrBase, sirLen);
    int aux2 = GetBase10Number(x.sir, x.nrBase, x.sirLen);
    int sum = aux1 + aux2;
    printf("\n%d (base 10) + %d (base 10) = %d (base 10) \n", aux1, aux2, sum);
    int maximum_base;
    if (nrBase > x.nrBase) maximum_base = nrBase;
    else maximum_base = x.nrBase;

    strcpy_s(this->sir, 100, GetChar(sum, maximum_base));
    this->nrBase = maximum_base;
    sirLen = strlen(this->sir);
    return *this;
}

Number& Number::operator=(const char* x) {
    strcpy_s(sir, 100, x);
    sirLen = strlen(sir);
    return *this;
}

char Number::operator[](int x) {
    return sir[x];
}

Number& Number::operator--() {
    strcpy_s(sir, 100, sir + 1);
    sirLen = strlen(sir);
    return *this;
}

Number Number::operator--(int x) {
    sir[sirLen - 1] = 0;
    sirLen--;
    return Number(sir, nrBase);
}

Number& Number::operator++() {
    sirLen++;
    return *this;
}

Number Number::operator++(int x) {
    sirLen += 2;
    return Number(sir, nrBase);
}

bool Number::operator!() {
    return !nrBase;
}

bool Number::operator>(Number x) {
    int aux1 = GetBase10Number(sir, nrBase, sirLen);
    int aux2 = GetBase10Number(x.sir, x.nrBase, x.sirLen);
    printf("\nComparing %d with %d...\n", aux1, aux2);
    return aux1 > aux2;
}
