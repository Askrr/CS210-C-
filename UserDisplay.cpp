#include "UserInput.h"
#include <iomanip>

using namespace std;
///////////////////////////////////////////////////////////////
// This will first show everthing that the user will see and //
// Then updates all the valcues to the default at the start  //
///////////////////////////////////////////////////////////////
int UserInput::ShowUserDisplay(double initialDeposit, double monthlyDeposit, double interestRate, int numYears) {
	cout << "____________________________________________________________________________________________" << endl;
	cout << "     __                                             ____                                    " << endl;
	cout << "    / |    ,                               /       /   )                /      ,            " << endl;
	cout << "   /__|       )__    __    __    __    __ /       /__ /     __    __   / __        __    __ " << endl;
	cout << "  /   |  /   /   ) /   ) /___) /   ) /   /       /    )   /   ) /   ) /(     /   /   ) /   )" << endl;
	cout << " /    | /   /     (___/ (___  (___( (___/       /____/   (___( /   / /  |   /   /   / (___/ " << endl;
	cout << "                     /                                                                   /  " << endl;
	cout << "                 (_ /                                                                (_ /   " << endl;
	cout << "-----------------------------Compound Interest Calculator-----------------------------------" << endl;
	cout << fixed << setprecision(2);
	cout << "********************************************************************************************" << endl;
	cout << "*********************************** User Inputs: *******************************************" << endl;
	cout << "                         Initial Deposit Amount: $" << initialDeposit << endl;
	cout << "                         Monthly Deposit Amount: $" << monthlyDeposit << endl;
	cout << fixed << setprecision(1);
	cout << "                         Annual Interest Rate: " << interestRate << endl;
	cout << fixed << setprecision(0);
	cout << "                         Number of years to calculate: " << numYears << endl;
	cout << "********************************************************************************************" << endl;
	cout << "********************************************************************************************" << endl;
	return 0;
}
///////////////////////////////////////////////////////////////////////
// After the main display is shown, the GetUserInputs will then      //
// Get all the inputs needed from the user. This involes implementing//
// A try/catch to get the correct information from the user and if   //
// Invalid information is entered, then an error will display.       //
// This will also refresh the screen after each input so the user can//
// See what they are entering as they go.                            //
///////////////////////////////////////////////////////////////////////
int UserInput::GetUserInputs(double initialDeposit, double monthlyDeposit, double interestRate, int numYears) {
	UserInput userInput{};
	while (true) {
		try {
			userInput.ShowUserDisplay(initialDeposit, monthlyDeposit, interestRate, numYears);
			cout << "\nEnter Initial Deposit Amount: \n$";
			std::cin.clear();
			cin >> initialDeposit;
			if (initialDeposit <= 0) {
				throw 1;
			}
			UserInput::SetInitialDeposit(initialDeposit);
			system("CLS");

			userInput.ShowUserDisplay(initialDeposit, monthlyDeposit, interestRate, numYears);
			cout << "\nEnter Monthly Deposit: \n$";
			cin >> monthlyDeposit;
			if (monthlyDeposit <= 0) {
				throw 2;
			}
			UserInput::SetMonthlyDeposit(monthlyDeposit);
			system("CLS");

			userInput.ShowUserDisplay(initialDeposit, monthlyDeposit, interestRate, numYears);
			cout << "\nEnter Annual Interest Rate: \n ";
			cin >> interestRate;
			if (interestRate <= 0) {
				throw 3;
			}
			UserInput::SetInterestRate(interestRate);
			system("CLS");

			userInput.ShowUserDisplay(initialDeposit, monthlyDeposit, interestRate, numYears);
			cout << "\nEnter Number of Years to Calculate: \n";
			cin >> numYears;
			if (numYears <= 0) {
				throw 4;
			}
			UserInput::SetNumYears(numYears);
			system("CLS");

			userInput.ShowUserDisplay(initialDeposit, monthlyDeposit, interestRate, numYears);
			system("pause");
			system("CLS");
			break;
		}
		catch (...) {
			std::cin.clear();                                                   ///////////////////////////////////////////////////////////////////////////////////////////////
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // The cin.ignore() statement takes all character in the input stream and discards           //
			cout << "You have to enter a number above zero." << endl;           // them until it reaches a newline character, which is then discards as well.                //
			system("pause");                                                    // By using the integral value defined by the numberic_limits::max(), the ignore call will   //
			system("CLS");                                                      // ignore characters with no limit until it get tot he deliminator or EOF. Remember: have to //
		}                                                                       // include the limits library in order to use this value.                                    //
	}                                                                           ///////////////////////////////////////////////////////////////////////////////////////////////
	return 0;
}