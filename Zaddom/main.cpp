#include "Zaddom.hpp"

int main()
{
	Player* p1 = new Player(CheckerState::X);
	Player* p2 = new Player(CheckerState::O);
	Game g(p1, p2);
	g.start();
	delete p1;
	delete p2;
	return 0;
}