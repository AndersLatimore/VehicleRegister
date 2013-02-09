//
//  VehicleRegister.cpp
//  InlamningsUppgiftIIB
//
//  The vehicle register, see more info in main.
//
//  Created by Anders Akesson on 11/29/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#include "VehicleRegister.h"
#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>

using namespace std;

    // constructor
VehicleRegister::VehicleRegister()
{
    this->nrOfVehicles = 0;
    this->arraySize = 1;
    this->nrOfCars = 0;
    this->nrOfBikes = 0;
    
    vehicles = new Vehicle*[arraySize];
    
    for (int i = 0; i < this->arraySize; i++)
    {
        vehicles[i] = new Vehicle();
    }
    
}
    // copy constructor
VehicleRegister::VehicleRegister(const VehicleRegister& vehRegRef)
{
    this -> nrOfVehicles = vehRegRef.nrOfVehicles;
    this -> arraySize = vehRegRef.arraySize;
    this -> nrOfCars = vehRegRef.nrOfCars;
    this -> nrOfBikes = vehRegRef.nrOfBikes;
    
    Vehicle** vehicles = new Vehicle*[nrOfVehicles];
    
    for (int i = 0; i < this->nrOfVehicles; i++)
    {
        vehicles[i] = new Vehicle(*vehRegRef.vehicles[i]);
    }
}
    // overloaded operator
VehicleRegister VehicleRegister::operator=(const VehicleRegister &reg)
{
    if (this -> nrOfVehicles > 0)
    {
        for (int i = 0; i < this->nrOfVehicles; i++)
        {
            delete vehicles[i];
        }
        delete [] this-> vehicles;
    }
    this -> nrOfVehicles = reg.nrOfVehicles;
    this -> arraySize = reg.arraySize;
    this -> nrOfCars = reg.nrOfCars;
    this -> nrOfBikes = reg.nrOfBikes;
    this -> vehicles = new Vehicle*[this -> arraySize];
    
    for (int i = 0; i < this->nrOfVehicles; i++)
    {
        vehicles[i] = new Vehicle(*reg.vehicles[i]);
    }
    return *this;
}
    // resize the arraysize
void VehicleRegister::resize()
{
    Vehicle** temp;
    this->arraySize = this->arraySize * 2;
    temp = new Vehicle*[this->arraySize];
    
    for (int i = 0; i < this->nrOfVehicles; i++)
    {
        temp[i] = vehicles[i];
    }
    delete [] vehicles;
    
    vehicles = temp;
}
    // show-functions
string* VehicleRegister::showAll(string array[], int length) const
{
    if(this->nrOfVehicles == 0)
    {
        cout << "No vehicles registered. " << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < this->nrOfVehicles; i++)
        {
            array[i] = vehicles[i]->toString();
        }
        return array;
    }
}
string* VehicleRegister::showAllLicense(string licensePlateIn, string array[],  int length) const
{
    if(this->nrOfVehicles == 0)
    {
        cout << "No vehicles registered. " << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < this->nrOfVehicles; i++)
        {
               if(licensePlateMatch(licensePlateIn, vehicles[i]->getLicensePlate()))
               {
                    array[i] = vehicles[i]->toString();
               }
        }
        return array;
    }
}
string* VehicleRegister::showAllCars(string array[], int length) const
{
    if(this->nrOfCars == 0)
    {
        cout << "No cars registered. " << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < this->nrOfVehicles; i++)
        {
            if(vehicles[i]->getClassName() == "Car")
            {
                array[i] = vehicles[i]->toString();
            }
        }
        return array;
    }
}
string* VehicleRegister::showAllBikes(string array[], int length) const
{
    if(this->nrOfBikes == 0)
    {
        cout << "No bikes registered. " << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < this->nrOfVehicles; i++)
        {
            if(vehicles[i]->getClassName() == "MotorBikes")
            {
                array[i] = vehicles[i]->toString();
            }
        }
        return array;
    }
}
string* VehicleRegister::showInfoLicense(string licensePlateIn, string array[], int length) const
{
    if(nrOfVehicles == 0)
    {
        cout << "No vehicles registered. " << endl;
        return 0;
    }
    for (int i = 0; i < this->nrOfVehicles; i++)
    {
        if((licensePlateIn == vehicles[i]->getLicensePlate()))
        {
            array[i] = vehicles[i]->toString();
        }
    
    }
    return array;
}
    // add-functions
void VehicleRegister::addCar(string newMark, int newYear, string newLicensePlate, double newPrice, string newFuelType, string newSize)
{
    for (int i = 0; i < this->nrOfVehicles; i++)
    {
        if (newLicensePlate == vehicles[i]->getLicensePlate())
        {
            cout << "That vehicle already exists. " << endl;
            return;
        }
    }
    if(this->nrOfVehicles >= this->arraySize)
    {
        resize();
    }
    vehicles[nrOfVehicles] = new Car(newMark, newYear, newLicensePlate, newPrice, newFuelType, newSize);
    
    this->nrOfCars++;
    this->nrOfVehicles++;
}
void VehicleRegister::addBike(string newMark, int newYear, string newLicensePlate, double newPrice, int newCc)
{
    for (int i = 0; i < nrOfVehicles; i++)
    {
        if (newLicensePlate == vehicles[i]->getLicensePlate())
        {
            cout << "That vehicle already exists. " << endl;
            return;
        }
    }
    
    if(this->nrOfVehicles >= this->arraySize)
    {
        resize();
    }
    
    vehicles[nrOfVehicles] = new MotorBikes(newMark, newYear, newLicensePlate, newPrice, newCc);
    
    this->nrOfBikes++;
    this->nrOfVehicles++;
}
    // delete-function
void VehicleRegister::removeVehicleLicense(string licensePlateIn)
{
    if(nrOfVehicles == 0)
    {
        cout << "No vehicles registered. " << endl;
        return;
    }
    for (int i = 0; i < nrOfVehicles; i++)
    {
        if (licensePlateIn == vehicles[i]->getLicensePlate())
        {
            cout << "Removing vehicle with platenumber " << vehicles[i]->getLicensePlate() << "..." << endl;
            vehicles[i] = vehicles[--nrOfVehicles];
            
            if(vehicles[i]->getClassName() == "Car")
            {
                nrOfCars = nrOfCars -1;
            }
            else if (vehicles[i] -> getClassName() == "MotorBikes")
            {
                nrOfBikes = nrOfBikes - 1;
            }
        }
    }
}
    // get number of cars and bikes
int VehicleRegister::getNrOfCars()
{
    return this->nrOfCars;
}
int VehicleRegister::getNrOfBikes()
{
    return this->nrOfBikes;
}
    // function to check if the licensplates match
bool VehicleRegister::licensePlateMatch(string const & lhs, string const & rhs) const
{
        assert(lhs.size() == 6);
        assert(rhs.size() == 6);
    
    for (int i = 0; i < 6; ++i)
    {
        if (lhs[i] == '*' || rhs[i] == '*')
            continue;
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}

    // destructor
VehicleRegister::~VehicleRegister()
{
    for (int i = 0; i < this->nrOfVehicles; i++)
    {
        delete vehicles[i];
        vehicles[i] = NULL;
    }
    delete vehicles;
    vehicles = NULL;
    
}