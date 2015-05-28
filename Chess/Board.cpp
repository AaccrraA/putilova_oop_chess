#include "Board.h"

Board::Board() {
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			board[row][col] = 0;
		}
	}
	// Allocate and place black pieces
	for (int col = 0; col < 8; ++col) {
		board[6][col] = new Pawn('B');
	}
	board[7][0] = new Rook('B');
	board[7][1] = new Knight('B');
	board[7][2] = new Bishop('B');
	board[7][3] = new King('B');
	board[7][4] = new Queen('B');
	board[7][5] = new Bishop('B');
	board[7][6] = new Knight('B');
	board[7][7] = new Rook('B');
	// Allocate and place white pieces
	for (int col = 0; col < 8; ++col) {
		board[1][col] = new Pawn('W');
	}
	board[0][0] = new Rook('W');
	board[0][1] = new Knight('W');
	board[0][2] = new Bishop('W');
	board[0][3] = new King('W');
	board[0][4] = new Queen('W');
	board[0][5] = new Bishop('W');
	board[0][6] = new Knight('W');
	board[0][7] = new Rook('W');

	// For statistic
	white = CreateComposite('W');
	black = CreateComposite('B');
}

Board::~Board() {
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			delete board[row][col];
			board[row][col] = 0;
		}
	}
}

void Board::Print() {
	using namespace std;
	cout << endl << endl;
	const int squareWidth = 4;
	const int squareHeight = 3;
	for (int row = 0; row < 8 * squareHeight; ++row) {
		int squareRow = row / squareHeight;
		// Print side border with numbering
		if (row % 3 == 1) {
			cout << '-' << (char)('1' + 7 - squareRow) << '-';
		}
		else {
			cout << "---";
		}
		// Print the chess board
		for (int col = 0; col < 8 * squareWidth; ++col) {
			int squareCol = col / squareWidth;
			if (((row % 3) == 1) && ((col % 4) == 1 || (col % 4) == 2) && board[7 - squareRow][squareCol] != 0) {
				if ((col % 4) == 1) {
					cout << board[7 - squareRow][squareCol]->GetColor();
				}
				else {
					cout << board[7 - squareRow][squareCol]->GetPiece();
				}
			}
			else {
				if ((squareRow + squareCol) % 2 == 1) {
					cout << '*';
				}
				else {
					cout << ' ';
				}
			}
		}
		cout << endl;
	}
	// Print the bottom border with numbers
	for (int row = 0; row < squareHeight; ++row) {
		if (row % 3 == 1) {
			cout << "---";
			for (int col = 0; col < 8 * squareWidth; ++col) {
				int squareCol = col / squareWidth;
				if ((col % 4) == 1) {
					cout << (squareCol + 1);
				}
				else {
					cout << '-';
				}
			}
			cout << endl;
		}
		else {
			for (int col = 1; col < 9 * squareWidth; ++col) {
				cout << '-';
			}
			cout << endl;
		}
	}
}

bool Board::IsInCheck(char color) {
	// Find the king
	int kingRow;
	int kingCol;
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			if (board[row][col] != 0) {
				if (board[row][col]->GetColor() == color) {
					if (board[row][col]->GetPiece() == 'K') {
						kingRow = row;
						kingCol = col;
					}
				}
			}
		}
	}
	// Run through the opponent's pieces and see if any can take the king
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			if (board[row][col] != 0) {
				if (board[row][col]->GetColor() != color) {
					if (board[row][col]->IsLegalMove(row, col, kingRow, kingCol, board)) {
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool Board::CanMove(char color) {
	// Run through all pieces
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			if (board[row][col] != 0) {
				// If it is a piece of the current player, see if it has a legal move
				if (board[row][col]->GetColor() == color) {
					for (int moveRow = 0; moveRow < 8; ++moveRow) {
						for (int moveCol = 0; moveCol < 8; ++moveCol) {
							if (board[row][col]->IsLegalMove(row, col, moveRow, moveCol, board)) {
								// Make move and check whether king is in check
								Piece* qpTemp = board[moveRow][moveCol];
								board[moveRow][moveCol] = board[row][col];
								board[row][col] = 0;
								bool canMove = !IsInCheck(color);
								// Undo the move
								board[row][col] = board[moveRow][moveCol];
								board[moveRow][moveCol] = qpTemp;
								if (canMove) {
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}