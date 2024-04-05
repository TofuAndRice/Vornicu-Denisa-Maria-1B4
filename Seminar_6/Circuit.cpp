#include <iostream>
#include "Circuit.h"
#include "Car.h"
#include "BMW.h"
#include "Volvo.h"
using namespace std;

Circuit::Circuit() {
	length = 0;
	nrcars = 0;
	cars = new Car*[10]; 
}

int Circuit::GetLength() {
	return length;
}

void Circuit::SetLength(int length) {
	this->length = length;
}
void Circuit::SetWeather(Weather weather) {
	this->weather = weather;
}

void Circuit::AddCar(Car* object) {
	cars[nrcars++] = object;
}

void Circuit::Race() {
	for (int i = 0; i < nrcars; i++) {
		cout << typeid(*cars[i]).name()<<" : "<<cars[i]->GetRaceTime(length, weather) << " || "; // typeid(*cars[i]).name() afiseaza clasa
	}
}

void Circuit::ShowFinalRanks() {
	for (int i = 0; i < nrcars-1; i++) {
		for (int j = i + 1; j < nrcars; j++) {
			if (cars[i]->GetRaceTime(length, weather) > cars[j]->GetRaceTime(length, weather)) {
				Car* aux = cars[i];
				cars[i] = cars[j];
				cars[j] = aux;
			}
		}
	}
	Race();
}

void Circuit::ShowWhoDidNotFinish() {
	for (int i = 0; i < nrcars; i++) {
		if (cars[i]->GetFuelCapacity() < cars[i]->GetRaceTime(length, weather) * cars[i]->GetFuelConsumption()) {
			cout << typeid(*cars[i]).name() << " || ";
		}
	}

}