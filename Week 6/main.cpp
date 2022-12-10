
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include "multiply.h"

using namespace std;

int main(){
	//main menu input option
	int input = 0;
	while (input != 3) {
		display();
		cout << "1: Display a Multiplication Table" << endl;
		cout << "2: Double a Value" << endl;
		cout << "3: Exit" << endl;
		cout << endl;
		cin >> input;
			switch (input) {
			case 1: if (input == 1) {
				MultiplicationTable();
			}

				  // case 2 returns a number X 2
			case 2: if (input == 2) {
				DoubleValue();
			}
				  // exit the program if the input is 3
			case 3: if (input == 3) {
				cout << "Exiting Program, Goodbye." << endl;
			}
				  // error checking for number input to make sure input stays between 1-3 and is an integer.
			default: if ((input < 1) || (input > 3)) {
				system("CLS");
				main();
				system("pause");
				system("CLS");
			}
		}
	}
}

