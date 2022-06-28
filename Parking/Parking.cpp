#include "Parking.hpp"
#include <iostream>

Parking::Parking(double _width, double _deepth) : width(_width), deepth(_deepth)
{
	totalArea = width * deepth;
	// obliczyc regularParkingSpotDimensions na podstawie klasy RegularParkingSpot dla ulatwienia na razie wpisuje te wartosc na sztywno i tak samo robie z innymi miejscami
	double regularSpotDimensions = 11.09;
	double largerSpotDimensions = 18.22;
	double handicapSpotDimensions = 17.28;
	totalArea *= 0.62; // odejmujemy 38% calosci calej powierzchni na szlaki komunikacyjne
	double areaForVans = totalArea * 0.02;
	double areaForHandicaps = totalArea * 0.05;
	double areaForRegulars = totalArea - areaForVans - areaForHandicaps;

	numOfLargerSpots = static_cast<int>(areaForVans / largerSpotDimensions);
	numOfDisabledParkingSpots = static_cast<int>(areaForHandicaps / handicapSpotDimensions);
	numOfRegularSpots = static_cast<int>(areaForRegulars / regularSpotDimensions);
	std::cout << numOfLargerSpots << " " << numOfDisabledParkingSpots << " " << numOfRegularSpots;
}
