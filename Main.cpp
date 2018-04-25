// ---------------------------------------------------------------
// Programming Assignment:	COURSE PROJECT
// Developer:				Domingo Gonzales III
// Date Written:			3/11/18
// Purpose:					WEEK 3 
// ---------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main() {

	// variable declarations
	char importOrManual, wireType;
	string typeOfWire;
	int feetOfWire;
	double costPerFoot, costOfLabor, totalCostOfMaterial, totalCostOfLabor;

	// determining how program will get its info
	cout << "Would you like to import(i) or manually enter(m) your quote information?";
	cin >> importOrManual;

	// verifying users input source choice
	while (importOrManual != 'i' && importOrManual != 'm') {
		cout << "Please enter an 'i' for import or 'm' for manual entry.";
		cin >> importOrManual;
	}

	// if statement for import or manual entry will be build here later

	cout << "What type of wire will the project require?\n(a for aluminum/c for copper)";
	cin >> wireType;

	if (wireType == 'a') {
		typeOfWire = "aluminum";
	}
	else {
		typeOfWire = "copper";
	}

	cout << "How many feet of wire will the project need?";
	cin >> feetOfWire;

	cout << "What is the current cost per foot of " << typeOfWire << " wire?";
	cin >> costPerFoot;

	cout << "What is the labor rate per foot of wire?";
	cin >> costOfLabor;

	totalCostOfMaterial = feetOfWire * costPerFoot;
	totalCostOfLabor = feetOfWire * costOfLabor;

	cout << "\nProject Report:\n\n"
		<< "You will use " << feetOfWire << " feet of " << typeOfWire << " wire.\n\n"
		<< "At a cost of $" << costPerFoot << " per foot, the total cost of materials will be $" << totalCostOfMaterial << ".\n"
		<< "At a rate of $" << costOfLabor << " per foot, the total cost of labor will be $" << totalCostOfLabor << ".\n";

}
