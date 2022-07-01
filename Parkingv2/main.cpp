#include "Parkingv2.hpp"
#include <iostream>
#include <string>

int main() {
	ParkingLot p1(70, 3);
	Vehicle v(VehicleType::bus);
	std::cout << v.generatePlateNumber() << std::endl;
	
}