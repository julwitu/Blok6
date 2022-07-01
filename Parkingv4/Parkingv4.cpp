#include "Parkingv4.hpp"
#include <iostream>
#include <string>

Vehicle::Vehicle(VehicleType _vt) : vt(_vt) {};

void Vehicle::parkFirstAvailable(ParkingLot& p) {


}
void Vehicle::parkAtChoosen() {

}
void Vehicle::clearSpot() {

}

ParkingSpot* Vehicle::getParkingSpot() const
{
	return (ParkingSpot*)myParkingSpot;
}



ParkingLot::ParkingLot() {
	for (int i = 0; i < 50; i++) {
		parkingSpots[i].prefix = "A";
		parkingSpots[i].value = std::to_string(i + 1);
	}
}

void ParkingLot::park() {

}

int ParkingLot::firstFree() {
	// find first free spot
	//int index = 0;
	//for (int i = 0; i < numOfSpots; i++) {
	//	if (freeSpots[i] == true) {
	//		index = i;
	//		break;
	//	}
	//}
	////USUNAC WYSWIETLANIE POZNIEJ
	//std::cout << "First free: " << index << " +  " << parkingSpots[index];
	//return index;
}

bool ParkingLot::checkIfAvailable(std::string input)
{
	//bool isFree = false;
	//for (int i = 0; i < 50; i++) {
	//	if ((parkingSpots[i] == input) && (freeSpots[i] == true)) {
	//		isFree = true;
	//		//USUNAC WYSWIETLANIE
	//		std::cout << "Is choosen available? " << i << " / " << isFree;
	//	}
	//}
	//return isFree;
}




//metoda parkfirstavailable musi wywolywac metode peekSpot i dopiero pozniej moze wywolywac metode park
//metoda parkatchoosen musi wielokrotnie wywolywac metode park az nie trafimy wolnego