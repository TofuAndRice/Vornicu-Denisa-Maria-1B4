#include "RangeRover.h"
#include "Fiat.h"
#include "Seat.h"
#include <iostream>
#include "Volvo.h"
#include "Weather.h"

RangeRover::RangeRover() {
	fuelCapacity = 100;
	fuelConsumption = 8;
	// sunny, rain, snow:
	avgSpeed[0] = 1;
	avgSpeed[1] = 30;
	avgSpeed[2] = 1;
}

int RangeRover::GetFuelCapacity() const {
	return fuelCapacity;
}
int RangeRover::GetFuelConsumption() const {
	return fuelConsumption;
}

double RangeRover::GetRaceTime(int length, Weather condition) {
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