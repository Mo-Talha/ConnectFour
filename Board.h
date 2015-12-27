const int column = 7;
const int row = 6;

enum Player {HUMAN, AI, NONE};

class Board {

	private:
		
		int board[column][row];
		
		Player activePlayer;
		
	public:

		Board();

		Board getVirtualBoard(int c);

		void print ();

		bool valid(int c);

		Player win();

		void insertHuman(int c);

		int minmax(Board board);

		void insertAI();

};