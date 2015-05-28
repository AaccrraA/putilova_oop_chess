#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(char color) : Piece(color) {}
	~Pawn() {}

private:
	char GetPiece() {
		return 'P';
	}

	int getValue() {
		return 1;
	}

	bool AreSquaresLegal(int srcRow, int srcCol, int destRow, int destCol, Piece* board[8][8]) {
		Piece* qpDest = board[destRow][destCol];
		if (qpDest == 0) {
			// Destination square is unoccupied
			if (srcCol == destCol) {
				if (GetColor() == 'W') {
					if (destRow == srcRow + 1) {
						return true;
					}
				}
				else {
					if (destRow == srcRow - 1) {
						return true;
					}
				}
			}
		}
		else {
			// Dest holds piece of opposite color
			if ((srcCol == destCol + 1) || (srcCol == destCol - 1)) {
				if (GetColor() == 'W') {
					if (destRow == srcRow + 1) {
						return true;
					}
				}
				else {
					if (destRow == srcRow - 1) {
						return true;
					}
				}
			}
		}
		return false;
	}
};

#endif