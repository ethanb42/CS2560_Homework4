#ifndef ParkingMeter_H
#define ParkingMeter_H

class ParkingMeter
{
private:
	int purchasedTime;

public: 
	//constructors
	ParkingMeter(int pTime) {
		purchasedTime = pTime;
	}
	//default
	ParkingMeter() {
		ParkingMeter(0);
	}

	//getter methods
	int getPurchasedTime() {
		return purchasedTime;
	}

	//setter methods
	void setpurchasedTime(int pTime) {
		purchasedTime = pTime;
	}
};

#endif