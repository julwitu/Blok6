#include "Hangman.hpp"
#include <iostream>
Hangman::Hangman(std::string secret)
{
	this->secret = secret;
	for (int i = 0; i < 26; i++) {
		alphabet[i] = false;
	}
	for (int i = 0; i < secret.length(); i++) {
		guessWord += '_';
	}
}

std::string Hangman::getGuess()
{
	for (int i = 0; i < secret.length(); i++) {
		std::cout << guessWord[i] << " ";
	}
	std::cout << std::endl;
	return guessWord;
}

std::string Hangman::getAlphabet()
{
	std::string result;
	for (int i = 0; i < 26; i++) {
		result += i + 97;
		//std::cout << static_cast<char>(i + 97) << " ";
	}
	return result;
}

bool Hangman::guess(char c)
{
	for (int i = 0; i < secret.length(); i++) {
		if (secret[i] == c) {
			guessWord[i] = c;
		}
	}

	return false;
}

std::string Hangman::getSecret()
{
	return std::string();
}
