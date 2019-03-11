#ifndef PoliceOfficer_H
#define PoliceOfficer_H

//object the officer interacts with
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"

#include <string>

//forward declaration of classes used in the Police Officer class
//Prevents compiler error
class ParkedCar;
class ParkingMeter;
class ParkingTicket;

using namespace std;
class PoliceOfficer
{
private: 
	string name;  //the officer's name
	int badgeNumber;  //the officer's badge number

public:

	//constructor
	PoliceOfficer(string n, int badge) {

		name = n;
		badgeNumber = badge;
	}

//getter methods
	string getName() {
		return name;
}
	
	int getBadgeNumber() {
		return badgeNumber;
	}

	//setter methods
	void setName(string s) {
		name = s;
	}

	void setBadgeNumber(int x) {
		badgeNumber = x;
	}

	//check a ParkedCar and a ParkingMeter to see if the time 
	//has expired
	int checkParkedCar(ParkedCar &car, ParkingMeter &meter) {
		if (car.getMinutes() > meter.getPurchasedTime()) {
			return 1; //issue a ticket
		}
		else
			return 0; //no ticket 
	}

	//issue a citation if the car is out of time
	ParkingTicket issueTicket(ParkedCar &car, ParkingMeter &meter) {
		ParkingTicket ticket(badgeNumber,name, car, meter); //created the ticket
		return ticket;
	}
};

#endif