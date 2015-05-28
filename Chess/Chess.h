#ifndef CHESS_H
#define CHESS_H

#include <iostream>
#include "Board.h"

class Chess
{
public:
	static Chess& instance();

	void Start();

	void GetNextMove(Piece* board[8][8]);

	void AlternateTurn();

	bool IsGameOver();

	void PrintStatistic();

protected:
	static Chess Instance;
private:
	Chess() : playerTurn('W') {}
	~Chess() {}
	Board gameBoard;
	char playerTurn;
};

#endif