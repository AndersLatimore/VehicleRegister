//
//  Car.cpp
//  InlamningsUppgiftIIB
//
//  Created by Anders Akesson on 11/29/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#include "Car.h"
#include <sstream>

string Car::toString()
{
    stringstream carStrStream;
    carStrStream << this -> mark << "\t" << this -> year << "\t" << this -> licensePlate << "\t";
    carStrStream << this -> price << "\t" << this -> fuelType << "\t" << this -> size << endl;
    return carStrStream.str();
}
string Car::getClassName()
{
    string classNameCar = "Car";
    return classNameCar;
}
int Car::getYear() const
{
    return Vehicle::getYear();
}
string Car::getMark() const
{
    return Vehicle::getMark();
}
string Car::getLicensePlate() const
{
    return Vehicle::getLicensePlate();
}
double Car::getPrice() const
{
    return Vehicle::getPrice();
}
