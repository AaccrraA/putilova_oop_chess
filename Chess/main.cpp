#include <iostream>
#include <vector>
#include "Chess.h"
#include "StartGameCommand.h"

int main() {
	std::vector<Command*> v;
	v.push_back(new StartGameCommand(&Chess::instance()));
	v[0]->execute();
	return 0;
}