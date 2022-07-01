#pragma once
#include <string>
enum class VehicleType{car, handicap, bus};

class ParkingLot;
class ParkingTicket;

class Vehicle {
	std::string plateNumber;
	VehicleType vt;
	int numOfSpotsRequired;
	int thisVehicleNum;
protected: 	
	static int carCounter;

public:
	Vehicle(VehicleType _vt);
	std::string generatePlateNumber();
	std::string whereToPark(ParkingLot& p); // metoda zwraca pierwsze wolne miejsce do zaparkowania
	bool canIParkHere(std::string); // metoda zwraca czy wybrane przez uzytkownika miejsce jest wolne do zaparkowania
	bool ifFits();
	void clearSpot();
	ParkingTicket printParkingTicket();
};
class Car : public Vehicle {
public:
	Car();
};
class Bus : public Vehicle {
public:

};
class Handicap : public Vehicle{
public:

};


class ParkingLot {
	std::string** parkingSpots = nullptr;
	int regularSpots;
	int handicapSpots;
	int largeSpots;
public:
	ParkingLot(int totalSpots, int numOfLevels);
	std::string** showFreeSpots();
	// Utworzyc druga tablice booli ktora trzymalaby wartosci zajetych miejsc
	bool isFree();
	void parkHere();
};