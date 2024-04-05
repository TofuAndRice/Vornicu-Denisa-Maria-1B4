#pragma once
#include "Weather.h"
class Car
{
protected:
	int fuelCapacity;
	int fuelConsumption;
	int avgSpeed[3]; // sunny, rain, snow
public:
	virtual double GetRaceTime(int length, Weather condition) = 0;
	virtual int GetFuelCapacity() const = 0;
	virtual int GetFuelConsumption() const = 0;
	//virtual int GetAverageSpeed(Weather weather) const = 0;
};

