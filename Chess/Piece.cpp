#include "Piece.h"

char Piece::GetColor() {
	return _color;
}

bool Piece::IsLegalMove(int srcRow, int srcCol, int destRow, int destCol, Piece* board[8][8]) {
	Piece* qpDest = board[destRow][destCol];
	if ((qpDest == 0) || (_color != qpDest->GetColor())) {
		return AreSquaresLegal(srcRow, srcCol, destRow, destCol, board);
	}
	return false;
}