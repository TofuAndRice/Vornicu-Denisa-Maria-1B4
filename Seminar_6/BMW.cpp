#include <iostream>
#include "BMW.h"
#include "Weather.h"

BMW::BMW(int capacity, int consumption) { //singurul constrcutor definit diferit, seteaza doar fuelCapacity si fuelConsumption in mod manual!
	fuelCapacity = capacity;
	fuelConsumption = consumption;
	// sunny, rain, snow:
	avgSpeed[0] = 3;
	avgSpeed[1] = 2;
	avgSpeed[2] = 1;
}

int BMW::GetFuelCapacity() const {
	return fuelCapacity;
}
int BMW::GetFuelConsumption() const {
	return fuelConsumption;
}

double BMW::GetRaceTime(int length, Weather condition) {
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