#ifndef ACQUAINTANCE_H
#define ACQUAINTANCE_H

class Acquaintance :
    public Contact
{
private:
    char* phoneNumber;
    Type person = ACQUAINTANCE;

public:
    Acquaintance();
    Acquaintance(char* x);
};
#endif
