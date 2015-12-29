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

		Player getActivePlayer();

		void print ();

		bool valid(int c);

		Player win();

		void insert(int c);

		void insertHuman(int c);

		void insertAI();

};