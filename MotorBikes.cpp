//
//  MotorBikes.cpp
//  InlamningsUppgiftIIB
//
//  Created by Anders Akesson on 11/29/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#include "MotorBikes.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string MotorBikes::toString()
{
    stringstream bikeStrStream;
    bikeStrStream << this -> mark << "\t" << this -> year << "\t" << this -> licensePlate << "\t" << this -> price << "\t" << this -> cc << endl;
    return bikeStrStream.str();
}
string MotorBikes::getClassName()
{
    string classNameMotorBikes = "MotorBikes";
    return classNameMotorBikes;
}
string MotorBikes::getMark() const
{
    return Vehicle::getMark();
}
int MotorBikes::getYear() const
{
    return Vehicle::getYear();
}
string MotorBikes::getLicensePlate() const
{
    return Vehicle::getLicensePlate();
}
double MotorBikes::getPrice() const
{
    return Vehicle::getPrice();
}