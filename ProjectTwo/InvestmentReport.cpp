#include "InvestmentReport.h"

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// This helper function formats the monetary values with 2 decimal places. This can be used instead of adjusting each output. 
string formatAmount(double value) {
    ostringstream oss;
    oss << fixed << setprecision(2) << value;
    return oss.str();
}

// Constructor that populates the report with user-entered data.
InvestmentReport::InvestmentReport(double initInvest, double monthDeposit, double interestRate, int term)
    : initialInvestment(initInvest), monthlyDeposit(monthDeposit), annualInterestRate(interestRate), years(term) {}

// Displays the annual interest and balances WITHOUT the monthly deposits. 
void InvestmentReport::DisplayWithoutMonthlyDeposit() const {
    double balance = initialInvestment;
    const int col1Width = 6;
    const int col2Width = 20;
    const int col3Width = 26;

    // Displays the header. It uses formatting to ensure the labels are centered and aligned with the values below. 
    cout << "\n  Balance and Interest Without Additional Monthly Deposits\n";
    cout << "  " << string(col1Width + col2Width + col3Width, '=') << "\n";

    cout << "  "
        << setw(col1Width) << right << "Year"
        << setw(col2Width) << right << "Year End Balance"
        << setw(col3Width) << right << "Year End Earned Interest" << endl;

    cout << "  "
        << string(col1Width + col2Width + col3Width, '-') << "\n";

    // This loop runs the calculation until it reaches the number of years the user submitted. 
    // It is formatted to stay aligned with the labels. 
    for (int year = 1; year <= years; ++year) {
        double interest = balance * (annualInterestRate / 100.0);
        balance += interest;

        cout << right << setw(6) << year
            << setw(18) << "$" + formatAmount(balance)
            << setw(26) << "$" + formatAmount(interest) << endl;
    }
}

// Displays the annual interest and balances WITH the monthly deposits. 
void InvestmentReport::DisplayWithMonthlyDeposit() const {
    double balance = initialInvestment;
    const int col1Width = 6;
    const int col2Width = 20;
    const int col3Width = 26;

    cout << "\n  Balance and Interest With Additional Monthly Deposits\n";
    cout << "  " << string(col1Width + col2Width + col3Width, '=') << "\n";

    cout << "  "
        << setw(col1Width) << right << "Year"
        << setw(col2Width) << right << "Year End Balance"
        << setw(col3Width) << right << "Year End Earned Interest" << endl;

    cout << "  "
        << string(col1Width + col2Width + col3Width, '-') << "\n";

        // This loop runs the calculation until it reaches the number of years the user submitted. 
        // It is formatted to stay aligned with the labels. 
        for (int year = 1; year <= years; ++year) {
        double yearlyInterest = 0.0;

        //This loop adds the sum of 12 months together.
        for (int month = 0; month < 12; ++month) {
            balance += monthlyDeposit;
            double monthlyInterest = balance * (annualInterestRate / 100.0) / 12.0;
            balance += monthlyInterest;
            yearlyInterest += monthlyInterest;
        }

        cout << right << setw(6) << year
            << setw(18) << "$" + formatAmount(balance)
            << setw(26) << "$" + formatAmount(yearlyInterest) << endl;
    }
}
