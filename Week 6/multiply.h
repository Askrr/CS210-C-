#include <string>
#include <iostream>

using namespace std;

static void MultiplicationTable() {
	// define user input
	int userNumber;
	// ask for number
	cout << "\nPlease enter any number: " << endl;
	// get users input
	cin >> userNumber;
	cout << endl;
	// show what number was entered
	cout << "\nYou entered: " << userNumber << endl;
	// for loop to print off table
	for (int i = 1; i < 11; i++) {
		cout << userNumber << " X " << i << " = " << userNumber * i << endl;
	}
}
static void DoubleValue() {
	// define user input
	int userNumber;
	// ask for number
	cout << "\nPLease enter any number: " << endl;
	// get users input
	cin >> userNumber;
	cout << endl;
	// show what number was entered
	cout << "\nYou entered: " << userNumber << endl;
	// print off number doubled
	cout << userNumber << " doubled is: " << userNumber * 2 << endl;
}
static void display() {
	cout << " _____       _            _       _             " << endl;
	cout << "/  __ |     | |          | |     | |            " << endl;
	cout << "| /  |/ __ _| | ___ _   _| | __ _| |_ ___  _ __ " << endl;
	cout << "| |    / _` | |/ __| | | | |/ _` | __/ _ || '__|" << endl;
	cout << "| |__/| (_| | | (__| |_| | | (_| | || (_) | |   " << endl;
	cout << "|_____/__,_|_||____|__,__|_|__,_||__|___/_|_|   " << endl;
	cout << endl;
}