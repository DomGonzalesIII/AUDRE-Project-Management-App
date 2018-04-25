#include <iostream>
#include <string>

using namespace std;

class Job {
// private variables
private:
	char wireType;
	string typeOfWire, action;
	int refNum;
	double feetOfWire, wireCost, laborCost;

// public member functions
public:
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
	void summaryReport();
};
