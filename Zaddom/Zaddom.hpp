#pragma once
#include <iostream>

class Board;

enum CheckerState { X, O, EMPTY };

class Board
{
	CheckerState table[3][3];
	bool checkRows();
	bool checkCols();
	bool checkDiagonal();
public:
	CheckerState check(int x, int y) const;
	void set(CheckerState cs, int x, int y);
	bool isOver();
	bool xWon();
};

class Player
{
	CheckerState colour;
public:
	Player(CheckerState _colour);
	bool makeTurn(Board*);
};

class Game
{
	Board board;
	Player* p1, * p2;
	Player* currentPlayer;
	void swapPlayer();
public:
	Game(Player* p1, Player* p2);
	void start();
	void reset();
};

std::ostream& operator<<(std::ostream& s, const Board& board);