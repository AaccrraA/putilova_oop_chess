#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(char color) : Piece(color) {}
	~Bishop() {}

private:
	char GetPiece() {
		return 'B';
	}

	int getValue() {
		return 3;
	}

	bool AreSquaresLegal(int srcRow, int srcCol, int destRow, int destCol, Piece* board[8][8]) {
		if ((destCol - srcCol == destRow - srcRow) || (destCol - srcCol == srcRow - destRow)) {
			// Make sure that all invervening squares are empty
			int rowOffset = (destRow - srcRow > 0) ? 1 : -1;
			int colOffset = (destCol - srcCol > 0) ? 1 : -1;
			int checkRow;
			int checkCol;
			for (checkRow = srcRow + rowOffset, checkCol = srcCol + colOffset;
				checkRow != destRow;
				checkRow = checkRow + rowOffset, checkCol = checkCol + colOffset)
			{
				if (board[checkRow][checkCol] != 0) {
					return false;
				}
			}
			return true;
		}
		return false;
	}
};

#endif