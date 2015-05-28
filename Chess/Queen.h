#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(char color) : Piece(color) {}
	~Queen() {}

private:
	char GetPiece() {
		return 'Q';
	}

	int getValue() {
		return 10;
	}

	bool AreSquaresLegal(int srcRow, int srcCol, int destRow, int destCol, Piece* board[8][8]) {
		if (srcRow == destRow) {
			// Make sure that all invervening squares are empty
			int colOffset = (destCol - srcCol > 0) ? 1 : -1;
			for (int checkCol = srcCol + colOffset; checkCol != destCol; checkCol = checkCol + colOffset) {
				if (board[srcRow][checkCol] != 0) {
					return false;
				}
			}
			return true;
		}
		else if (destCol == srcCol) {
			// Make sure that all invervening squares are empty
			int rowOffset = (destRow - srcRow > 0) ? 1 : -1;
			for (int checkRow = srcRow + rowOffset; checkRow != destRow; checkRow = checkRow + rowOffset) {
				if (board[checkRow][srcCol] != 0) {
					return false;
				}
			}
			return true;
		}
		else if ((destCol - srcCol == destRow - srcRow) || (destCol - srcCol == srcRow - destRow)) {
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