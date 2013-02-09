//
//  VehicleRegister.h
//  InlamningsUppgiftIIB
//
//  The vehicle register, see more info in main.
//
//  Created by Anders Akesson on 11/29/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#ifndef __InlamningsUppgiftIIB__VehicleRegister__
#define __InlamningsUppgiftIIB__VehicleRegister__

#include "Vehicle.h"
#include "Car.h"
#include "MotorBikes.h"
#include <iostream>
#include <string>
#include <vector>
#include "SmartArray.h"

using namespace std;

class VehicleRegister
{
    
private:
    Vehicle** vehicles;
    int nrOfVehicles;
    int arraySize;
    int nrOfCars;
    int nrOfBikes;
    
public:
    VehicleRegister();
    VehicleRegister(const VehicleRegister& vehRegRef);
    VehicleRegister operator=(const VehicleRegister &reg);
    int getNrOfVehicles() const {return this -> nrOfVehicles;}
    void resize();
    
    string* showAll(string array[], int length) const;
    string* showAllLicense(string licensePlateIn,string array[], int length) const;
    string* showAllCars(string array[], int length) const;
    string* showAllBikes(string array[], int length) const;
    void addCar(string newMark, int newYear, string newLicensePlate, double newPrice, string newFuelType, string newSize);
    void addBike(string newMark, int newYear, string newLicensePlate, double newPrice, int newCc);
    void removeVehicleLicense(string licensePlateIn);
    string* showInfoLicense(string licensePlateIn,string array[], int length) const;
    int getNrOfCars();
    int getNrOfBikes();
    bool licensePlateMatch(string const & lhs, string const & rhs) const;
    
    virtual ~VehicleRegister();
    
};

#endif /* defined(__InlamningsUppgiftIIB__VehicleRegister__) */
