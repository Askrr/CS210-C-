#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <istream>

using namespace std;

bool validOption(int option) {
	////////////////////////////////////////////////////////
	// This fuction is checking for a valid option choice //
	// If the option is not 1, 2, 3, or 4, then an error  //
	// occurs. This will catch for unusual entries then   //
	// such as letters or special characters. The entry   //
	// needs to be a specific number to be allowed.       //
	////////////////////////////////////////////////////////
	vector<int> validOptions = { 1,2,3,4 };
	for (int item : validOptions) {
		if (item == option) {
			return true;
		}
	}
	cout << "\nNot a valid option, please try again.\n" << endl;
	return false;
}

void menu() {
	ifstream inFS;
	ofstream outFS;
	string fileWord;
	string item_name;
	int item_frequency;
	vector<string> item_list;
	vector<int> frequencyList;
	bool menuLoop = true;
	int frequencyWidth;
	while (menuLoop) {
		// menu loop
		cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "// 1: List of all items purchased and how many times each was purchased.                                    //" << endl;
		cout << "// 2. Select an item to view how many times it was purchased.                                               //" << endl;
		cout << "// 3. Generate a a file and a text-based histogram displaying each item and how many times it was purchased.//" << endl;
		cout << "// 4. Exit.                                                                                                 //" << endl;
		cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << endl;
		cout << "Please select and option: " << endl;
		int option;
		cin >> option;
		string item;

		if (validOption(option)) {
			////////////////////////////////////////
			// This first section will find the   //
			// Items and thier frequencies and    //
			// then print them off. This needs to //
			// be deleted afterwards so when      //
			// after if you choose another option //
			// it doesnt start making multiple    //
			// lines and copies.                  //
			////////////////////////////////////////
			if (option == 1) {
				cout << "List of all items purchased and their frequency: " << endl;
				inFS.open("frequency.dat");
				if (!inFS.is_open()) {
					cout << "Unable to open the file!" << endl;
				}
				inFS >> item_name;
				inFS >> item_frequency;
				while (!inFS.fail()) {
					item_list.push_back(item_name);
					frequencyList.push_back(item_frequency);
					inFS >> item_name;
					inFS >> item_frequency;
				}
				for (int i = 0; i < item_list.size(); i++) {
					cout << item_list.at(i) << " " << frequencyList.at(i) << endl;
				}
				inFS.close();
				cout << endl;
				system("pause");
				break;
			}
			//////////////////////////////////////
			// This option just wants to output //
			// A selected item and its quantity //
			// so the first loops will check if //
			// the word is in the list of items //
			// then it will find that items     //
			// index number and reference the   //
			// frequency list and print off the //
			// number of that item at the same  //
			// index number of inputted item.   //
			//////////////////////////////////////
			else if (option == 2) {
				cout << "Enter a specific item to view how many times it was purchased: " << endl;
				cin >> item;
				cout << endl;
				inFS.open("frequency.dat");
				if (!inFS.is_open()) {
					cout << "Unable to open the file!" << endl;
				}
				inFS >> item_name;
				inFS >> item_frequency;
				while (!inFS.fail()) {
					item_list.push_back(item_name);
					frequencyList.push_back(item_frequency);
					inFS >> item_name;
					inFS >> item_frequency;
				}
				inFS.close();
				if (std::find(item_list.begin(), item_list.end(), item) != item_list.end()) {
					cout << item << ": ";
					int itemIndex = distance(item_list.begin(), find(item_list.begin(), item_list.end(), item));
					cout << frequencyList[itemIndex];
				}

				cout << endl;
				system("pause");
				break;
			}
			/////////////////////////////////////
			// This section will make the file //
			// then print off the frequency    //
			// list and then make a text based //
			// histogram printoff as well.     //
			/////////////////////////////////////
			else if (option == 3) {
				cout << "Creating file and histogram of each item and their frequency: " << endl;
				cout << endl;
				inFS.open("frequency.dat");
				if (!inFS.is_open()) {
					cout << "Unable to open the file!" << endl;
				}
				inFS >> item_name;
				inFS >> item_frequency;
				while (!inFS.fail()) {
					item_list.push_back(item_name);
					frequencyList.push_back(item_frequency);
					inFS >> item_name;
					inFS >> item_frequency;
				}
				for (int i = 0; i < item_list.size(); i++) {
					cout << item_list.at(i) << " " << frequencyList.at(i) << endl;
				}
				cout << endl;
				cout << "---Text-Based Histogram---" << endl;
				cout << endl;
				/////////////////////////////////////
				// This spacing makes it so that   //
				// the histogram (horizontal) will //
				// be formatted correctly ........ //
				/////////////////////////////////////
				for (int i = 0; i < item_list.size(); i++) {
					frequencyWidth = frequencyList.at(i) + 1;
					size_t spacing = 12 - item_list[i].length();
					cout << item_list.at(i);
					std::cout << std::string(spacing, ' ');
					cout << setfill('*') << setw(frequencyWidth) << " " << endl;
				}
				if (!inFS.eof()) {
					cout << "Input failure before reaching the end of the file" << endl;
				}
				cout << "closing frequency.dat file..." << endl;
				inFS.close();
				system("pause");
				break;
			}
			else if (option == 4) {
				menuLoop = false;
				cout << "//////////////////////////////////////" << endl;
				cout << "//           Exiting Program        //" << endl;
				cout << "//////////////////////////////////////" << endl;
				break;
			}
			else {
				break;
			}
		}
	}
	cout << endl;
}