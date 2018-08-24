/*
Spring 2018 COP2272.04 Computer Programming 1
Assignment 1
Purpose: Converts minutes to years and days
Student Name: Justin Krum
*/

#include <iostream>		//Allows for standard i/o in the program
using namespace std;	//



/**
	Calculates the number of years and days, when given a number of minutes by the user

	@param numberMinutes Number of minutes to be converted into years and days
	@return Pointer to an array storing years at index 0 and days at index 1
*/
int* getYearsDays(int numberMinutes) {
	//1 Year = 525600 Minutes
	//1 Day  = 1440 Minutes
	int numberResults[2] = { 0, 0 };
	int* pointerArray = numberResults;

	//Subtracts number of minutes in a year from numberMinutes 
	//until there is less than a year's worth of minutes in numberMinutes
	while (numberMinutes >= 525600) {
		numberMinutes -= 525600;
		numberResults[0]++;
	}

	//Subtracts number of minutes for each day
	//until there are less than a day's worth of minutes
	while (numberMinutes >= 1440) {
		numberMinutes -= 1440;
		numberResults[1]++;
	}
	
	//Returns pointer for the array of results
	return pointerArray;
}

/**
	Main method of the program

	@return Returns 0 if everything works correctly
*/
int main() {

	//Initialization of variables
	int numberMinutes = 0;

	//Prompting user for input
	cout << "Enter the number of minutes: ";
	cin >> numberMinutes;

	//Receives pointer for the array with results from getYearsDays()
	int* pointerResults = getYearsDays(numberMinutes);

	//Outputs the values to the user
	cout << numberMinutes << " minutes is approximately " << pointerResults[0] 
		 << " years and " << pointerResults[1] << " days." << endl;
	
	//Returns 0 if no problems have occured
	return 0;
}