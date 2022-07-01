#include "TicTacToeAI.hpp"
#include <random>

std::ostream& operator<<(std::ostream& s, const Board& board) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			s << board.check(i, j) << " ";
		} s << std::endl;
	}
	return s;
}

std::ostream& operator<<(std::ostream& s, const CheckerState& cs) {
	if (cs == CheckerState::empty)
		s << "-";
	else if (cs == CheckerState::X)
		s << "X";
	else if (cs == CheckerState::O)
		s << "O";
	return s;
}

Board::Board()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			table[i][j] = CheckerState::empty;
		}
	}
}
CheckerState Board::check(int x, int y) const
{
	return table[x][y];
}

Game::Game(Player* p1, Player* p2) {
	player1 = p1;
	player2 = p2;
	currentPlayer = player1;
}
bool Board::isOver() {
	bool isOver = false;
	if (this->isOverRows() || this->isOverCols() || this->isOverDiagonals())
		isOver = true;
	return isOver;
}
bool Board::isOverRows() {
	bool isOver = false;
	if ((table[0][0] != CheckerState::empty && table[0][0] == table[0][1] && table[0][1] == table[0][2]) || (table[1][0] != CheckerState::empty && table[1][0] == table[1][1] && table[1][1] == table[1][2]) || (table[2][0] != CheckerState::empty && table[2][0] == table[2][1] && table[2][1] == table[2][2]))
		isOver = true;
	return isOver;
}
bool Board::isOverCols() {
	bool isOver = false;
	if ((table[0][0] != CheckerState::empty && table[0][0] == table[1][0] && table[1][0] == table[2][0]) || (table[0][1] != CheckerState::empty && table[0][1] == table[1][1] && table[1][1] == table[2][1]) || (table[0][2] != CheckerState::empty && table[0][2] == table[1][2] && table[1][2] == table[2][2]))
		isOver = true;
	return isOver;
}
bool Board::isOverDiagonals() {
	bool isOver = false;
	if ((table[0][0] != CheckerState::empty && table[0][0] == table[1][1] && table[1][1] == table[2][2]) || (table[0][2] != CheckerState::empty && table[0][2] == table[1][1] && table[1][1] == table[2][0]))
		isOver = true;
	return isOver;
}

bool Board::xWon() {
	return true;
}
void Game::start() {
	do {
		this->swapPlayer();
		currentPlayer->makeTurn(&board);
		std::cout << board;
	} while (!board.isOver());
}


bool Board::set(CheckerState cs, int x, int y) {
	if (table[x][y] == CheckerState::empty)
		table[x][y] = cs;
	return true;
}

HumanPlayer::HumanPlayer(CheckerState _colour) : Player(_colour)
{
}

bool HumanPlayer::makeTurn(Board* board) {
	int x;
	int y;
	std::cout << "Ktore pole wybierasz(x): " << std::endl;
	std::cin >> x;
	std::cout << "Ktore pole wybierasz(y): " << std::endl;
	std::cin >> y;
	if (x >= 0 && x < 3 && y >= 0 && y < 3)
		board->set(this->colour, x, y);
	return true;
}
void Game::swapPlayer() {
	if (currentPlayer == player1) {
		currentPlayer = player2;
	}
	else if (currentPlayer == player2) {
		currentPlayer = player1;
	}
}
Player::Player(CheckerState _colour) : colour(_colour) {};

void Game::reset() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board.set(CheckerState::empty, i, j);
		}
	}
}

AIPlayer::AIPlayer(CheckerState _colour) : Player(_colour)
{
}

bool AIPlayer::makeTurn(Board* board)
{

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 2); // define the range

	bool tableAvailables[3][3];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (board->check(i, j) == CheckerState::empty) {
				tableAvailables[i][j] = true;
			}
			else {
				tableAvailables[i][j] = false;
			}
		}
	}

	board->set(colour, distr(gen), distr(gen));
	return true;
}



