#ifndef COLLEAGUE_H
#define COLLEAGUE_H

class Colleague : Contact
{
private:
    char* phoneNumber;
    char* company;
    char* address;
    Type person = COLLEAGUE;
public:
    Colleague();
    Colleague(char* x, char* y, char* z);
};
#endif


