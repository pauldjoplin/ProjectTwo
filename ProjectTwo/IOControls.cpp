#include "IOControls.h"
#include <iostream>
#include <limits>

using namespace std;

// The constructor for IOControls. It prompts the user to enter all of the investment details up front. 
// Each input is validated with the getValidatedInput<T>() template method. 
// All fields will be initialized after user input. 
IOControls::IOControls()
  : initialInvestment(getValidatedInput<double>("Initial Investment Amount: $")),
    monthlyDeposit(getValidatedInput<double>("Monthly Deposit Amount: $")),
    interestRate(getValidatedInput<double>("Interest Rate %: ")),
    term(getValidatedInput<int>("Number of years: ")) {
}

//The list of getters. This allows the runProgram function to pull the values and populate the InvestmentReport constructor. 
double IOControls::GetInvestment() const {
    return initialInvestment;
}

double IOControls::GetDeposit() const {
    return monthlyDeposit;
}

double IOControls::GetRate() const {
    return interestRate;
}

int IOControls::GetTerm() const {
    return term;
}
