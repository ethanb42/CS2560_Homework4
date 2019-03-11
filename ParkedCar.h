
#ifndef ParkedCar_H
#define ParkedCar_H

#include <string>
using namespace std;
class ParkedCar{

private:
	//the car's data
	string make;
	string model;
	string color;
	string license;
	int minutes;

public:
	//Constructors 
	ParkedCar(string ma, string mo, string c, string lic, int m) {
		make = ma;
		model = mo;
		color = c;
		license = lic;
		minutes = m;
	}
	//default
	ParkedCar() {
		ParkedCar("", "", "", "", -1);
	}

	//getter methods
	string getMake()  {
		return make;
	}

	string getModel() {
		return model;
	}

	string getColor() {
		return color;
	}

	string getLicense() {
		return license;
	}
	int getMinutes()  {
		return minutes;
	}

	//setter methods
	void setMake(string ma) {
		make = ma;
	}

	void setModel(string mo) {
		model = mo;
	}

	void setColor(string c) {
		color = c;
	}

	void setLicense(string li) {
		license = li;
	}

	void setMinutes(int m) {
		minutes = m;
	}
	
};

#endif

