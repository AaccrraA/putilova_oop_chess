#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "CompositePiece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"

class Board
{
public:
	Board();
	~Board();

	void Print();

	bool IsInCheck(char color);

	bool CanMove(char color);

	void UpdateCompositePiece(CompositePiece* side) {
		char color = side->GetColor();
		delete side;
		side = CreateComposite(color);
	}

	Piece* board[8][8];
	CompositePiece* white;
	CompositePiece* black;
private:
	CompositePiece* CreateComposite(char color) {
		CompositePiece* side = new CompositePiece(color);
		for (int i = 0; i < 8; ++i)
			side->addPiece(new Pawn(color));
		for (int i = 0; i < 2; ++i) {
			side->addPiece(new Rook(color));
			side->addPiece(new Knight(color));
			side->addPiece(new Bishop(color));
		}
		side->addPiece(new Queen(color));
		side->addPiece(new King(color));
		return side;
	}
};

#endif