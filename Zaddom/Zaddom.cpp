#include "Zaddom.hpp"
#include <iostream>

void Game::swapPlayer()
{
	if (currentPlayer == p1)
		currentPlayer = p2;
	else
		currentPlayer = p1;
}

Game::Game(Player* _p1, Player* _p2) : p1(_p1), p2(_p2)
{
	reset();
}

void Game::start()
{
	currentPlayer = p1;
	while (!board.isOver())
	{
		currentPlayer->makeTurn(&board);
		std::cout << "--------------" << std::endl;
		std::cout << board;
		std::cout << "--------------" << std::endl;
		swapPlayer();
	}
	if (board.xWon())
		std::cout << "X won" << std::endl;
	else
		std::cout << "O won" << std::endl;
}

void Game::reset()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board.set(CheckerState::EMPTY, i, j);
}

bool Board::checkRows()
{
	bool result = false;
	for (int i = 0; i < 3; i++)
	{
		if ((table[i][0] != CheckerState::EMPTY) &&
			(table[i][0] == table[i][1] == table[i][2]))
			result = true;
	}
	return result;
}

bool Board::checkCols()
{
	bool result = false;
	for (int i = 0; i < 3; i++)
	{
		if ((table[0][i] != CheckerState::EMPTY) &&
			(table[0][i] == table[1][i] == table[2][i]))
			result = true;
	}
	return result;
}

bool Board::checkDiagonal()
{
	return (table[0][0] != CheckerState::EMPTY) && (table[0][0] == table[1][1] == table[2][2]) ||
		(table[2][0] != CheckerState::EMPTY) && (table[2][0] == table[1][1] == table[0][2]);
}

CheckerState Board::check(int x, int y) const
{
	return table[x][y];
}

void Board::set(CheckerState cs, int x, int y)
{
	table[x][y] = cs;
}

bool Board::isOver()
{
	return checkRows() || checkCols() || checkDiagonal();
}

bool Board::xWon()
{
	return false;
}

Player::Player(CheckerState _colour) : colour(_colour)
{
}

bool Player::makeTurn(Board* board)
{
	std::cout << "You're player: " << colour << std::endl;
	int x = 0, y = 0;
	do
	{
		std::cout << "Give x and y: ";
		std::cin >> x;
		std::cin >> y;
	} while (board->check(x, y) != CheckerState::EMPTY);

	board->set(colour, x, y);
	return false;
}

std::ostream& operator<<(std::ostream& s, const Board& board)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			CheckerState cs = board.check(i, j);
			s << cs << " ";
		}
		s << std::endl;
	}
	return s;
}
