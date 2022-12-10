//////////////////////////////////////
//   Benjamin Leanna || SNHU CS210  //
//----------------------------------//
//          Week 5 - Project 2      ///////////////////////////////////////////////////////////////
//_______________________________________________________________________________________________//
//      __                                             ____                                      //
//      / |    ,                               /       /   )                /      ,             //
//     /__|       )__    __    __    __    __ /       /__ /     __    __   / __        __    __  //
//    /   |  /   /   ) /   ) /___) /   ) /   /       /    )   /   ) /   ) /(     /   /   ) /   ) //
//   /    | /   /     (___/ (___  (___( (___/       /____/   (___( /   / /  |   /   /   / (___/  //
//                       /                                                                   /   //
//                   (_ /                                                                (_ /    //
//-------------------------------Compound Interest Calculator------------------------------------//
///////////////////////////////////////////////////////////////////////////////////////////////////
#include "UserInput.h"
using namespace std;
UserInput newUser;

///////////////////////////////////////////////////////////////////////////
//Main function takes the newUser to get all inputs and to show displays.//
//Everything is difined in sidecar files and a header.                   //
///////////////////////////////////////////////////////////////////////////
int main() {
	newUser.GetUserInputs(newUser.GetInitialDeposit(), newUser.GetMonthlyDeposit(), newUser.GetInterestRate(), newUser.GetNumYears());
	newUser.NoMonthlyDeposit(newUser.GetInitialDeposit(), newUser.GetInterestRate(), newUser.GetNumYears());
	newUser.WithMonthlyDeposit(newUser.GetInitialDeposit(), newUser.GetMonthlyDeposit(), newUser.GetInterestRate(), newUser.GetNumYears());
}