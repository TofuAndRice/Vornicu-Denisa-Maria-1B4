#pragma once
class Number
{
	char* sir;
	int nrBase;
	unsigned int sirLen;
public:
	Number(); //Number n1;
	Number(const char* value, int base); //Number n1("23", 4);
	Number(int x); //Number n1(234); || Number n1=234;
	~Number();

	Number(const Number& x); //copy op., pt functii: parametrii, return etc;
	Number(const Number&& x); //move op., n1 = Number("22",5) este folosit temporar pt initializarea unei variabile, SAU pentru mutarea doar a anumitor resurse
	Number& operator=(Number&& x); //move (=) ass. op.
	Number& operator=(int x); //move ass. op.
	Number& operator=(const char* x); //move ass. op.

	// other operators:
	friend Number operator+(Number x1, Number x2); //poti folosi fara & daca ai copy constrcutor deja, & precizeaza ca foloseste obiectul respectiv si ca nu va face copie
	friend Number operator-(Number x1, Number x2);
	char operator[](int x);
	Number& operator+=(Number& x); //(+=) ass. op.
	bool operator>(Number x);
	Number& operator--(); //--n1;
	Number operator--(int x); //n1--;
	Number& operator++(); //++n1;
	Number operator++(int x); //n1++;
	bool operator<(Number x);
	bool operator==(Number x);
	bool operator!();

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base

	//unsigned int GetBase10Number() const;
};
