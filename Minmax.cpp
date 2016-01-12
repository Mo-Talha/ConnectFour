struct Node {
	int score, move, depth;
};

int bestMove = 0;

int numOfValidNodes(Board board){
	int validMoves = 0;
	for (int i = 0; i < column; i++){
		if (board.valid(i)) validMoves++;
	}
	return validMoves;
}

Node maxNode(Node nodes[], int length){
	Node highestScoreNode = nodes[0];
	for (int i = 0; i < length; i++){
		if (nodes[i].score > highestScoreNode.score){
			highestScoreNode = nodes[i];
		}
	}
	return highestScoreNode;
}

Node minNode(Node nodes[], int length){
	Node lowestScoreNode = nodes[0];
	for (int i = 0; i < length; i++){
		if (nodes[i].score < lowestScoreNode.score){
			lowestScoreNode = nodes[i];
		}
	}
	return lowestScoreNode;
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

int minmax(Board board, Node node){

	//Print for debugging
	board.print();

	//If we reach a node where a player wins, return the win state
	if (board.win() != NONE || node.depth == 1) return score(board);

	//Get number of valid moves and create relevant nodes
	Node nodes[numOfValidNodes(board)];
	int nodeIndx = 0;

	//Set depth to parent node
	for (int i = 0; i < column; i++) nodes[i].depth = node.depth;

	//Loop through each valid move
	for (int c = 0; c < column; c++){
		if (board.valid(c)){

			//Create new game state with valid move played
			Board possibleGame = board.getVirtualBoard(c);

			//Incrament depth after virtual move played
			nodes[nodeIndx].depth++;

			//Get relevant score for 'possibleGame' and store in node
			nodes[nodeIndx].score = minmax(possibleGame, nodes[nodeIndx]);

			//Store valid move in node
			nodes[nodeIndx].move = c;

			nodeIndx++;

		}
	}

	//If it is AI's turn to move
	//Maximize score	
	if (board.getActivePlayer() == AI){

		Node highestScoreNode = maxNode(nodes, nodeIndx + 1);

		bestMove = highestScoreNode.move;

		return highestScoreNode.score;

	//If it is human's turn to move
	//Minimize score
	} else {

		Node lowestScoreNode = minNode(nodes, nodeIndx + 1);

		bestMove = lowestScoreNode.move;

		return lowestScoreNode.score;

	}

}