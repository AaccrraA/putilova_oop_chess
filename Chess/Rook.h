#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(char color) : Piece(color) {}
	~Rook() {}

private:
	char GetPiece() {
		return 'R';
	}

	int getValue() {
		return 5;
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
		return false;
	}
};

#endif