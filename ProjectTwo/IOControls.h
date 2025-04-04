#ifndef HEADERS_IOCONTROLS_H //Define guards per best practices. 
#define HEADERS_IOCONTROLS_H
#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

/*
 * This class is used to gather the input from the user and confirm the validity of the data entered.
 * Setters were not needed in this version of the program. The object is getting all of the data
 * it needs up front and is reconstructed on each iteration of the loop in main.
*/
class IOControls
{
public:

    IOControls(); // The default constructor.

    double GetInvestment() const; // Getters for pulling user entered data into the report class for calculation.  
    double GetDeposit() const;
    double GetRate() const;
    int GetTerm() const;

    template<typename T> // This allows for flexible input validaiton by not needing to worry about the data type it is validating for. 
    T getValidatedInput(const string& prompt);// The type is determined when the function is called. The argument is the message shown to the user and their response. 

private:

    double initialInvestment; //Private fields to store validated inputs. 
    double monthlyDeposit;
    double interestRate;
    int term;
};

template<typename T> // Template funciton definition for input validation. 
T IOControls::getValidatedInput(const string& prompt) {
    T value;
    string input;
    bool valid; // Declared to keep the loop running so long as it is valid. 

    do {
        valid = true;

        try {
            cout << prompt;
            getline(cin, input);

            // Checks if user just hit Enter with no value entered. 
            if (input.empty()) {
                throw runtime_error("Input cannot be blank. Please enter a value.");
            }

            // Creates a string stream and attempts to extract int/double from the string.See more in IOControls.cpp.
            stringstream ss(input);
            ss >> value;

            // Fails if extraction fails or value is not positive or characters are after the number.
            if (ss.fail() || value < 0 || !ss.eof()) {
                throw runtime_error("Invalid input. Please enter a positive number.");
            }
        }
        catch (const runtime_error& e) { // If a error is hit, this is called and the appropriate error is displayed. 
            cerr << "Error: " << e.what() << endl;
            valid = false;
        }

    } while (!valid);

    return value;
}


#endif
