

#include <iostream>
#include <string>

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"
#include "ParkingTicket.h"
#include <iostream>
using namespace std;


int main() {
	//create a car
	ParkedCar car1 ("Kia", "Forte", "Silver", "1abc123", 20);

	//create a parking meter
	ParkingMeter meter1(20);

	//create a police officer
	PoliceOfficer police("Billy Bronco", 123456);

	cout << "Testing Ticket Simulator" << endl;

	//check for ticket
	if (police.checkParkedCar(car1, meter1) == 1) {
		//ticket issued
		cout << "Ticket issued" << endl;
		police.issueTicket(car1, meter1);
	}
	else {
		//no ticket
		cout << "Ticket not issued" << endl;
	}

	cout << "\nSetting the car's parked time to past the meter time\n" << endl;
	//increase the cars parked time so it passed the meter time
	car1.setMinutes(21);

	//check for ticket
	if (police.checkParkedCar(car1, meter1) == 1) {
		//ticket issued
		cout << "Ticket issued" << endl;
		police.issueTicket(car1, meter1);
	}
	else {
		//no ticket
		cout << "Ticket not issued" << endl;
	}

	//print out ticket to validate ticket was issued
	police.issueTicket(car1, meter1).printTicket();
	
	//car has been sitting for 2 hours now
	cout << "\nThe car has been sitting for 2 hours, updating ticket price...\n" << endl;
	car1.setMinutes(120);

	police.issueTicket(car1, meter1).setFine(car1,meter1);
	police.issueTicket(car1, meter1).printTicket();


	return 0;
}
