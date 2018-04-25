// ---------------------------------------------------------------
// Programming Assignment:	COURSE PROJECT
// Developer:				Domingo Gonzales III
// Date Written:			3/25/18
// Purpose:					WEEK 4 
// ---------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

//function prototypes
void addJob(int);
void updateJob(int);
void deleteJob(int);
void summaryReport(int);

// variable declarations
char userChoice = ' ', wireType;
string typeOfWire;
int refNum, feetOfWire;
double costPerFoot, costOfLabor, totalCostOfMaterial, totalCostOfLabor;

int main() {

	while (userChoice != 'E' && userChoice != 'e') {
		
		// Menu
		cout << "What would you like to do:\n"
			<< "(A) Add a job\n"
			<< "(U) Update a job\n"
			<< "(D) Delete a job\n"
			<< "(R) Display a Job Summary Report\n"
			<< "(E) Exit the program\n";
		cin >> userChoice;

		// verifying user's choice
		while (userChoice != 'A' && userChoice != 'a' && userChoice != 'U' && userChoice != 'u' && userChoice != 'D' && userChoice != 'd' && userChoice != 'R' && userChoice != 'r' && userChoice != 'E' && userChoice != 'e') {
			cout << "Please select a valid menu item. ";
			cin >> userChoice;
		}

		if (userChoice == 'A' || userChoice == 'a') {
			cout << "Enter the reference number for the new job you would like to add: ";
			cin >> refNum;
			addJob(refNum);
		}
		else if (userChoice == 'U' || userChoice == 'u') {
			cout << "Enter the reference number for the job you wish to update: ";
			cin >> refNum;
			updateJob(refNum);
		}
		else if (userChoice == 'D' || userChoice == 'd') {
			cout << "Enter the reference number for the job you would like to delete: ";
			cin >> refNum;
			deleteJob(refNum);
		}
		else if (userChoice == 'R' || userChoice == 'r') {
			cout << "Enter the reference number for the job you would like to create a summary report for: ";
			cin >> refNum;
			summaryReport(refNum);
		}
		else {
			cout << "Thanks for using the Project Management App!\n";
		}

	}
}

void addJob(int refNum) {
	//Code to create file named refNum will go here

	cout << "What type of wire will the project require?\n(a for aluminum/c for copper) ";
	cin >> wireType;

	if (wireType == 'a') {
		typeOfWire = "aluminum";
	}
	else {
		typeOfWire = "copper";
	}

	cout << "How many feet of wire will the project need? ";
	cin >> feetOfWire;

	cout << "What is the current cost per foot of " << typeOfWire << " wire? $";
	cin >> costPerFoot;

	cout << "What is the labor rate per foot of wire? $";
	cin >> costOfLabor;

	totalCostOfMaterial = feetOfWire * costPerFoot;
	totalCostOfLabor = feetOfWire * costOfLabor;

	//code to save entered information will go here later

	cout << "Your new job " << refNum << " has been saved to file.\n\n";
}

void updateJob(int refNum) {

	cout << "What type of wire will the project require?\n(a for aluminum/c for copper) ";
	cin >> wireType;

	if (wireType == 'a') {
		typeOfWire = "aluminum";
	}
	else {
		typeOfWire = "copper";
	}

	cout << "How many feet of wire will the project need? ";
	cin >> feetOfWire;

	cout << "What is the current cost per foot of " << typeOfWire << " wire? ";
	cin >> costPerFoot;

	cout << "What is the labor rate per foot of wire? ";
	cin >> costOfLabor;

	totalCostOfMaterial = feetOfWire * costPerFoot;
	totalCostOfLabor = feetOfWire * costOfLabor;

	//code to save entered information overwriting existing data will go here
	cout << "Your updates to job " << refNum << " has been saved to file.\n\n";
}

void deleteJob(int refNum) {
	//code to delete file will go here later
	cout << "Job " << refNum << " has been sucessfully deleted.\n\n";
}

void summaryReport(int refNum) {
	//code to extract this information from file will go here so I've entered dummy numbers

	cout << "\nProject Report:\n\n"
		<< "You will use " << 100 << " feet of " << "aluminum" << " wire.\n\n"
		<< "At a cost of $" << 4.00 << " per foot, the total cost of materials will be $" << 400 << ".\n"
		<< "At a rate of $" << 8.00 << " per foot, the total cost of labor will be $" << 800 << ".\n"
		<< "This brings the total project cost to $" << 1200 << ".\n\n";
}
