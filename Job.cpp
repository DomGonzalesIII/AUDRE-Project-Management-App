/* ----------------------------------------------------------------------------
This is the header file for the Job class

Developer:		Domingo Gonzales III
Date Written:	4/8/18
Last Updated:	4/14/18
-------------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include "Job.h"

// default constructor
Job::Job() {
	wireType = ' ';
	feetOfWire = 0.0;
	wireCost = 0.0;
	laborCost = 0.0;
}

// constructor
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

	// loop to verify user's choice is valid, this choice will determine selection of a string later
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

// print Summary Reports on all jobs in ProjectsFile.txt
void Job::summaryReport(const char FileName[]) {
	//code to extract this information from file
	ifstream inMyStream(FileName);	// opens file

	cout << "\nSummary Report\n\n";

	if (inMyStream.is_open()) {

		//set character to use as a line between record displays	
		string recBreaks = "";
		recBreaks.assign(30, '-');

		int fieldCount = 1;  //keep track of the number of fields read
		int recordCount = 1; //keep track of the number of records read

		//read the first field
		string fieldBuffer;
		getline(inMyStream, fieldBuffer, '#');

		// while the end of the file has not been reached
		while (!inMyStream.eof()) {

			//display the field
			switch (fieldCount) {

			case 1:
				cout << recBreaks << endl;
				cout << "Record # " << recordCount << endl;
				cout << "Reference Number..... " << fieldBuffer << endl;
				break;
			case 2:
				// stores wireType char for conversion to string
				wireTypeS = fieldBuffer;

				// if/else statement converting char indicator for wire type into meaningful string
				if (wireTypeS == "a" || wireTypeS == "A") {
					typeOfWire = "Aluminum";
				}
				else {
					typeOfWire = "Copper";
				}

				cout << "Type of wire......... " << typeOfWire << endl;
				break;
			case 3:
				feetOfWire = stod(fieldBuffer);
				cout << "Feet of Wire......... " << fieldBuffer << endl;
				break;
			case 4:
				wireCost = stod(fieldBuffer);
				cout << "Material Cost........ $" << fieldBuffer << endl;
				break;
			case 5:
				laborCost = stod(fieldBuffer);
				cout << "Labor Cost........... $" << fieldBuffer << endl;
				fieldCount = 0;
				recordCount++;

				// calculate total costs
				totalMaterialCost = feetOfWire * wireCost;
				totalLaborCost = feetOfWire * laborCost;

				//add total cost that are not stored in file to end of Summary Report print out before net record
				cout << "\nTotal Material Cost.. $" << totalMaterialCost << endl;
				cout << "Total Labor Cost..... $" << totalLaborCost << endl;
				cout << "\nTotal Job Cost....... $" << (totalMaterialCost + totalLaborCost) << endl;

				break;

			}

			//read the next field
			getline(inMyStream, fieldBuffer, '#');
			fieldCount++;

		}

		cout << recBreaks << endl;

		// closes the file
		inMyStream.close();
	}

}
