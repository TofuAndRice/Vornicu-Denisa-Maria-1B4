#pragma once
#include "Car.h"
class Volvo :
    public Car
{
public:
    Volvo(); //constructor default
    virtual int GetFuelCapacity() const override;
    virtual int GetFuelConsumption() const override;
    virtual double GetRaceTime(int length, Weather condition) override;
};