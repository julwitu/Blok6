#include "Parkingv3.hpp"
#include "Parkingv2.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

//ZMNIEJSZYC CARCOUNTER W DESTRUKTORZE
int Vehicle::carCounter = 0;

ParkingLot::ParkingLot(int totalSpots, const int numOfLevels)
{
	regularSpots = 0.94 * totalSpots;
	handicapSpots = 0.04 * totalSpots;
	largeSpots = totalSpots - regularSpots - handicapSpots;
	int spotsAtLvl = totalSpots / numOfLevels;
	parkingSpots = new std::string*[numOfLevels];

	for (int i = 0; i < numOfLevels; i++) {
		int counter = 1;
	parkingSpots[i] = new std::string[spotsAtLvl];
	for (int j = 0; j < spotsAtLvl; j++) {
		if (i == 0)
			parkingSpots[i][j] += 'A';
		else if (i == 1)
			parkingSpots[i][j] += 'B';
		else if (i == 2)
			parkingSpots[i][j] += 'C';
		else if (i == 3)
			parkingSpots[i][j] += 'D';
		else if (i == 4)
			parkingSpots[i][j] += 'E';
		parkingSpots[i][j] += std::to_string(counter);
		counter++;
		}
	}
	// USUNAC WYPISYWANIE
	for (int i = 0; i < numOfLevels; i++) {
		for (int j = 0; j < spotsAtLvl; j++) {
			std::cout << parkingSpots[i][j] << " ";
		}
		std::cout << std::endl << std::endl;
	}
}

Vehicle::Vehicle(VehicleType _vt) : vt(_vt) {
	carCounter++;
	thisVehicleNum = carCounter;
	generatePlateNumber();
}

void Vehicle::parkFirstAvailable()
{
}

std::string Vehicle::generatePlateNumber()
{
	//SPRAWDZIC OSTRINGSTREAM
	std::ostringstream result;
	result << "PL";
	if (vt == VehicleType::car)
		result << 'C' + std::to_string(carCounter);
	else if (vt == VehicleType::bus)
		result << 'B' + std::to_string(carCounter);
	else if (vt == VehicleType::handicap)
		result << 'H' + std::to_string(carCounter);

	result << std::setw(4) << std::setfill('0') << this->thisVehicleNum;
	return result.str();
}

std::string Vehicle::whereToPark(ParkingLot& p)
{
	
}

Car::Car() : Vehicle(VehicleType::car) 
{
}


bool ParkingLot::isFree() {


}