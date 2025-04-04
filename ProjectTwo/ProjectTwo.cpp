/*
* Paul Joplin
* 04/01/25
* Project Two
* CS 210
* 
* The purpose of this program is to prompt the user for an initial investment, a recurring deposit if they choose one, their annual interest rate, and 
* the number of years they tend to invest in to. The program will then run calculations and display two reports on how their money will grow over time
* with the total they deposited for the year, added to the interest and then given a total balance for the year. This project is a collection of concepts 
* that have been obsereved and applied leading up to this point. It takes input validation to an elevated level compared to the clock application. With 
* research combined with feedback from QA, new techniques were deployed. The sstream in combination with stdexcept and typename allowed for me to check if anything other than 
* a numerical value was in the entry field. This is an improvement over previous projects where instead of ignoring eveything after the correct input, it will now throw an error. 
* 
* The program uses an object-oriented approach for easier maintenance for future updates and readability. 
* 
* The client did not request additional functionality. However, it would be possible and practical to implement the ability to save generated reports to a file on the user's local machine.
*/


#include <iostream>

//Header files for input control and calculating. 
#include "IOControls.h"
#include "InvestmentReport.h"

using namespace std;

//This function displays the banner at program start. It serves no functional purpose, just a design detail. 
//I had considered moving this to a seperate source file, but figured that was not needed.
static void bankBanner() {
    cout << "                              /************************************************************\\" << endl;
    cout << "                               *                                                          *" << endl;
    cout << "                               *                    AIRGEAD BANKING                       *" << endl;
    cout << "                               *                                                          *" << endl;
    cout << "                               *                 \"Your Community Bank\"                    *" << endl;
    cout << "                               *                                                          *" << endl;
    cout << "                              \\************************************************************/" << endl;
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                           Welcome to our interest calculator!                                            " << endl;
    cout << "                                      Get started below by following the prompts." << endl;
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl << endl;
    cout << " ***********************************************************************************************************************";
    cout << " **************************************************** Data Input *******************************************************" << endl << endl;
}

//This function contains the main loop of the program.
void runProgram() {
    
    char choice; //Used for y/n choice.

    //This do/while loop will initiate on start and then run again if the user enters 'y' to run another report.  
    do {

#ifdef _WIN32 
        system("cls"); //This clears the console if the user is in Windows.
#else
        cout << "\033[2J\033[1;1H"; // This clears the console if the user is in a UNIX OS, I am not sure what QA uses to test with. 
#endif
        cout << "\033[1;32m"; //Sets the text to green in the console to match the client's vision.
        bankBanner(); //Displays the banner after the console is cleared. 
        
        cout << "After each entry, press Enter to continue..." << endl;
        IOControls input; //IOControls Class is called, beginning the prompts.

        InvestmentReport report( //InvestmentReport Class is called, gathering the information from IOControls and running the calculations. 
            input.GetInvestment(),
            input.GetDeposit(),
            input.GetRate(),
            input.GetTerm()
        );

        //Displays the reports requested by the client. 
        report.DisplayWithoutMonthlyDeposit();
        report.DisplayWithMonthlyDeposit();

        //This loop do/while loop will run until a user enters y/n. For input validation purposes.      
        do {
            cout << "\nWould you like to enter new values? (y/n).  This will clear the previous report: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            choice = tolower(choice); //converts the answer to lowercase for QOL. 

            if (choice != 'y' && choice != 'n') {
                cout << "Invalid input. Please enter 'y' or 'n'.\n";
            }

        } while (choice != 'y' && choice != 'n');

    } while (choice == 'y');

}

//Main function with minimal code contained within it, per the company standards. 
int main() {

    runProgram();

    return 0;
}
