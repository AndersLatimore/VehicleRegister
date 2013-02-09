//
//  Vehicle.cpp
//  InlamningsUppgiftIIB
//
//  Created by Anders Akesson on 11/29/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#include "Vehicle.h"
#include <sstream>
#include <string>

using namespace std;

Vehicle::Vehicle(string newMark, int newYear, string newLicensePlate, double newPrice)
{
    this -> mark = newMark;
    this -> year = newYear;
    this -> licensePlate = newLicensePlate;
    this -> price = newPrice;
}
string Vehicle::toString()
{
    stringstream vehicleStrStream;
    vehicleStrStream << this -> mark << "\t" << this -> year << "\t" << this -> licensePlate << "\t" << this -> price << endl;
    return vehicleStrStream.str();
}
string Vehicle::getClassName()
{
    string getClassNameVehicle = "Vehicle";
    return getClassNameVehicle;
}

int Vehicle::compare(const Vehicle& v) const
{
    return
    (mark < v.mark)                 ? -1:
    (mark > v.mark)                 ? -1:
    (year > v.year)                 ? -1:
    (year < v.year)                 ? -1:
    (licensePlate < v.licensePlate) ? -1:
    (licensePlate > v.licensePlate) ? -1:
    (price < v.price)               ? -1:
    (price > v.price)               ? -1:
    0;
}
