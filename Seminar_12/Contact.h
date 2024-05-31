#ifndef CONTACT_H
#define CONTACT_H

enum Type {
	FRIEND, 
	ACQUAINTANCE, 
	COLLEAGUE
};
class Contact
{
private:
	char* name;
	//Friend* friends;
	int position;
public:
	Contact(); 
	Contact(const char* x); 
	char* getName();
	//void addFriend(Friend* x);
};
#endif

