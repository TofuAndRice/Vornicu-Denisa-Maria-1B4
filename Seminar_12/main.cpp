#include<iostream>
#include"Contact.h"
#include"Friend.h"
#include"Acquaintance.h"
#include"Colleague.h"
#include"AddressBook.h"

using namespace std;
int main(){
    AddressBook addressBook;
    Contact x("John"), y("Denise"), z("Daniel");
    addressBook.addName(x);
    addressBook.addName(y);
    addressBook.addName(z);
    Friend a, b, c;


    /*addressBook.listFriends();

    cout << "Searching for John Doe:" << endl;
    Contact* contact = addressBook.searchContact("John Doe");
    if (contact) {
        contact->print();
    }
    else {
        cout << "Contact not found." << endl;
    }

    cout << "Deleting John Doe:" << endl;
    addressBook.deleteContact("John Doe");

    cout << "Searching for John Doe again:" << endl;
    contact = addressBook.searchContact("John Doe");
    if (contact) {
        contact->print();
    }
    else {
        cout << "Contact not found." << endl;
    }

    return 0;*/

}