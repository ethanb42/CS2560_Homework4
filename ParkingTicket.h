#ifndef ParkingTicket_H
#define ParkingTicket_H

//include the needed members
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"

#include <iostream>
#include <string>
using namespace std;

//forward declaration for class types used in ParkingTicket
//prevents compiler error
class ParkedCar;
class ParkingMeter;
class PoliceOfficer;

class ParkingTicket
{
private:
	int fine; //the ammount of the fine
	int badgeNumber;  //badge number of officer who issued citation
	string officerName; //name of officer who issued citation
	
	ParkedCar car;  //the car issued the citation
	ParkingMeter meter;  //used to find the fine cost

public:
	//needs to report the car, the fine, and the officer
	ParkingTicket(int bn, string n, ParkedCar &c, ParkingMeter &m) {
		car = c;
		meter = m;
		badgeNumber = bn;
		officerName = n;

		//calc fine ammount
		fine = 25 + ((car.getMinutes() - meter.getPurchasedTime()) / 60) * 10;

	}

	//getter methods
	int getFine() {
		return fine;
	}

	int getBadgeNumber() {
		return badgeNumber;

	}

	string getOfficerName() {
		return officerName;
	}

	//setter methods
	void setFine(ParkedCar &car, ParkingMeter &meter) {
		fine = 25 + ((car.getMinutes() - meter.getPurchasedTime()) / 60) * 10;
	}

	//prints ticket info for testing
	void printTicket() {
		cout << "\nTicket Information Printing....\n" <<
			"Car Make / Model: " << car.getMake() << " / " <<
			car.getModel() << endl;
		cout << "Car Color: " << car.getColor() << endl;
		cout << "Car License: " << car.getLicense() << endl;
		cout << "Fine: $" << fine << endl;
		cout << "Issued by Officer " << officerName << "  Badge Number: " << badgeNumber << endl;

	}
};

#endif
