time_t ttime = time(0);
tm* local_time = localtime(&ttime);  //////////////////////////////////////////////
int hour = local_time->tm_hour;      /// Structures the time for correct ranges ///
int minute = local_time->tm_min;     /// and only takes the parts it wants for  ///
int second = local_time->tm_sec;     /// each variable (hour/min/sec)           ///
                                     //////////////////////////////////////////////
string ampm; // To use A.M. or P.M. with the 12-hour clock. 

void worldClock() {
	if (second > 59) {
		second = 0;
		minute += 1;
	}
	if (minute > 59) {
		minute = 0;
		hour += 1;
	}
	if (hour > 24) {
		hour = 0;
		minute = 0;
		second = 0;
	}
	if (hour <= 11) {        /////////////////////////////////
		ampm = "A.M.";       /// this is added in so that  ///
	}                        /// the standard clock will   ///
	else {                   /// display the correct       ///
		ampm = "P.M.";       /// meridiem for time of day  ///
	}                        /////////////////////////////////
}

int twelveClock() {
	int hour12 = hour;      /////////////////////////////////////////////////////////////
	if (hour > 12) {        /// Hour is taken from local time in a 24 hour format so  ///
		hour12 = hour - 12; /// you have to sub 12 hours from it to get standard time ///
	}                       /////////////////////////////////////////////////////////////
	return hour12;
}

string format(int time) {               ///////////////////////////////////////////////////////////
	string format = "0";                /// formatting the time to make it a string for display ///
	if (time >= 0 && time <= 9) {       /// this way 00 doesn't print out for single numbers    ///
		format.append(to_string(time)); ///////////////////////////////////////////////////////////
	}
	else {
		format = to_string(time);
	}
	return format;
}

void display() {
	worldClock();             //////////////////////////////////////////////////
	                          /// After calling the worldClock(), hour_12 is ///
	int hour_12;              /// defined to call upon the twelveClock.      ///
	hour_12 = twelveClock();  /// This allows the printout for minutes and   ///
	                          /// seconds to be the same between the clocks  ///
	string format12;          /// but when the time goes over 12 hours on    ///
	string format24;          /// the standard clock, it will subract the    ///
	string min;               /// 12 hours from the world clock to display   ///
	string sec;               /// correctly on the standard clock.           ///
	                          //////////////////////////////////////////////////
	format24 = format(hour);     //Adding new variables to get formatting correct. 
	format12 = format(hour_12);  //Calls the hour_12 (twelveClock()) to format it to standard time. 
	min = format(minute);
	sec = format(second);

	// Displays the title, both clocks, and the Option's Menu 
	cout << setw(52) << "Chada Tech's Clock" << endl;
	cout << endl;
	cout << setw(20) << string(26, '*') << setw(30) << string(26, '*') << "  " << string(26, '*') << endl;
	cout << setw(20) << "*      12-Hour Clock     *" << setw(30) << "*      24-Hour Clock     *" << "  " << "*   1 - Add One Hour     *" << endl;
	cout << setw(1) << "*      " << format12 << ":" << min << ":" << sec << " " << ampm << "     *" << setw(11) << "*      " << format24 << ":" << min << ":" << sec << "          *" << "  " << "*   2 - Add One Minute   *" << endl;
	cout << setw(20) << string(26, '*') << setw(30) << string(26, '*') << "  " << "*   3 - Add One Second   *" << endl;
	cout << setw(84) << "*   4 - Exit             *" << endl;
	cout << setw(84) << string(26, '*') << endl;

}
