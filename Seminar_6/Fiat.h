#pragma once
#include "Car.h"
class Fiat :
    public Car
{
public:
    Fiat(); //constructor default
    virtual int GetFuelCapacity() const override;
    virtual int GetFuelConsumption() const override;
    virtual double GetRaceTime(int length, Weather condition) override;
};
