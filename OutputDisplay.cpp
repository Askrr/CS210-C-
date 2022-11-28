#include "UserInput.h"
#include <iomanip>

using namespace std;
/////////////////////////////////////////
//Dipslay Without the monthly deposits//
/////////////////////////////////////////
double UserInput::NoMonthlyDeposit(double initialDeposit, double interestRate, int numYears){
	int i;
	double yearlyInterest;
	double yearlyBalance = initialDeposit;

	cout << "____________________________________________________________________________________________" << endl;
	cout << "     __                                             ____                                    " << endl;
	cout << "    / |    ,                               /       /   )                /      ,            " << endl;
	cout << "   /__|       )__    __    __    __    __ /       /__ /     __    __   / __        __    __ " << endl;
	cout << "  /   |  /   /   ) /   ) /___) /   ) /   /       /    )   /   ) /   ) /(     /   /   ) /   )" << endl;
	cout << " /    | /   /     (___/ (___  (___( (___/       /____/   (___( /   / /  |   /   /   / (___/ " << endl;
	cout << "                     /                                                                   /  " << endl;
	cout << "                 (_ /                                                                (_ /   " << endl;
	cout << "-----------------------------Compound Interest Calculator-----------------------------------" << endl;
	cout << "               Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "============================================================================================" << endl;
	cout << "    Year           Year End Balance             Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;

	for (i = 1; i <= numYears; i++) {                              ////////////////////////////////////////////
		yearlyInterest = yearlyBalance * ((interestRate / 100));   //Loop to do math WITHOUT monthly deposits//
		yearlyBalance = yearlyBalance + yearlyInterest;            ////////////////////////////////////////////

		cout << setprecision(2) << setw(6) << i << " " << setw(19) << "$" << 0.00 + yearlyBalance << " " << setw(23) << "$" << yearlyInterest << "\n" << endl;
	}
	system("pause");
	system("CLS");
	return 0;
}
/////////////////////////////////
//Display WITH montly desposits//
/////////////////////////////////
double UserInput::WithMonthlyDeposit(double initialDeposit, double monthlyDeposit, double interestRate, int numYears) {
	int i;
	int j;
	double yearlyInterest;
	double monthlyInterest;
	double monthlyBalance = initialDeposit;
	double yearlyBalance = initialDeposit;
	const int months = 12;

	cout << "____________________________________________________________________________________________" << endl;
	cout << "     __                                             ____                                    " << endl;
	cout << "    / |    ,                               /       /   )                /      ,            " << endl;
	cout << "   /__|       )__    __    __    __    __ /       /__ /     __    __   / __        __    __ " << endl;
	cout << "  /   |  /   /   ) /   ) /___) /   ) /   /       /    )   /   ) /   ) /(     /   /   ) /   )" << endl;
	cout << " /    | /   /     (___/ (___  (___( (___/       /____/   (___( /   / /  |   /   /   / (___/ " << endl;
	cout << "                     /                                                                   /  " << endl;
	cout << "                 (_ /                                                                (_ /   " << endl;
	cout << "-----------------------------Compound Interest Calculator-----------------------------------" << endl;
	cout << "                  Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "============================================================================================" << endl;
	cout << "    Year           Year End Balance             Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;

	for (i = 1; i <= numYears; i++) {                                             //////////////////////////////////
		yearlyInterest = 0;                                                       // Loop to do math with monthly //
		for (j = 1; j <= months; j++) {                                           // deposits ------------------- //
			monthlyInterest = 0;                                                  //////////////////////////////////
			monthlyBalance = monthlyBalance + monthlyDeposit;
			monthlyInterest = (monthlyBalance * ((interestRate / 100) / months));
			yearlyInterest = yearlyInterest + monthlyInterest;
			monthlyBalance = monthlyBalance + monthlyInterest;
		}
		cout << setprecision(2) << setw(6) << i << " " << setw(19) << "$" << 0.00 + monthlyBalance << " " << setw(20) << "$" << yearlyInterest << "\n" << endl;
	}
	system("pause");
	system("CLS");
	return 0;
}