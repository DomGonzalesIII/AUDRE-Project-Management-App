/* -------------------------------------------------------------------------------
   This class stores information about a wire harness job involving wire and labor

   Developer:		Domingo Gonzales III
   Date Written:	4/8/18
   Last Updated:	4/14/18
   -------------------------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

class Job {
// private variables
private:

	char wireType;
	string wireTypeS, typeOfWire, action;
	int refNum;
	double feetOfWire, wireCost, laborCost, totalMaterialCost, totalLaborCost;

// public member functions
public:

	//constructors
	Job();
	Job(int rn, char wt, double fow, double wc, double lc);
	
	// mutator functions
	void setRefNum(int rn);
	void setWireType(char wt);
	void setFeetOfWire(double fow);
	void setWireCost(double wc);
	void setLaborCost(double lc);

	// accessor functions
	int getRefNum();
	char getWireType();
	double getFeetOfWire();
	double getWireCost();
	double getLaborCost();
	void summaryReport(const char FileName[]);
};
