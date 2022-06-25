#include "Hangman.hpp"
#include <string>
#include <iostream>

int main() {
	Hangman game("wisielec");
	bool finished;
	do {
		std::string guess = game.getGuess(); // zwracac _ a _ _ _ a _
		//std::cout << guess << std::endl;
		std::string alphabet = game.getAlphabet(); // zwracac _ b c d e _ _ h
		std::cout << alphabet << std::endl;
		std::cout << "Guess a letter: " << std::endl;
		char letter;
		std::cin >> letter;

		 finished = game.guess(letter); // zgadujemy - zmieniamy zarowno getguess i getalphabet
	} while (!finished);
	std::cout << "Secret key was: " << game.getGuess();



}