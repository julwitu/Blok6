#pragma once
#include <iostream>
enum class CheckerState {empty, X, O }; // 3 stany

class Board{
	CheckerState table[3][3];
public:
	Board();
	CheckerState check(int x, int y) const;
	bool set(CheckerState cs, int x, int y);
	bool isOver(); // rozbic na 3 metody
	bool xWon();
};
class Player{
	//Board* board; nie do konca potrzebne bo przekazujemy w parametrze turna
	//CheckerState colour; // mala niedoskonalosc-gracz moglby byc reprezentowany przez puste pola zamiast X lub O bo enum zawiera pusta wartosc
public:
	CheckerState colour;
	Player(CheckerState _colour);
	bool makeTurn(Board* board);
};
class Game{
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
