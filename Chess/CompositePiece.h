#ifndef COMPOSITEPIECE_H
#define COMPOSITEPIECE_H

#include <vector>
#include <assert.h>
#include "Piece.h"

class CompositePiece : public Piece
{
public:
	CompositePiece(char color) : Piece(color) {}
	~CompositePiece() {
		for (int i = 0; i<c.size(); ++i)
			delete c[i];
	}

	int getValue () {
		int total = 0;
		for (int i = 0; i<c.size(); ++i)
			total += c[i]->getValue();
		return total;
	}

	void addPiece(Piece* p) {
		c.push_back(p);
	}

	char GetPiece() { assert(false); return NULL; }

private:
	bool AreSquaresLegal(int srcRow, int srcCol, int destRow, int destCol, Piece* board[8][8]) { assert(false); return NULL; }
	std::vector<Piece*> c;
};

#endif