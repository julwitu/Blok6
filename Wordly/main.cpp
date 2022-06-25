#include "Wordly.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

int main() {
	Wordle game("BEADY");
	int attempts = 0;

	do {
		//system("cls"); //czyscimy ekran
		//game.draw();
		std::cout << "Podaj slowo: " << std::endl;
		std::string word;
		std::cin >> word;
		std::string colours = game.test(word);
	
		//system("cls"); //czyscimy ekran wrzucic do metody draw
		game.draw();
	} while (!game.isFinished());


}