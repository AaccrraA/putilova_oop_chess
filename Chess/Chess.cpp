#include <iostream>
#include "Chess.h"

using namespace std;

Chess Chess::Instance;

Chess& Chess::instance() {
	return Instance;
}

void Chess::Start() {
	do {
		GetNextMove(gameBoard.board);
		AlternateTurn();
	} while (!IsGameOver());
	gameBoard.Print();
}
	
void Chess::GetNextMove(Piece* board[8][8]) {
	using namespace std;
	bool validMove = false;
	do {
		PrintStatistic();
		gameBoard.Print();

		// Get input and convert to coordinates
		cout << playerTurn << "'s Move: ";
		int startMove;
		cin >> startMove;
		int startRow = (startMove / 10) - 1;
		int iStartCol = (startMove % 10) - 1;

		cout << "To: ";
		int endMove;
		cin >> endMove;
		int endRow = (endMove / 10) - 1;
		int endCol = (endMove % 10) - 1;

		// Check that the indices are in range
		// and that the source and destination are different
		if ((startRow >= 0 && startRow <= 7) &&	(iStartCol >= 0 && iStartCol <= 7) && (endRow >= 0 && endRow <= 7) && (endCol >= 0 && endCol <= 7)) {
			// Additional checks in here
			Piece* currPiece = board[startRow][iStartCol];
			// Check that the piece is the correct color
			if ((currPiece != 0) && (currPiece->GetColor() == playerTurn)) {
				// Check that the destination is a valid destination
				if (currPiece->IsLegalMove(startRow, iStartCol, endRow, endCol, board)) {
					// Make the move
					Piece* qpTemp = board[endRow][endCol];
					board[endRow][endCol] = board[startRow][iStartCol];
					board[startRow][iStartCol] = 0;
					// Make sure that the current player is not in check
					if (!gameBoard.IsInCheck(playerTurn)) {
						delete qpTemp;
						validMove = true;
					}
					else { // Undo the last move
						board[startRow][iStartCol] = board[endRow][endCol];
						board[endRow][endCol] = qpTemp;
					}
				}
			}
		}
		if (!validMove) {
			cout << "Invalid Move!" << endl;
		}
	} while (!validMove);
}

void Chess::AlternateTurn() {
	playerTurn = (playerTurn == 'W') ? 'B' : 'W';
}

bool Chess::IsGameOver() {
	// Check that the current player can move
	// If not, we have a stalemate or checkmate
	bool canMove(false);
	canMove = gameBoard.CanMove(playerTurn);
	if (!canMove) {
		if (gameBoard.IsInCheck(playerTurn)) {
			AlternateTurn();
			std::cout << "Checkmate, " << playerTurn << " Wins!" << std::endl;
		}
		else {
			std::cout << "Stalemate!" << std::endl;
		}
	}
	return !canMove;
}

void Chess::PrintStatistic() {
	int blackValue = gameBoard.black->getValue();
	int whiteValue = gameBoard.white->getValue();
	std::cout << "Piece values of black: " << blackValue << endl;
	std::cout << "Piece values of white: " << whiteValue << endl;
}