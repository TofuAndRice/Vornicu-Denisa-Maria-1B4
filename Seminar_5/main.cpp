#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Number.h"

using namespace std;

int main(){
    Number n1("10110010", 2);
    Number n2("734", 8);
    Number n3("FF", 16);

    printf("n1: ");
    n1.Print();
    printf("n2: ");
    n2.Print();
    printf("n3: ");
    n3.Print();

    printf("\nn1 has %d digits and it is written in base %d:\n", n1.GetDigitsCount(), n1.GetBase());
    for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
    {
        printf("n1[%d]=%c\n", tr, n1[tr]);
    }

    printf("\nCalculate: n1 = (n2 + n3 - n1) + n1  \n\n");
    n1 = (n2 + n3 - n1) + n1; // after this n1 will be in base 16
    printf("Now, n1 = ");
    n1.Print();

    printf("\nn1 changing base:\n");
    n1.SwitchBase(2);
    n1.Print();

    if (n3 > n1) printf("n3 is bigger than n1\n\n"); else printf("n3 is smaller than n1\n\n");

    
    Number n4=70; // in base 10, with constructor
    n4.Print();

    Number n5;
    n5 = 32; // in base 10, with move ass. op.
    n5.Print();

    n1 = 255; // in base 2, with move ass. op.
    n1.Print();

    n4+=n1;
    n4.Print();

    n4 = "13579"; // n4 mentains its base (10) and will be 13579
    n4.Print();

    printf("\n");
    --n4; // the first digit from n4 will be remove ==> n4 becomes 3579
    n4.Print();

    n4--; // the last digit from n4 will be remove ==> n4 becomes 357
    n4.Print();

    if (!n4) printf("\nBaza este 0\n");
    else printf("\nBaza este diferita de 0\n");

    return 0;
}
