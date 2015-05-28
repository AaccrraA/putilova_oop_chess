#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
public:
	King(char color) : Piece(color) {}
	~King() {}

private:
	
	char GetPiece() {
		return 'K';
	}

	int getValue() {
		return 4;
	}

	bool AreSquaresLegal(int srcRow, int srcCol, int destRow, int destCol, Piece* board[8][8]) {
		int rowDelta = destRow - srcRow;
		int colDelta = destCol - srcCol;
		if (((rowDelta >= -1) && (rowDelta <= 1)) &&
			((colDelta >= -1) && (colDelta <= 1)))
		{
			return true;
		}
		return false;
	}
};

#endif