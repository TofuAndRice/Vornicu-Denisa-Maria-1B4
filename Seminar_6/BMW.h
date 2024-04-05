#pragma once
#include "Car.h"
class BMW :
    public Car
{
public:
    BMW(int capacity, int consumption); //constructor 
    virtual int GetFuelCapacity() const override;
    virtual int GetFuelConsumption() const override;
    virtual double GetRaceTime(int length, Weather condition) override;


    /*
    //alta varianta:
    virtual int GetFuelCapacity() const override { return 1; }
    virtual int GetFuelConsumption() const override { return 2; }
    */
};

