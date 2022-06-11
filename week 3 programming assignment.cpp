// week 3 programming assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

//using namespace
using namespace std;

int main()
{
    //declare the constants 
    const int headerlen = 50;
    const string OUTPUTFILENAME = "order.txt";
    //declare the variables
    ofstream output_D;
    string item, Fragile, destination;
    double ShippingCost = 0.0;
    double OrderTotal;

    //the welcome message for the program and intro
    string sTitle = "ITCS 2530 - Programming Assignment for week #3";
    int iTitleLen = static_cast<int>(sTitle.length()); //Quell compiler warning. 

    //calculating and creating a variable
    int iFillLen = headerlen - iTitleLen;
    int iFillLenHalf = iFillLen / 2;
    string strFill(iFillLenHalf, '.');

    cout << setfill('.');
    cout << setw(headerlen) << "." << endl;
    //static_cast to quell compiler warning 
    cout << setw(static_cast<std::streamsize>(iTitleLen)) << right << sTitle << endl;
    cout << setw(headerlen) << "." << endl << endl;
    //reseting the setfill
    cout << setfill(' ');

    //taking the users input 
    cout << "Please enter the item name (no spaces)" << setw(12) << setfill('.') << ":";
    cin >> item;
    char fragile;
    cout << "Is the item fragile? (y=yes/n=no)" << setw(17) << setfill('.') << ":";
    cin >> fragile;
    if (fragile == 'y' || fragile == 'Y')
    {
        ShippingCost += 2;
    }
    else if (fragile != 'n' || fragile != 'N')
    {
        cout << "\nInvalid entry, exiting" << endl;
        return 0;
    }

    cout << "Please enter your order total" << setw(21) << setfill('.') << ":";
    cin >> OrderTotal;
    cout << "Please enter destination. (usa/can/aus/mars)" << setw(11) << setfill('.') << ":";
    cin >> destination;
    if (destination != "usa" && destination != "can" && destination != "aus" && destination != "mars")
    {
        cout << "\nInvalid entry, exiting";
        return 0;
    }
    //the input changed to upper case 
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
    transform(item.begin(), item.end(), item.begin(), ::toupper);
    //shipping cost for the destinations
    if (destination == "USA")
    {
        if (OrderTotal < 50.00)
            ShippingCost += 6.00;
        else if (OrderTotal < 50.00 || OrderTotal < 100.01)
            ShippingCost += 9.00;
        else if (OrderTotal < 100.00 || OrderTotal < 150.01)
            ShippingCost += 12.00;
        else
            ShippingCost = 0.0;
    }
    if (destination == "CAN")
    {
        if (OrderTotal < 50.00)
            ShippingCost += 8.00;
        else if (OrderTotal < 50.00 || OrderTotal < 100.01)
            ShippingCost += 12.00;
        else if (OrderTotal <= 100.00 || OrderTotal < 150.01)
            ShippingCost += 15.00;
        else
            ShippingCost = 0.0;
    }
    if (destination.compare("AUS") == 0)
    {
        if (OrderTotal < 50.00)
            ShippingCost += 10.00;
        else if (OrderTotal < 50.00 || OrderTotal < 100.01)
            ShippingCost += 14.00;
        else if (OrderTotal <= 100.00 || OrderTotal < 100.01)
            ShippingCost += 17.00;
        else
            ShippingCost = 0.0;
    }
    if (destination.compare("MARS") == 0)
    {
        if (OrderTotal < 50.00)
            ShippingCost += 15.00;
        else if (OrderTotal < 50.00 || OrderTotal < 100.01)
            ShippingCost += 16.00;
        else if (OrderTotal <= 100.00 || OrderTotal < 100.01)
            ShippingCost += 20.00;
        else
            ShippingCost = 0.0;
    }

    //stores the outputs in a file
    output_D.open(OUTPUTFILENAME);
    //the results after the user enters the input 
    output_D << "\nYour item is" << setw(35) << setfill('.') << item << endl;
    cout << "\nYour item is" << setw(35) << setfill('.') << item << endl;

    output_D << "Your shipping cost is" << setw(25) << setfill('.') << "$" << ShippingCost << ".00" << endl;
    cout << "Your shipping cost is" << setw(25) << setfill('.') << "$" << ShippingCost << ".00" << endl;

    output_D << "You are shipping to" << setw(29) << setfill('.') << destination << endl;
    cout << "You are shipping to" << setw(29) << setfill('.') << destination << endl;
    double total = ShippingCost + OrderTotal;

    output_D << "Your total shipping costs are" << setw(17) << setfill('.') << "$" << fixed << setprecision(2) << total << endl;
    cout << "Your total shipping costs are" << setw(17) << setfill('.') << "$" << fixed << setprecision(2) << total << endl;

    output_D << endl << setw(54) << setfill('-') << "Thank You\n" << endl;
    cout << endl << setw(54) << setfill('-') << "Thank You" << endl;
    return 0;

}