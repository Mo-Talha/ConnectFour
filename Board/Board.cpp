#include "Board.h"
#include "../Algorithms/Minmax.cpp"

Board::Board(){
	//Initialize board with 0
	for (int c = 0; c < column; c++){
		for (int r = 0; r < row; r++) board[c][r] = 0;
	}
}

Player Board::getActivePlayer(){
	return activePlayer;
}

Board Board::getVirtualBoard(int c){
	
	Board newBoard = *this;

	newBoard.insert(c);

	//Switch player turns
	if (newBoard.activePlayer == AI) newBoard.activePlayer = HUMAN;
		else newBoard.activePlayer = AI;

	return newBoard;

}

void Board::print (){
	
	for (int k = 0; k < column; k++) cout << "  " << k;
	
	cout << "\n";
	
	for (int r = 0; r < row; r++){
		
		cout << r;
		
		for (int c = 0; c < column; c++){
			
			cout << "|";

			switch (board[c][r]){
				case 1:
					cout << "X";
					break;
				case 2:
					cout << "O";
					break;
				default:
					cout << " ";
					break;
			} 
			
			cout << "|";

			if (c == (column - 1)) cout << endl; 

		}
	}
}

bool Board::valid(int c){
	return board[c][0] == 0 ? true:false;
}

Player Board::win(){

	int verticalNumHuman = 0, verticalNumAI = 0;

	for (int c = 0; c < column; c++){
		for (int r = 0; r < row; r++){
		
			//Search vertically
			if (board[c][r] == 1){
				verticalNumHuman++;
				verticalNumAI = 0;
			} else {
				verticalNumHuman = 0;
			}

			if (board[c][r] == 2){
				verticalNumAI++;
				verticalNumHuman = 0;
			} else {
				verticalNumAI = 0;
			}

			//Search for any winning player
			if (verticalNumHuman == 4) return HUMAN;

			if (verticalNumAI == 4) return AI;
			
		}
	}

	int horizontalNumHuman = 0, horizontalNumAI = 0;

	for (int r = 0; r < row; r++){
		for (int c = 0; c < column; c++){

			//Search horizontally
			if (board[c][r] == 1){
				horizontalNumHuman++;
				horizontalNumAI = 0;
			} else {
				horizontalNumHuman = 0;
			}

			if (board[c][r] == 2){
				horizontalNumAI++;
				horizontalNumHuman = 0;
			} else {
				horizontalNumAI = 0;
			}

			//Search for any winning player
			if (horizontalNumHuman == 4) return HUMAN;
			
			if (horizontalNumAI == 4) return AI;
			
		}
	}

	for (int c = 0; c < row; c++){
		for (int r = 0; r < column; r++){

		int positiveDiagonalNumHuman = 0, positiveDiagonalNumAI = 0, negativeDiagonalNumHuman = 0, negativeDiagonalNumAI = 0;

				//Check negative diagonal
				if (((column - 1) - c) >= 3 && ((row - 1) - r) >= 3){
					for (int i = 0; i < 4; i++){

						if (board[c + i][r + i] == 1){
							negativeDiagonalNumHuman++;
							negativeDiagonalNumAI = 0;
						} else {
							negativeDiagonalNumHuman = 0;
						}

						if (board[c + i][r + i] == 2){
							negativeDiagonalNumAI++;
							negativeDiagonalNumHuman = 0;
						} else {
							negativeDiagonalNumAI = 0;
						}

						//Search for any winning player
						if (negativeDiagonalNumHuman == 4) return HUMAN;
					
						if (negativeDiagonalNumAI == 4) return AI;
						
					}	

				//Check positive diagonal
				} 

				if (((column - 1) - c) >= 3 && ((row - 1) - r) <= 2) {

					for (int i = 0; i < 4; i++){

						if (board[c + i][r - i] == 1){
							positiveDiagonalNumHuman++;
							positiveDiagonalNumAI = 0;
						} else {
							positiveDiagonalNumHuman = 0;
						}

						if (board[c + i][r - 1] == 2){
							positiveDiagonalNumAI++;
							positiveDiagonalNumHuman = 0;
						} else {
							positiveDiagonalNumAI = 0;
						}

						//Search for any winning player
						if (positiveDiagonalNumHuman == 4) return HUMAN;
						
						if (positiveDiagonalNumAI == 4) return AI;
						
					}

				}
			}
		}

	return NONE;

}

void Board::insert(int c){
	for (int r = (row - 1); r >= 0; r--){
		if (board[c][r] == 0){
			if (activePlayer == HUMAN) board[c][r] = 1;
				else if (activePlayer == AI) board[c][r] = 2; 
			break;
		}
	}	
}

void Board::insertHuman(int c){
	activePlayer = HUMAN;
	insert(c);
}

void Board::insertAI(){
	activePlayer = AI;

	//If player wins, exit
	if (win() == HUMAN) return;

	//Make parent node and initialize to 0
	Node head;
	head.score = 0;
	head.move = 0;
	head.depth = 0;

	//Implement minMax algorithm to find best move
	minmax(*this, head);

	insert(bestMove);
}