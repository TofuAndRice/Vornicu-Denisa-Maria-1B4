#pragma once
#include "Car.h"
class Seat :
    public Car
{
public:
    Seat(); //constructor default
    virtual int GetFuelCapacity() const override;
    virtual int GetFuelConsumption() const override;
    virtual double GetRaceTime(int length, Weather condition) override;
};