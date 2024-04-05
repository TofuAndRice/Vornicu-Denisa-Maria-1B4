#pragma once
#include "Car.h"
class RangeRover :
    public Car
{
public:
    RangeRover(); //constructor default
    virtual int GetFuelCapacity() const override;
    virtual int GetFuelConsumption() const override;
    virtual double GetRaceTime(int length, Weather condition) override;
};