#include <iostream>
#include "Volvo.h"
#include "Weather.h"

Volvo::Volvo() { 
	fuelCapacity = 100;
	fuelConsumption = 8;
	// sunny, rain, snow:
	avgSpeed[0] = 1;
	avgSpeed[1] = 20;
	avgSpeed[2] = 1;
}

int Volvo::GetFuelCapacity() const {
	return fuelCapacity;
}
int Volvo::GetFuelConsumption() const {
	return fuelConsumption;
}

double Volvo::GetRaceTime(int length, Weather condition) {
	double raceTime;
	if (condition == Sunny) {
		raceTime = (double)length / avgSpeed[0];
	}
	else if (condition == Rain) {
		raceTime = (double)length / avgSpeed[1];
	}
	else if (condition == Snow) {
		raceTime = (double)length / avgSpeed[2];
	}
	return raceTime;
}