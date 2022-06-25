#pragma once
#include <string>


class Wordle {
	std::string secret;
	std::string guesses[6];
	std::string answers[6];
	int attempt;
public:
	Wordle(std::string secret);
	std::string test(std::string guess);
	bool isFinished(); // sprawdza czy ostatnie zgadniete slowo jest rowne secret i sprawdza liczbe prob
	//bool isFinished(std::string colours) //  sprawdzamy czy slowo ma wszystkie zielone pola 

	void draw(); // wypisz obie tablice , jedna z kolorami jedna ze zgadnietym slowem + na poczatku wyczysc ekran
};

//wynik metody draw 
//IRATE std::cout<< '\t' BBGBO
//CEASE \t BGGBB ...