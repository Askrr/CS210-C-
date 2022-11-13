/////////////////////////////////////////////////
/// Benjamin Leanna                           ///
/// CS210 - Week 3 Project - Chada Tech Clock ///
///////////////////////////////////////////////// 

//Standard library facilities:
#include <iostream> // Standard input/output stream objects
#include <iomanip>  // Parametric manipulators (including setw())
#include <string>   // Introduces string types, character traits and a set of converting functions
#include <Windows.h>// Includes all functions in the Windows API  
#include <conio.h>  // Console Input Output header file. 
#include <chrono>   // Time library under the std::chrono namespace. Purations, Time Points, and Clocks
#include <thread>   // declares the thread class and the this_thread namespace. 

using namespace std;
// Includes the clock displays header file to define everything main() needs
#include "clockDisplays.h"  

int main() {															       //////////////////////////////////////////////////////////////////
	int choice = 0;														       /// In the main function, kbhit will return a non-zero integer ///
	int flag = 0;															   /// if a key is in the keyboard buffer. It will not wait for a ///
	while (choice != 4) {												   	   /// key to be pressed. This allows the program to continue to  ///
		while (!kbhit() && flag == 0) {										   /// refresh itself while the user makes a choice for input.    ///
			system("cls");													   /// system("cls") clears the screen then calls the display()   ///
			display();														   /// again to update to the new time while adding a second in   ///
			second++;                                                          /// between each refresh. sleep_for will delay the adding of   ///                                           
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));      /// the second to not let the clock speed up past real time    ///
			main();                                                            //////////////////////////////////////////////////////////////////
		}
		cin >> choice;

		switch (choice) {                //////////////////////////////////////////////////////
		case 1:                          /// Standard switch statement for each menu option ///
			hour = hour + 1;             /// For each case since the sleep timer is 1000    ///
			second = second - 1;         /// and the timer never stops, so you have to sub  ///
		case 2:                          /// one second for each choice so the time doesn't ///
			minute = minute + 1;         /// get out of alignment.                          ///
			second = second - 1;         //////////////////////////////////////////////////////
		case 3:
			second = second + 1;
		}
		

	}
	cout << "Exiting Program, Goodbye." << endl;

	exit(0);
}
