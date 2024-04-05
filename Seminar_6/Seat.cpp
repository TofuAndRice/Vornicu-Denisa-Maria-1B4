#include "Seat.h"
#include <iostream>
#include "Volvo.h"
#include "Weather.h"

Seat::Seat() {
	fuelCapacity = 100;
	fuelConsumption = 8;
	// sunny, rain, snow:
	avgSpeed[0] = 1;
	avgSpeed[1] = 4;
	avgSpeed[2] = 1;
}

int Seat::GetFuelCapacity() const {
	return fuelCapacity;
}
int Seat::GetFuelConsumption() const {
	return fuelConsumption;
}

double Seat::GetRaceTime(int length, Weather condition) {
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