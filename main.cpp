//
//  main.cpp
//  InlamningsUppgiftIIB
//
//  This program is a register for vehicles; cars and motorbikes.
//  The program uses inheritance. It allocates memory dynamically.
//  The register is emtpty to start with, the user adds vehicles through a menu.
//
//  Created by Anders Akesson on 11/29/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "VehicleRegister.h"
#include "SmartArray.h"

using namespace std;

void displayMenu();
int getChoice();
string getLicensePlate();
string getMark();
int getYear();
string getNewLicensePlate();
double getPrice();
string getFuelType();
string getSize();
int getCc();
void printArray(string array[], int begin, int end);

int main()
{
    VehicleRegister myRegister;
    int choice = 0;
    string* ptr;
    
    do {
        displayMenu();
        choice = getChoice();
        switch (choice)
        {
            case 1:
            {
                ptr = new string[myRegister.getNrOfVehicles()];
                ptr = myRegister.showAll(ptr, 0);
                printArray(ptr, 0, myRegister.getNrOfVehicles());
                break;
            }
            case 2:
            {
                string licensePlateIn;
                licensePlateIn = getLicensePlate();
                ptr = new string[myRegister.getNrOfVehicles()];
                cout << "Showing info for licensplate " << licensePlateIn << endl;
                ptr = myRegister.showAllLicense(licensePlateIn, ptr, 0);
                printArray(ptr, 0, myRegister.getNrOfVehicles());
                break;
            }
            case 3:
            {
                ptr = new string[myRegister.getNrOfVehicles()];
                cout << "Displaying all cars: " << endl;
                ptr = myRegister.showAllCars(ptr, 0);
                printArray(ptr, 0, myRegister.getNrOfVehicles());
                break;
            }
            case 4:
            {
                ptr = new string[myRegister.getNrOfVehicles()];
                cout << "Displaying all bikes: " << endl;
                ptr = myRegister.showAllBikes(ptr, 0);
                printArray(ptr, 0, myRegister.getNrOfVehicles());
                break;
            }
            case 5:
            {
                string newMark;
                newMark = getMark();
                int newYear;
                newYear = getYear();
                string newLicensePlate;
                newLicensePlate = getNewLicensePlate();
                double newPrice;
                newPrice = getPrice();
                string newFuelType;
                newFuelType = getFuelType();
                string newSize;
                newSize = getSize();
                myRegister.addCar(newMark, newYear, newLicensePlate, newPrice, newFuelType, newSize);
                break;
            }
            case 6:
            {
                string newMark;
                newMark = getMark();
                int newYear;
                newYear = getYear();
                string newLicensePlate;
                newLicensePlate = getNewLicensePlate();
                double newPrice;
                newPrice = getPrice();
                int newCc;
                newCc = getCc();
                myRegister.addBike(newMark, newYear, newLicensePlate, newPrice, newCc);
                break;
            }
            case 7:
            {
                string licensePlateIn;
                licensePlateIn = getNewLicensePlate();
                myRegister.removeVehicleLicense(licensePlateIn);
                break;
            }
            case 8:
            {
                string licensePlateIn;
                licensePlateIn = getNewLicensePlate();
                cout << "You entered " << licensePlateIn << endl;
                cout << "\nShowing all matching vehicles: " << endl;
                ptr = new string[myRegister.getNrOfVehicles()];
                ptr = myRegister.showInfoLicense(licensePlateIn, ptr, 0);
                printArray(ptr, 0, myRegister.getNrOfVehicles());
                break;
            }
            case 9:
            {
                int numberOfBikes = 0;
                numberOfBikes = myRegister.getNrOfBikes();
                cout << numberOfBikes << endl;
                break;
            }
            case 10:
            {
                int numberOfCars = 0;
                numberOfCars = myRegister.getNrOfCars();
                cout << numberOfCars << endl;;
                break;
            }
            case 11:
            {
                int numberOfVehicles = 0;
                numberOfVehicles = myRegister.getNrOfVehicles();
                cout << numberOfVehicles << endl;
                break;
            }
            case 12:
                break;
            
        }
    } while (choice != 12);
    
    delete [] ptr;

    return 0;
}

void displayMenu() // Function to display the menu
{
    cout << "1. Show all vehicles:" << endl;
    cout << "2. Show all that matches the licenseplate: " << endl;
    cout << "3. Show all cars: " << endl;
    cout << "4. Show all bikes: " << endl;
    cout << "5. Add a car: " << endl;
    cout << "6. Add a bike: "<< endl;
    cout << "7. Remove vehicle: " << endl;
    cout << "8. Show info on one vehicle: " << endl;
    cout << "9. Get number of bikes: " << endl;
    cout << "10. Get number of cars: " << endl;
    cout << "11. Get number of vehicles: " << endl;
    cout << "12. Quit. " << endl;
    
    /*
    presentera alla fordon
    • presentera alla fordon som matchar delar av ett angivet
    registreringsnummer
    • presentera alla bilar
    • presentera alla motorcyklar
    • lägga in fordon
    • ta bort fordon med viss registreringsnummer
    • presentera info om ett givet fordon givet registreringsnummer
     */
}
int getChoice() // Function to get the choice from the user
{
    int choice;
    cout << "Enter your number of choice: " << endl;
    cin >> choice;
    cin.ignore();
    
    while(choice < 1 || choice > 12 || !(cin.good()))
    {
        cin.clear();               // clear error condition
        cin.ignore(100,'\n');     // remove characters)
        
        cout << "Not a valid input, choice can only by 1 - 12. " << endl;
        cout << "Please re-enter: ";
        cin >> choice;
        cin.ignore();
    }
    
    return choice;
}
string getLicensePlate()
{
    string licensePlateIn;
    cout << "Enter the licenseplate, six(6) characters. ";
    cout << "Enter * for the symbols you don't know: " << endl;
    getline(cin, licensePlateIn);
    while(licensePlateIn.length() < 6 || licensePlateIn.length() > 6)
    {
        cout << "Not a valid input, please re-enter: " << endl;
        cout << "Enter the licenseplate, six(6) characters. ";
        cout << "Enter * for the symbols you don't know: " << endl;
        getline(cin, licensePlateIn);
    }
    return licensePlateIn;
}
string getMark()
{
    string newMark;
    cout << "Enter the mark: " << endl;
    getline(cin, newMark);
    while(newMark.length() > 50 || newMark.length() < 1)
    {
        cout << "Not a valid input, please re-enter: " << endl;
        cout << "Enter the mark: " << endl;
        getline(cin, newMark);
    }
    return newMark;
}
int getYear()
{
    int newYear;
    cout << "Enter the year, four (4) digits: " << endl;
    cin >> newYear;
    cin.ignore();
    while(newYear < 1850 || newYear > 2013 || !(cin.good()))
    {
        cin.clear();               // clear error condition
        cin.ignore(100,'\n');     // remove characters)
        
        cout << "Not a valid input, enter four (4) digits: " << endl;
        cout << "Please re-enter: ";
        cin >> newYear;
        cin.ignore();
    }
    return newYear;
}
string getNewLicensePlate()
{
    string newLicensePlate;
    cout << "Enter the licenseplate, six (6) characters: " << endl;
    getline(cin, newLicensePlate);
    while(newLicensePlate.length() < 6 || newLicensePlate.length() > 6)
    {
        cout << "Not a valid input, please re-enter: " << endl;
        cout << "Enter the licenseplate, six(6) characters. ";
        getline(cin, newLicensePlate);
    }
    return newLicensePlate;
}
double getPrice()
{
    double newPrice;
    cout << "Enter the price: " << endl;
    cin >> newPrice;
    cin.ignore();
    while(newPrice < 0 || !(cin.good()))
    {
        cin.clear();               // clear error condition
        cin.ignore(100,'\n');     // remove characters)
        
        cout << "Not a valid input, please re-enter: ";
        cin >> newPrice;
        cin.ignore();
    }
    return newPrice;
}
string getFuelType()
{
    string newFuelType;
    cout << "Enter the fueltype of the car: " << endl;
    getline(cin, newFuelType);
    while(newFuelType.length() > 50 || newFuelType.length() < 1)
    {
        cout << "Not a valid input, please re-enter: " << endl;
        cout << "Enter the fueltype of the car: " << endl;
        getline(cin, newFuelType);
    }
    return newFuelType;
}
string getSize()
{
    string newSize;
    cout << "Enter the size (small, medium or large) of the car: " << endl;
    getline(cin, newSize);
    return newSize;
}
int getCc()
{
    int newCc;
    cout << "Enter the cc of the bike: " << endl;
    cin >> newCc;
    cin.ignore();
    while(newCc < 0 || newCc > 2000 || !(cin.good()))
    {
        cin.clear();               // clear error condition
        cin.ignore(100,'\n');     // remove characters)
        
        cout << "Not a valid input, please re-enter: ";
        cin >> newCc;
        cin.ignore();
    }
    return newCc;
}
void printArray(string array[], int begin, int end)
{
    for (int i = begin; i < end; i++)
    {
        cout << array[i] << endl;
    }
}