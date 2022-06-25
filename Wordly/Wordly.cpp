
#include "Wordly.hpp"
#include "iostream"
#include <stdlib.h>

Wordle::Wordle(std::string secret)
{
	this->secret = secret;
	attempt = 0;
}

std::string Wordle::test(std::string guess)
{

	guesses[attempt] = guess;
	std::string answer;
	for (int i = 0; i < 5; i++) {
		answer += 'B';
	}
	
		for (int j = 0; j < 5; j++) {
			if (secret[j] == guess[j]) {
				answer[j] = 'G';
			}
			else {
				for (int i = 0; i < 5; i++) {
					if (secret[j] == guess[i])
						answer[i] = 'O';
				}
			}
		}
		answers[attempt] = answer;
	return guess;
}

bool Wordle::isFinished()
{
	bool finished = false;
	if (attempt>5 || (guesses[attempt] == secret) && (answers[attempt] == "GGGGG")){
		finished = true;
	} 
	attempt++;
	return finished;
}

void Wordle::draw()
{

	std::cout << guesses[attempt] << '\t' << answers[attempt] << '\t' << "Attempt: " << attempt+1 << std::endl;

}
