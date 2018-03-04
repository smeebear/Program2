// Game of Tic-Tac-Toe that stores a historical number
// of wins, losses, and ties in a text document

// Sam O'Heron

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void displayBoard (char* board);
bool isWinning (char* board, char player);
void getMove (char* board, char player);
bool isEven (int digit);
char* setupGame ();
int play1PGame ();
int play2PGame ();
void swap (char& current, char& old);
void fileInOut (int winX, int winO, int ties);



int main ()
{
	int winner = 0,																	// Which player won?
		numPlayers,																	// Number of players (1 or 2)
		winX,																		// Wins by X this session
		winO,																		// Wins by O this session
		ties;																		// Ties this session
		
	do 																				// Executes the menu until numPlayers is 3
	{
		cout << "Welcome to Doc Brown's Tic-Tac-Toe" << endl;
		cout << "Enter your selection from the options below..." << endl;

		cout << endl << " 1. 1 Player Game" << endl;
		cout << " 2. 2 Player Game" << endl;
		cout << " 3. Exit" << endl;
		cout << "Enter your choice : ";

		cin >> numPlayers;


		switch (numPlayers)
		{
			case 1 : cout << "Sorry, but that is not an option ... yet\n" << endl;													
					 break;															
			case 2 : winner = play2PGame ();
					 cout << "My value is " << winner << endl;
					 break;															
			case 3 : cout << "\nHave a great day" << endl;
					 break;
			default : cout << "That is an invalid option.  Please try again\n" << endl;
					 break;
		}

		if (winner == 1)
		{
			cout << "Congrats X, you win!" << endl;
			winX++;																	// Increments the number of times X has won this session
			winner = 0;																// Resets winner
		}
		else if (winner == 2)
		{
			cout << "Congrats O, you win!" << endl;
			winO++;																	// Increments the number of times O has won this session
			winner = 0;																// Resets winner
		}		
		else if (winner == 3)
		{
			cout << "Oh no! It was a tie!" << endl;
			ties++;																	// Increments number of times the players have tied this session
			winner = 0;																// Resets winner
		}
	} while (numPlayers !=3);														// Repeats the do while until the user enters 3

	cout << "Player X won " << winX << " times!" << endl;
	cout << "Player O won " << winO << " times!" << endl;
	cout << "The players tied " << ties << " times." << endl;

	fileInOut (winX, winO, ties); 													// Controls writing the history to the file

	return 0;

}

void displayBoard (char* board)
{
	system ("clear");																// CHANGE BACK TO "CLS"!!!!!!
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

void fileInOut (int winX, int winO, int ties)
{
	int totalX,																		// Historical X wins
		totalO,																		// Historical O wins
		totalTie;																	// Historical ties
	ifstream inFile;
	ofstream outFile;

	inFile.open("TTTStats.txt");													// Opens the file
	inFile >> totalX;																// Reads in all the values, which are
	inFile >> totalO;																// stored in order of X, O, and Ties
	inFile >> totalTie;
	inFile.close();																	// Closes the file

	totalX += winX;																	// Adds the wins from the current session
	totalO += winO;																	// to the historical running total
	totalTie += ties;

	cout << "\nPlayer X has won " << totalX << " times in total!" << endl;			// Prints the history, an extra step so I
	cout << "Player O has won " << totalO << " times in total!" << endl;			// wouldn't have to check the file each time
	cout << "The players have tied " << totalTie << " times overall." << endl;

	outFile.open("TTTStats.txt");													// Writes all the values into TTTStats.txt
	outFile << totalX << endl;														// in order (X,O,Tie)
	outFile << totalO << endl;
	outFile << totalTie << endl;
	outFile.close();																// Closes the file and ends the function
}