/////////////////////////////////////////////////
// Benjamin Leanna -- Project 3 "Corner Grocer //
//      December 9th, 2022 -- SNHU CS210       //
/////////////////////////////////////////////////

#include "Menu.h"

using namespace std;
//////////////////////////////////////////////////
// Main() function will call menu from header   //
// file and that will calculate the rest of the //
// required functions of the program            //
//////////////////////////////////////////////////
int main()
{

	try
	{
		menu();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
		cout << "Error occurred";
		system("pause");
	}

}