#pragma once
#include <string>
enum class VehicleType { car, handicap, bus };


struct ParkingSpot {
	std::string prefix;
	std::string value;
};

class Vehicle {
	VehicleType vt;
	ParkingSpot myParkingSpot;
public:
	Vehicle(VehicleType _vt);
	void parkFirstAvailable(ParkingLot& p); //wez pierwsze z tablicy
	void parkAtChoosen(); // wez wybrane przez siebie
	void clearSpot(); // wyczysc miejsce po sobie;
	//ParkingLot* getSpots() const;
	ParkingSpot* getParkingSpot() const;
};


//// ///// ///// SKONCZONA KLASA PARKINGLOT
class ParkingLot {
	ParkingSpot parkingSpots[50];
public:
	ParkingLot();
	void park(); // zaparkuj - odejmij od tablicy
	int firstFree(); // podaj pierwszy wolny
	bool checkIfAvailable(std::string input); // sprawdz czy wybrany jest wolny
	ParkingSpot* getParkingSpot() const;
};