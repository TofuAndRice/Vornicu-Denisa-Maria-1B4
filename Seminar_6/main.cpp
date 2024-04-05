#include <iostream>
#include "Car.h"
#include "Circuit.h"
#include "BMW.h"	
#include "Volvo.h"
#include "Seat.h"
#include "RangeRover.h"
#include "Fiat.h"
#include "Weather.h"

using namespace std;

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Rain);

	BMW x(100, 5); //motive experimentale
	c.AddCar(&x); //cu & pentru ce nu este pointer 

	c.AddCar(new Volvo());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());

	cout << "Inainte de afisarea rankului:" << endl;
	c.Race();
	cout << endl << endl << "Rankul final este: " << endl;
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	cout << endl << endl <<"Cine nu a terminat: " << endl;
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit

	system("pause");
	return 0;
}
