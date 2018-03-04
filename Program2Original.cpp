//Describe program

// PUT YOUR NAME HERE

#include <iostream>
#include <cstdlib>

using namespace std;

void displayBoard (char* board);
bool isWinning (char* board, char player);
void getMove (char* board, char player);
bool isEven (int digit);
char* setupGame ();
int play1PGame ();
int play2PGame ();
void swap (char& current, char& old);


int main ()
{
	int winner,				// Which player won?
		numPlayers;			// Number of players (1 or 2)

	cout << "Welcome to Doc Brown's Tic-Tac-Toe" << endl;
	cout << "Enter your selection from the options below..." << endl;

	cout << endl << " 1. 1 Player Game" << endl;
	cout << " 2. 2 Player Game" << endl;
	cout << " 3. Exit" << endl;
	cout << "Enter your choice : ";

	cin >> numPlayers;

	switch (numPlayers)
	{
		case 1 : cout << "Sorry, but that is not an option ... yet" << endl;
				 return 0;
		case 2 : winner = play2PGame ();
				 break;
		case 3 : cout << "Have a great day" << endl;
				 return 0;
		default : cout << "That is an invalid option.  Please try again" << endl;
				  return 0;
	}

	if (winner == 1)
	{
		cout << "Congrats X, you win!" << endl;
	}
	else if (winner == 2)
	{
		cout << "Congrats O, you win!" << endl;
	}
	else
	{
		cout << "Oh no! It was a tie!" << endl;
	}

	return 0;

}

void displayBoard (char* board)
{
	system ("CLS");
	cout << "   |   |   " << endl;
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "   |   |   " << endl;
	cout << "-----------" << endl;
	cout << "   |   |   " << endl;
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "   |   |   " << endl;
	cout << "-----------" << endl;
	cout << "   |   |   " << endl;
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << "   |   |   " << endl;
}

bool isEven (int digit)
{
	if (digit % 2 == 0)
		return true;
	return false;
}

bool isWinning (char* board, char player)
{
	if (
		(board[0] == player && board[1] == player && board[2] == player) ||
		(board[3] == player && board[4] == player && board[5] == player) ||
		(board[6] == player && board[7] == player && board[8] == player) ||
		(board[0] == player && board[3] == player && board[6] == player) ||
		(board[1] == player && board[4] == player && board[7] == player) ||
		(board[2] == player && board[5] == player && board[8] == player) ||
		(board[0] == player && board[4] == player && board[8] == player) ||
		(board[2] == player && board[4] == player && board[6] == player)
 		) 
		return true;
  	else 
 		return false;
}

void getMove (char* board, char player)
{
	int userChoice;

	do {
		cout << "It is " << player <<"'s turn - pick a space : ";
		cin >> userChoice;
	} while (userChoice <= 0 || userChoice >= 10 || board[userChoice - 1] == 'O' || board[userChoice -1] == 'X');
	board[userChoice - 1] = player;
}

char* setupGame ()
{
	char* board = new char[10];
	for (int i = 0; i < 9; i++)
		board[i] = '0' + (i + 1);
	return board;
}

void swap (char& current, char& old)
{
	char rearrange;
	rearrange = current;
	current = old;
	old = rearrange;
}
int evaluate (char* board, int player)
{

}
int play1PGame ()
{
	int moves = 1;
	bool winner = false;
	char* board = setupGame ();
	int player = 1;

}

int play2PGame ()
{
	int moves = 1;
	bool winner = false; 
	char* board = setupGame ();
	char player = 'X';
	char lastPlayer = 'O';

	displayBoard (board);
	do {

		getMove (board, player);
		moves++;
		winner = isWinning (board, player);
		swap (player, lastPlayer);
		displayBoard (board);
	} while (moves <= 9 && !(winner));
	if (!winner)
		return 3;
	else if (isEven(moves))
		return 1; 
	else if (isEven (moves - 1))
		return 2;

}