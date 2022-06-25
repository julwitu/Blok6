#pragma once
#include <string>

class Hangman {
	std::string secret;// przekazane z konstruktora
	bool alphabet[26]; // warto zainicjalizowac w konstruktorze
	std::string guessWord; //na samym poczatku same _ _ _ 
	int attempt; // ignoruj poki co
public:

	Hangman(std::string secret);

	std::string getGuess();
	std::string getAlphabet();
	bool guess(char c); // zwraca prawde tylko jesli wszystkie litery sa odgadniete
	std::string getSecret();
};