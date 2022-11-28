                      /////////////////////////////////////
#ifndef TOP_DISPLAY_H  // These header guards prevent re- //
#define TOP_DISPLAY_H  // declaration of any identifiers  //
                      /////////////////////////////////////
#include <string>
#include <iostream>

using namespace std;

class UserInput {
public:
    void SetInitialDeposit(double initialDeposit); //Set the initial deposit amount
    void SetNumYears(int numYears);                //Set the number of years to calculate
    void SetInterestRate(double interestRate);     //Set the yearly interest rate
    void SetMonthlyDeposit(double monthlyDeposit); //Set the monthly deposit amount
    double GetInitialDeposit() const;              //Get the initial deposit amount
    int GetNumYears() const;                       //Get the number of years to calculate
    double GetInterestRate() const;                //Get the yearly interest rate
    double GetMonthlyDeposit() const;              //Get the monthly deposit amount
    int GetUserInputs(double initialDeposit, double monthlyDeposit, double interestRate, int numYears);         //Get all the user inputs
    int ShowUserDisplay(double initialDeposit, double monthlyDeposit, double interestRate, int numYears);       //Set all the user inputs
    double NoMonthlyDeposit(double initialDeposit, double interestRate, int numYears);                          //What to show without monthly deposits
    double WithMonthlyDeposit(double initialDeposit, double monthlyDeposit, double interestRate, int numYears); //What to show with monthly deposits
private:
    double initial;   /////////////////////
    double monthly;   //Private variables//
    double interest;  /////////////////////
    int years;
};
#endif //TOP_DISPLAY_H//