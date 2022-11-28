#include "UserInput.h"

using namespace std;

void UserInput::SetInitialDeposit(double initialDeposit) {   ////////////////////////////////////////////////////////
	initial = initialDeposit;                                // Setters and Getters for the UserInput class in the //
}                                                            // UserInput.h file. These allow for the private      //
void UserInput::SetMonthlyDeposit(double monthlyDeposit) {   // variables to be called and used in the rest of the //
	monthly = monthlyDeposit;                                // program while using AirGeads security standards    //
}                                                            ////////////////////////////////////////////////////////
void UserInput::SetInterestRate(double interestRate) {
	interest = interestRate;
}
void UserInput::SetNumYears(int numYears) {
	years = numYears;
}
double UserInput::GetInitialDeposit() const {
	return initial;
}
double UserInput::GetMonthlyDeposit() const {
	return monthly;
}
double UserInput::GetInterestRate() const {
	return interest;
}
int UserInput::GetNumYears() const {
	return years;
}