//
//  Car.h
//  InlamningsUppgiftIIB
//
//  Created by Anders Akesson on 11/29/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#ifndef __InlamningsUppgiftIIB__Car__
#define __InlamningsUppgiftIIB__Car__

#include "Vehicle.h"
#include <iostream>
#include <string>

using namespace std;

class Car:public Vehicle
{
    
private:
    string fuelType;
    string size;
    
public:
    Car(string newMark, int newYear, string newLicensePlate, double newPrice, string newFuelType, string newSize) : Vehicle(newMark, newYear, newLicensePlate, newPrice)
    {
        this -> fuelType = newFuelType;
        this -> size = newSize;
    }
    
    void setFuelType(string newFuelType) {this -> fuelType = newFuelType;}
    void setSize(string newSize) {this -> size = newSize;}
    virtual string getClassName();
    
    string getFuelType() {return this -> fuelType;}
    string getSize() {return this -> size;}
    virtual int getYear() const;
    virtual string getMark() const;
    virtual string getLicensePlate() const;
    virtual double getPrice() const;
    
    virtual string toString();
    virtual ~Car(){};
    
};

#endif /* defined(__InlamningsUppgiftIIB__Car__) */
