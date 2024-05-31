#ifndef FRIEND_H
#define FRIEND_H

class Friend : Contact
{
private:
    char* phoneNumber;
    char* dateBirth;
    char* address;
    Type person = FRIEND;
public:
    Friend();
    Friend(const char* x, const char* y, const char* z);    
};
#endif
