using namespace std;

#include <iostream>
#include "Board/Board.cpp"

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