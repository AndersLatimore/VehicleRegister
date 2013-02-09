//
//  MotorBikes.h
//  InlamningsUppgiftIIB
//
//  Created by Anders Akesson on 11/29/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#ifndef __InlamningsUppgiftIIB__MotorBikes__
#define __InlamningsUppgiftIIB__MotorBikes__

#include "Vehicle.h"
#include <iostream>
#include <string>

using namespace std;

class MotorBikes: public Vehicle
{
    
private:
    int cc;
    
public:
    MotorBikes(string newMark, int newYear, string newLicensePlate, double newPrice, int newCc) : Vehicle(newMark, newYear, newLicensePlate, newPrice)
    {
        this -> cc = newCc;
    }
    void setCc(int newCc) {this -> cc = newCc;}
    int getCc() const {return this -> cc;}
    virtual string getClassName();
    virtual string getMark() const;
    virtual int getYear() const;
    virtual string getLicensePlate() const;
    virtual double getPrice() const;

    virtual string toString();
    virtual ~MotorBikes(){};

};

#endif /* defined(__InlamningsUppgiftIIB__MotorBikes__) */
