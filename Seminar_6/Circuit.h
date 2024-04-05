#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit
{
private:
	int length;
	Weather weather;
    Car** cars; //array of Car
	int nrcars;
public:
	Circuit(); //constructor
	void AddCar(Car* object);
	void SetLength(int length);
	void SetWeather(Weather weather);
	int GetLength();
	void GetWeather();
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

