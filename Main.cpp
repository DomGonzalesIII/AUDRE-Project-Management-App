// ---------------------------------------------------------------
// Programming Assignment:	COURSE PROJECT
// Developer:				Domingo Gonzales III
// Date Written:			3/31/18
// Purpose:					WEEK 5
// ---------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

//function prototypes
void addJob(int);
void updateJob(int);
void deleteJob(int);
void summaryReport(int);

//variable declarations
char userChoice = ' ', wireType;
string typeOfWire;
int refNum;

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

		if (toupper(userChoice) == 'A') {
			cout << "\nEnter the reference number for the new job you would like to add: ";
			cin >> refNum;
			addJob(refNum);
		}
		else if (toupper(userChoice) == 'U') {
			cout << "\nEnter the reference number for the job you wish to update: ";
			cin >> refNum;
			updateJob(refNum);
		}
		else if (toupper(userChoice) == 'D') {
			cout << "\nEnter the reference number for the job you would like to delete: ";
			cin >> refNum;
			deleteJob(refNum);
		}
		else if (toupper(userChoice) == 'R') {
			cout << "\nEnter the reference number of the job you would like to create a summary report for: ";
			cin >> refNum;
			summaryReport(refNum);
		}
		else {
			cout << "\nThank you for using the 'AUDRE' Project Management App!\n";
		}

	}
}

void addJob(int refNum) {
	//Code to create file named refNum will go here

	cout << "What type of wire will the project require?\n(a for aluminum/c for copper) ";
	cin >> wireType;

	// verifying user's choice
	while (tolower(wireType) != 'a' && tolower(wireType) != 'c') {
		cout << "Please select a valid wire type.\n(a for aluminum/c for copper) ";
		cin >> wireType;
	}

	//converts users char input for wire type into string. This makes input easier
	if (wireType == 'a') {
		typeOfWire = "aluminum";
	}
	else {
		typeOfWire = "copper";
	}

	double costs[6]; //this array will store the feet of wire, cost per foot, labor rate, total materials cost, total labor cost, and total project cost

	cout << "How many feet of wire will the project need? ";
	cin >> costs[0];

	cout << "What is the current cost per foot of " << typeOfWire << " wire? $";
	cin >> costs[1];

	cout << "What is the labor rate per foot of wire? $";
	cin >> costs[2];

	costs[3] = costs[0] * costs[1];		//calculates total materials cost
	costs[4] = costs[0] * costs[2];		//calculates total labor cost
	costs[5] = costs[3] + costs[4];		//calculates total cost of the project

	//code to write information to file will go here later

	cout << "\nYour new job " << refNum << " has been saved to file.\n\n";
}

void updateJob(int refNum) {

	cout << "What type of wire will the project require?\n(a for aluminum/c for copper) ";
	cin >> wireType;

	// verifying user's choice
	while (tolower(wireType) != 'a' && tolower(wireType) != 'c') {
		cout << "Please select a valid wire type.\n(a for aluminum/c for copper) ";
		cin >> wireType;
	}

	//converts users char input for wire type into string. This makes input easier
	if (wireType == 'a') {
		typeOfWire = "aluminum";
	}
	else {
		typeOfWire = "copper";
	}

	double costs[6]; //this array will store the feet of wire, cost per foot, labor rate, total materials cost, total labor cost, and total project cost

	cout << "How many feet of wire will the project need? ";
	cin >> costs[0];

	cout << "What is the current cost per foot of " << typeOfWire << " wire? $";
	cin >> costs[1];

	cout << "What is the labor rate per foot of wire? $";
	cin >> costs[2];

	costs[3] = costs[0] * costs[1];		//calculates total materials cost
	costs[4] = costs[0] * costs[2];		//calculates total labor cost
	costs[5] = costs[3] + costs[4];		//calculates total cost of the project

	//code to write entered information to file, overwriting existing data will go here
	cout << "\nYour updates to job " << refNum << " has been saved to file.\n\n";
}

void deleteJob(int refNum) {
	//code to delete file will go here later
	cout << "\nJob " << refNum << " has been sucessfully deleted.\n\n";
}

void summaryReport(int refNum) {
	//code to extract this information from file will go here so I've entered dummy numbers
	char wireType = 'a';
	double costs[6] = { 100, 4.00, 8.00, 400, 800, 1200 };

	//converting char indicator for wire type into meaningful string
	if (wireType == 'a') {
		typeOfWire = "aluminum";
	}
	else {
		typeOfWire = "copper";
	}

	//printing report to console
	cout << "\nProject Report:\n\n"
		<< "You will use " << costs[0] << " feet of " << "aluminum" << " wire.\n\n"
		<< "At a cost of $" << costs[1] << " per foot, the total cost of materials will be $" << costs[3] << ".\n"
		<< "At a rate of $" << costs[2] << " per foot, the total cost of labor will be $" << costs[4] << ".\n"
		<< "\nThis brings the total project cost to $" << costs[5] << ".\n\n";
}
