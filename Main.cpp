// ---------------------------------------------------------------
// Programming Assignment:	COURSE PROJECT
// Developer:				Domingo Gonzales III
// Date Written:			4/8/18
// Purpose:					WEEK 6
// ---------------------------------------------------------------

#include <iostream>
#include <string>
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

// new object
Job newJob;

int main() {

	//displays a greeting to the user
	cout << "\nHello, welcome to the 'AUDRE' Project Management App\n\n";

	while (toupper(userChoice) != 'E') {
		
		// Menu
		cout << "What would you like to do:\n"
			<< "(A) Add a job\n"
			<< "(U) Update a job\n"
			<< "(D) Delete a job\n"
			<< "(R) Display a Job Summary Report\n"
			<< "(E) Exit the program\n";
		cin >> userChoice;

		// verifying user's choice
		while (toupper(userChoice) != 'A' && toupper(userChoice) != 'U' && toupper(userChoice) != 'D' && toupper(userChoice) != 'R' && toupper(userChoice) != 'E') {
			cout << "\nPlease select a valid menu item. ";
			cin >> userChoice;
		}

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
			newJob.summaryReport();
			break;
		case 'E':
			cout << "\nThank you for using the 'AUDRE' Project Management App!\n";
			break;
		}
	}
}

void addJob() {
	//Code to create file named refNum will go here

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

	//code to write information to file will go here later

	cout << "\n\nYour new job " << refNum << " has been saved to file.\n\n\n";
}

void updateJob() {

	while (toupper(userChoice) != 'X') {
		// Update Options 
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

	//code to write entered information to file, overwriting existing data will go here
	
	cout << "\nYour updates to job " << refNum << " has been saved to file.\n\n";
}

void deleteJob() {
	//code to delete file will go here later
	cout << "\nJob " << refNum << " has been sucessfully deleted.\n\n";
}
