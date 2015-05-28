#ifndef PIECE_H
#define PIECE_H

class Piece
{
public:
	Piece(char color) : _color(color) {}
	~Piece() {}
	
	virtual char GetPiece() = 0;
	
	virtual int getValue() = 0;

	char GetColor();
	
	bool IsLegalMove(int srcRow, int srcCol, int destRow, int destCol, Piece* board[8][8]);

private:
	
	virtual bool AreSquaresLegal(int srcRow, int srcCol, int destRow, int destCol, Piece* board[8][8]) = 0;
	
	char _color;
};

#endif