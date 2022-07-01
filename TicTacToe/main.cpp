#include "TicTacToe.hpp"

int main() {
	Player* p1 = new Player(CheckerState::X);
	Player* p2 = new Player(CheckerState::O);

	Game g(p1, p2);

	g.start();
	g.reset();
	delete p1;
	delete p2;

}