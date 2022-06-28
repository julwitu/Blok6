#pragma once
//README	To jest projekt parkingu, ktory pozwala uzytkownikowi na sprawdzenie dostepnych miejsc w danym momencie. Dostepne sa miejsca dla samochodow osobowych, busow lub inwalidow. Kazde miejsce parkingowe ma osobna cene. Dostepne taryfy to: godzinowa, dzienna lub miesieczna.  
//mozna dodac obsluge parkingu, parking tickets, co jeszcze?
//dodac numeracje miejsc parkingowych oraz odpowiednio funkcje zwracajaca numer miejsca parkingowego
// fajnie byloby dopisac dwie tablice jedna, ktora bedzie tablica booli sprawdzajaca czy dane miejsce parkingowe jest dostepne, druga podajaca numer tego miejsca. W momencie kiedy klient zaparkuje na danym miejscu parkingowym to numer miejsca automatycznie zostanie przypisany do klienta natomiast w tablicy zmienia sie na zajety.

//KROK PO KROKU:
//1. najpier zaimplementuj logike wolnych miejsc parkingowych numerowania ich i przypisywania klientowi
//2. pozniej wybor taryfy oraz obliczenie ceny za wykupione miejsce parkingowe
//3. mozna dodac dodatkowa funkcjonalnosc czyli tablice przechowujaca numery rejestracyjne zaparkowanych samochodow 
enum class TypeOfVehicle{car, van, handicap};

class Parking {
	double width; //calkowite wymiary parkingu //realnie 2,44x4,88 normalne, 3,6x4,8 handicap   3,1x5,88 van  !! 38% calosci nalezy zostawic na drogi pomiedzy
	double deepth; // calkowite wymiary parkingu
	double totalArea; // calkowita powierzchnia parkingu
	int numOfRegularSpots; // calkowita liczba normalnych miejsc parkingowych
	int numOfLargerSpots; // calkowita liczba duzych miejsc parkingowych
	int numOfDisabledParkingSpots; // calkowita liczba miejsc dla niepelnosprawnych;
	int openingHours; // godziny otwarcia !!sprawdzic czy nie lepiej byloby wprowadzic je jako inny typ zmiennej lub rozbic na dwa
	int ratePerHour; // cena za miejsce parkingowe za godzine !! na podstawie tej ceny beda wyliczane daily i monthy fees;
	int currentAvailableSpots;
public:
	Parking(double width, double deepth); // konstruktor w ktorym podajemy dokladne wymiary parkingu, na jej podstawie dostajemy informacje na temat liczby utworzenia miejsc parkingowych, z ktorej 2% powinny stanowic duze miejsca oraz 5% miejsca dla niepelnosprawnych
};

class RegularParkingSpot {
	int width;// wymiary miejsca parkingowego
	int deepth; // wymiary miejsca parkingowego
	int ratePerHour; // cena za miejsce parkingowe za godzine !! na podstawie tej ceny beda wyliczane daily i monthy fees;
public:
	RegularParkingSpot(int chosenFee); // w konstruktorze podajemy na ile osoba chce zaparkowac samochod !! sprawdzic czy typ danej odpowiedni
	bool ifOccupied();

};

class LargerParkingSpot {

};

class DisabledParkingSpot {

};

class Customer {
	TypeOfVehicle vehicle;
public: 
	Customer(TypeOfVehicle vehicle);
	bool checkAvailableSpots(); // funkcja sprawdzajaca czy sa dostepne miejsca parkingowe z danej kategorii
	int whereToPark(); //po sprawdzeniu czy dane miejsce parkingowe jest dostepne funkcja zwraca numer miejsca pod jakim mozemy zaparkowac
};

