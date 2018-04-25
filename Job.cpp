#include <iostream>
#include "Job.h"

Job::Job() {
	wireType = ' ';
	feetOfWire = 0.0;
	wireCost = 0.0;
	laborCost = 0.0;
}

Job::Job(int rn, char wt, double fow, double wc, double lc) {
	refNum = rn;
	wireType = wt;
	feetOfWire = fow;
	wireCost = wc;
	laborCost = lc;
}

void Job::setRefNum(int rn) {
	refNum = rn;
}

void Job::setWireType(char wt) {
	wireType = wt;
}

void Job::setFeetOfWire(double fow) {
	feetOfWire = fow;
}

void Job::setWireCost(double wc) {
	wireCost = wc;
}

void Job::setLaborCost(double lc) {
	laborCost = lc;
}

int Job::getRefNum() {
	cout << "\nEnter your reference number: ";
	cin >> refNum;
	return refNum;
}

char Job::getWireType() {
	cout << "\nWhat type of wire will the project require?\n(a for aluminum/c for copper) ";
	cin >> wireType;

	// verifying user's choice 
	while (tolower(wireType) != 'a' && tolower(wireType) != 'c') {
		cout << "\nPlease select a valid wire type.\n(a for aluminum/c for copper) ";
		cin >> wireType;
	}
	return wireType;
}

double Job::getFeetOfWire() {
	cout << "\nEnter the feet of wire required by the job: ";
	cin >> feetOfWire;
	return feetOfWire;
}

double Job::getWireCost() {
	cout << "\nEnter the current cost of your wire type: ";
	cin >> wireCost;
	return wireCost;
}

double Job::getLaborCost() {
	cout << "\nEnter the current cost of labor: ";
	cin >> laborCost;
	return laborCost;
}

void Job::summaryReport() {
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
	cout << "\n***********************************\nProject Report:\n\n"
		<< "You will use " << costs[0] << " feet of " << "aluminum" << " wire.\n\n"
		<< "At a cost of $" << costs[1] << " per foot, the total cost of materials will be $" << costs[3] << ".\n"
		<< "At a rate of $" << costs[2] << " per foot, the total cost of labor will be $" << costs[4] << ".\n"
		<< "\nThis brings the total project cost to $" << costs[5] << ".\n\n";
}
