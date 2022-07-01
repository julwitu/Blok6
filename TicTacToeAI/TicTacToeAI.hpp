#pragma once
#include <iostream>

//tworzymy klasy pochodne AIPlayer i HumanPlayer z klasa bazowa Player
//makeTurn w Player -> virtualna (najlepiej pure virtual); przesuwamy nasza metode do HumanPlayer
//zrobic wybor/interakcje zeby tworzyc AIPlayer lub HumanPlayer w zaleznosci od inputu z klawiatury
//zdefiniowac metode makeTurn dla AIPlayer
//	//uzyc funkcji random z odpowiednim zakresem do losowania pol w AIPlayerze


enum class CheckerState { empty, X, O }; // 3 stany

class Board {
	CheckerState table[3][3];
public:
	Board();
	CheckerState check(int x, int y) const;
	bool set(CheckerState cs, int x, int y);
	bool isOver(); // rozbic na 3 metody
	bool isOverRows();
	bool isOverCols();
	bool isOverDiagonals();
	bool xWon();
};
class Player {
	//Board* board; nie do konca potrzebne bo przekazujemy w parametrze turna
	//CheckerState colour; // mala niedoskonalosc-gracz moglby byc reprezentowany przez puste pola zamiast X lub O bo enum zawiera pusta wartosc
protected:
	CheckerState colour;
public:
	Player(CheckerState _colour);
	virtual bool makeTurn(Board* board) = 0;
};

class AIPlayer : public Player {
public:
	AIPlayer(CheckerState _colour);
	bool makeTurn(Board* board) override;

};

class HumanPlayer : public Player {
public:
	HumanPlayer(CheckerState _colour);
	bool makeTurn(Board* board) override; 
};
class Game {
	Player* currentPlayer;
	Player* player1;
	Player* player2;
	Board board;
	void swapPlayer();
public:
	Game(Player* p1, Player* p2);
	void start(); // petla gry
	void reset();
};

std::ostream& operator<<(std::ostream& s, const Board& board);
std::ostream& operator<<(std::ostream& s, const CheckerState& cs);
