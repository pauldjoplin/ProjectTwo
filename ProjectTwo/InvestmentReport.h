#ifndef HEADERS_INVESTMENT_REPORT_H //Define guards per best practices. 
#define HEADERS_INVESTMENT_REPORT_H
#pragma once

// This class does the intake of the user inputs and runs the calculations.
// It also displays the final reports with some styling. 
class InvestmentReport
{
public: 
	// This constructor initializes the report with all necessary values. 
	InvestmentReport(double initInvest, double monthlyDeposit,
		double annualInterestRate, int years);

	void DisplayWithoutMonthlyDeposit() const; // Displays the report without monthly deposits.
	void DisplayWithMonthlyDeposit() const; // Displays the report with monthly deposits. 

private:
	double initialInvestment;
	double monthlyDeposit;
	double annualInterestRate;
	int years;
};
#endif