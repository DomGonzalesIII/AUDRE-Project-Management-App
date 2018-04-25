/* ---------------------------------------------------------------------------
This is main for my course project, the 'AUDRE' Project Management App (AUDRE 
stands for add, update, delete, report, exit). I use a combination of methods, 
class calls, and objects throughout the full program.

Developer:		Domingo Gonzales III
Date Written:	3/4/18
Last Updated:	4/14/18
------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <fstream>
#include "Job.h"
using namespace std;

// method prototypes
void addJob();
void updateJob();
void deleteJob();

// variables
char userChoice = ' ', wireType;
string typeOfWire;
int refNum;
double feetOfWire, wireCost, laborCost;

// file job information will be written to
const char FileName[] = "\\\\acad.dvuadmin.net\\sce\\HOMEDIR\\D40840958\\Documents\\Visual Studio 2015\\Projects\\CourseProject\\ProjectsFile.txt";

// new object
Job newJob;

int main() {

	//displays a greeting to the user
	cout << "\nHello, welcome to the 'AUDRE' Project Management App\n\n";

	// program continues until user enters 'e' or 'E' indicating they are done
	while (toupper(userChoice) != 'E') {
		
		// Menu
		cout << "What would you like to do:\n"
			<< "(A) Add a job\n"
			<< "(U) Update a job\n"
			<< "(D) Delete a job\n"
			<< "(R) Display a Job Summary Report\n"
			<< "(E) Exit the program\n";
		cin >> userChoice;

		// loop to verify user's choice
		while (toupper(userChoice) != 'A' && toupper(userChoice) != 'U' && toupper(userChoice) != 'D' && toupper(userChoice) != 'R' && toupper(userChoice) != 'E') {
			cout << "\nPlease select a valid menu item. ";
			cin >> userChoice;
		}

		// user's choice triggers different menu options and thus functions
		switch (toupper(userChoice)) {
		case 'A':
			addJob();
			break;
		case 'U':
			updateJob();
			break;
		case 'D':
			deleteJob();
			break;
		case 'R':
			newJob.summaryReport(FileName);
			break;
		case 'E':
			cout << "\nThank you for using the 'AUDRE' Project Management App!\n";
			break;
		}
	}
} //end of main

// beginning of function definitions
void addJob() {
	
	cout << "\nAdd Job\n";

	//code to write information to file
	char anotherRecord = 'Y';
	ofstream  outMyStream(FileName, ios::app);		// opens file in append mode

	// loop iterated while user has more records to add
	while (toupper(anotherRecord) == 'Y') {

		// get values from user
		refNum = newJob.getRefNum();
		wireType = newJob.getWireType();
		feetOfWire = newJob.getFeetOfWire();
		wireCost = newJob.getWireCost();
		laborCost = newJob.getLaborCost();

		// set retrieved values
		newJob.setRefNum(refNum);
		newJob.setWireType(wireType);
		newJob.setFeetOfWire(feetOfWire);
		newJob.setWireCost(wireCost);
		newJob.setLaborCost(laborCost);

		if (outMyStream.is_open()) {

			// saving collected variables to file. (#) is my delimiter
			outMyStream << refNum << "#";
			outMyStream << wireType << "#";
			outMyStream << feetOfWire << "#";
			outMyStream << wireCost << "#";
			outMyStream << laborCost << "#";

		}

		cout << "\n\nEnter another Job? (Y/N)\n";
		cin >> anotherRecord;
	}

	// close file
	outMyStream.close();

	cout << "\n\nYour new job " << refNum << " has been saved to file.\n\n\n";
}

void updateJob() {

	// loop iterates until user is done with updates
	while (toupper(userChoice) != 'X') {
		// Update Options (sub menu to Menu) 
		cout << "\nWhat would you like to update:\n"
			<< "(R) Reference Number\n"
			<< "(W) Wire Type\n"
			<< "(F) Feet of Wire\n"
			<< "(C) Wire Cost\n"
			<< "(L) Labor Cost\n"
			<< "(X) Done With Updates\n";
		cin >> userChoice;

		// verifying user's choice
		while (toupper(userChoice) != 'R' && toupper(userChoice) != 'W' && toupper(userChoice) != 'F' && toupper(userChoice) != 'C' && toupper(userChoice) != 'L' && toupper(userChoice) != 'X') {
			cout << "\nPlease select a valid menu item. ";
			cin >> userChoice;
		}

		switch (toupper(userChoice)) {
		case 'R':
			refNum = newJob.getRefNum();
			newJob.setRefNum(refNum);
			cout << "\n\nYour change has been made.\n\n";
			break;
		case 'W':
			wireType = newJob.getWireType();
			newJob.setWireType(wireType);
			cout << "\n\nYour change has been made.\n\n";
			break;
		case 'F':
			feetOfWire = newJob.getFeetOfWire();
			newJob.setFeetOfWire(feetOfWire);
			cout << "\n\nYour change has been made.\n\n";
			break;
		case 'C':
			wireCost = newJob.getWireCost();
			newJob.setWireCost(wireCost);
			cout << "\n\nYour change has been made.\n\n";
			break;
		case 'L':
			laborCost = newJob.getLaborCost();
			newJob.setLaborCost(laborCost);
			cout << "\n\nYour change has been made.\n\n";
			break;
		case 'X':
			break;
		}
	}

	/* variable information has been collected like in addJob() function, but need to learn how to go to 
	   specific locations in file and overwrite data. So, code to write entered information to file, overwriting 
	   existing data will go here in future beyond this class. Need to learn this. */

	cout << "\nYour updates to job " << refNum << " has been saved to file.\n\n";
}

void deleteJob() {
	//code to retreive and delete file will go here later. I need to learn how to do this as well.
	cout << "\nJob " << refNum << " has been sucessfully deleted.\n\n";
}
