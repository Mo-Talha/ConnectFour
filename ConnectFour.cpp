#include <iostream>
#include <limits>

//This is a change.

using namespace std;

const int column = 7;
const int row = 6;

enum Player {HUMAN, AI, NONE};

class Board {

	private:
		
		int board[column][row];
		Player player;
		
	public:

		Board(){
			//Initialize board
			for (int c = 0; c < column; c++){
				for (int r = 0; r < row; r++){
					board[c][r] = 0;
				}
			}
		}

		void print (){
			for (int k = 0; k < column; k++){
				cout << "  " << k;
			} 
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

		bool valid(int c){
			return board[c][0] == 0 ? true:false;
		}

		Player win(){
			
			int verticalNumHuman = 0, verticalNumAI = 0;

			for (int c = 0; c < column; c++){
				for (int r = 0; r < row; r++){

					if (verticalNumAI == 4){
						return AI;
					}

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
					if (verticalNumHuman == 4){
						return HUMAN;
					}

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
					if (horizontalNumHuman == 4){
						return HUMAN;
					}

					if (horizontalNumAI == 4){
						return AI;
					}

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
		 					if (negativeDiagonalNumHuman == 4){
		 						return HUMAN;
		 					}

		 					if (negativeDiagonalNumAI == 4){
		 						return AI;
		 					}

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
		 					if (positiveDiagonalNumHuman == 4){
		 						return HUMAN;
		 					}

		 					if (positiveDiagonalNumAI == 4){
		 						return AI;
		 					}

 						}

 					}

				}
			}

			return NONE;
		}

		void insertHuman(int c){
			player = HUMAN;
			for (int r = (row - 1); r >= 0; r--){
				if (board[c][r] == 0){
					board[c][r] = 1; 
					break;
				}
			}
		}

		int score(Board board){
			//Win = 1. Lose = -1. Draw = 0.
			Player plyr = board.win();
			if (plyr == AI){
				return 1;
			} else if (plyr == HUMAN){
				return -1;
			} else {
				return 0;
			}
		}

		int* getPossibleMoves(Board board){

			int* possibleMoves[column] = new int[column];
			int j = 0;

			for (int i = 0; i < column; i++){
				//If column is valid add to possibleMoves array
				if (board.valid(i)){
					possibleMoves[j++] = i;
				}
			}

			//Mark end of array as -1.
			possibleMoves[j] = -1;

			//Return head of array
			return possibleMoves;

		}

		int minmax(Board board){

			//If we reach a node where a player wins, return the win state
			if (win() != NONE) return score(board);

			//Array of size 7 that stores the score for each possible move. 7 max because 7 possible moves at max.
			int scores[7] = {0};

			int moves[7] = {0};





		}

		void insertAI(){
			//Implement minMax algorithm
			player = AI;

		}

};

int main (){

	cout << "Welcome to Muhammad Talha's Connect Four game! \n";
	cout << "Enter any key to get started. To exit type any non integer character." << endl;
	cin.get();

	Board board;

	int x = 0;

	cout << "Insert (x) : ";

	while (cin >> x){

		if (x < 0 || x > 6 || !board.valid(x)){
			cout << "Please enter a valid coordinate." << endl;
			continue;
		}

		cout << '\n';
		
		board.insertHuman(x);
		
		board.insertAI();
		
		board.print();

		if (board.win() == HUMAN){
			cout << "You won!" << endl;
			return 0;
		} else if (board.win() == AI){
			cout << "Unfortunately you lost. Better luck next time." << endl;
			return 0;
		}

		cout << '\n';

		cout << "Insert (x): ";

	}

	return 0;

}