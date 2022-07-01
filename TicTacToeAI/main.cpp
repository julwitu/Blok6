#include "TicTacToeAI.hpp"

int main() {
	std::cout << "Czy pierwszy gracz to AI (Y/N): " << std::endl;
	char choice;
	std::cin >> choice;
	Player* p1;
	Player* p2;
	if (choice == 'Y') {
		p1 = new AIPlayer(CheckerState::O);
	}
	else {
		p1 = new HumanPlayer(CheckerState::X);
	}

	std::cout << "Czy drugi gracz to AI (Y/N): " << std::endl;
	std::cin >> choice;
		if (choice == 'Y') {
		p2 = new AIPlayer(CheckerState::O);
	}
	else {
		p2 = new HumanPlayer(CheckerState::X);
	}

	Game g(p1, p2);

	g.start();
	g.reset();
	delete p1;
	delete p2;

}