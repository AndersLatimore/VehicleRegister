//
//  Vehicle.h
//  InlamningsUppgiftIIB
//
//  Created by Anders Akesson on 11/29/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#ifndef __InlamningsUppgiftIIB__Vehicle__
#define __InlamningsUppgiftIIB__Vehicle__

#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
    
protected:
    string mark;
    int year;
    string licensePlate;
    double price;
    
public:
    Vehicle()
    {
        setMark(""), setYear(0000), setlicensePlate("AAA000"), setPrice(0.0);
    }
    Vehicle(string newMark, int newYear, string newLicensePlate, double newPrice);
    
    void setMark(string newMark) {this -> mark = newMark;}
    void setYear(int newYear) {this -> year = newYear;}
    void setlicensePlate(string newLicensePlate) {this -> licensePlate = newLicensePlate;}
    void setPrice (double newPrice) {this -> price = newPrice;}
    
    virtual string getMark() const {return this -> mark;}
    virtual int getYear() const {return this -> year;}
    virtual string getLicensePlate() const {return this -> licensePlate;}
    virtual double getPrice() const {return this -> price;}
    int compare(const Vehicle& v) const;
    virtual string getClassName();

    virtual string toString();
    virtual ~Vehicle(){};

};


#endif /* defined(__InlamningsUppgiftIIB__Vehicle__) */
