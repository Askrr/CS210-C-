//////////////////////////////////////////
/// Benjamin Leanna - Week 4 Assigment ///
/// Read File, Convert F to C temps    ///
/// and Write back to new file.        ///
/// Nov. 20th, 2022                    ///
//////////////////////////////////////////

#include <string>    //Allows for string manipulation
#include <iostream>  //Allowing for input/output operations
#include <fstream>   //Input/Output stream calss to operate on files.
#include <vector>    //Defines the vector container class
#include <stdlib.h>   //C Standard gneral utilities library (allows use of system("pause")
using namespace std;
////////////////////////////
// Define a conversion    //
// fuction to change temps//
// from F to C            //
////////////////////////////
void convertTemps(int &temperature) {
	temperature = ((double)temperature - 32.0) * (5.0 / 9.0);
}
int main() {
	// Main function called//

	//////////////////////////
	//First we need to make //
	//in and out variables  //
	//////////////////////////
	ifstream inFS;
	ofstream outFS;
	//////////////////////////
	//Next, make vars for   //
	//the cities/numbers    //
	//and the vectors to    //
	//hold both of them.    //
	//////////////////////////
	string cityName;
	int cityTemp;
	vector<string> cityVector;
	vector<int> tempVector;
	//////////////////////////
	//Next we will open the //
	//File to read          //
	//////////////////////////
	inFS.open("FahrenheitTemperature.txt");
	//////////////////////////
	//Next,check to make    //
	//sure the file is open //
	//////////////////////////
	if (!inFS.is_open()) {
		cout << "FahrenheitTemperature.txt was unable to open!!" << endl;
		return 1;
	}
	//////////////////////
	//Next, read file   //
	//////////////////////
	inFS >> cityName;
	inFS >> cityTemp;
	while (!inFS.fail()) {
		//////////////////////
		//Add to vector now //
		//////////////////////
		cityVector.push_back(cityName);
		tempVector.push_back(cityTemp);
		inFS >> cityName;
		inFS >> cityTemp;
	}
	//////////////////////
	//Check to see that //
	//no eof() error    //
	//////////////////////
	if (!inFS.eof()) {
		cout << "Input failure before reaching the end of file." << endl;
	}
	//////////////////////
	//Closing file      //
	//////////////////////
	inFS.close();
	////////////////////////////
	// Next, the program is   //
	// going to pause. This   //
	// will make the user have//
	// to hit a key to cont-  //
	// inue the next part of  //
	// the program to write   //
	////////////////////////////
	system("pause");
	////////////////////////////
	// Now that the first file//
	// is read, we want to    //
	// open the 2nd file and  //
	// write the new temps    //
	////////////////////////////
	outFS.open("CelsiusTemperature.txt");
	////////////////////////////
	//Again, check that file  //
	//has opened properly     //
	////////////////////////////
	if (!outFS.is_open()) {
		cout << "CelsiusTemperature.txt was unable to open" << endl;
		return 1;
	}
	//////////////////////////////
	//A loop will now go through//
	//each element of the vector//
	//and print into the C file //
	//while converting the #s   //
	//////////////////////////////
	for (int i = 0; i < cityVector.size(); i++) {
		convertTemps(tempVector.at(i));
		outFS << cityVector.at(i) << " " << tempVector.at(i) << endl;
	}
	///////////////////
	//Close the file!//
	///////////////////
	outFS.close();
	return 0;
}