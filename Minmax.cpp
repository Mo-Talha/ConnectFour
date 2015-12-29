int bestMove = 0;

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

int minmax(Board board){

	//If we reach a node where a player wins, return the win state
	if (board.win() != NONE) return score(board);

	//Array that stores the score for each immediate possible move
	int scores[column] = {0};
	int scoresIndx = 0;

	//Array that stores the index for each immediate possible move
	int moves[column] = {0};
	int movesIndx = 0;

	//Loop through each valid move
	for (int c = 0; c < column; c++){
		//If move is valid
		if (board.valid(c)){

			//Create new game state with valid move played
			Board possibleGame = board.getVirtualBoard(c);

			//Get relevant score for 'possibleGame' and store in score array
			scores[scoresIndx++] = minmax(possibleGame);

			//Store each valid move in move array
			moves[movesIndx++] = c;

		}
	}

	//If it is AI's turn to move
	//Maximize score
	if (board.getActivePlayer() == AI){

		//Max score index
		int maxScoreIndx;



	//If it is human's turn to move
	} else {



	}



}