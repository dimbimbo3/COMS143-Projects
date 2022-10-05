#include <iostream>
#include <iomanip>
using namespace std;

const int COLS = 3;
void boardSpots(int board[][COLS], const int);
void displayBoard(char playBoard[][COLS], const int);
void playerInput(char playBoard[][COLS], const int, const int);
void play(int board[][COLS], char playBoard[][COLS], const int);
bool wintest(char playBoard[][COLS], const int, const char);
bool playAgain();

void main(){
	const int ROWS = 3;
	bool win = false;
	bool contin = true;

	while(contin){
		int board[ROWS][COLS] = {{1,2,3},
								{4,5,6},
								{7,8,9}};
		char playBoard[ROWS][COLS] = {{'*','*','*'},
									  {'*','*','*'},
									  {'*','*','*'}};

		play(board, playBoard, ROWS);
		contin = playAgain();
	}
}

//Displays number spots on the board
void boardSpots(int board[][COLS], const int rows){
	cout << "__________" << endl;
	for(int x = 0; x < rows; x++){
		cout << "|";
		for(int y = 0; y < COLS; y++){
			cout << setw(2) << board[x][y] << "|";
		}
		cout << endl;
	}
	cout << "__________" << endl;
}

//Displays current play board
void displayBoard(char play[][COLS], const int rows){
	cout << "__________" << endl;
	for(int x = 0; x < rows; x++){
		cout << "|";
		for(int y = 0; y < COLS; y++){
			cout << setw(2) << play[x][y] << "|";
		}
		cout << endl;
	}
	cout << "__________" << endl;
}

//Asks where player wants to place their piece
void playerInput(int board[][COLS], char play[][COLS], const int rows, const char player){
	int place = 0;

	do{
		boardSpots(board, rows);
		cout << "Choose a spot on the board, 1 - 9:";
		cin >> place;
		switch(place){
		case 1:
				play[0][0] = player;
			break;
		case 2:
				play[0][1] = player;
			break;
		case 3:
				play[0][2] = player;
			break;
		case 4:
				play[1][0] = player;
			break;
		case 5:
				play[1][1] = player;
			break;
		case 6:
				play[1][2] = player;
			break;
		case 7:
				play[2][0] = player;
			break;
		case 8:
				play[2][1] = player;
			break;
		case 9:
				play[2][2] = player;
			break;
		default:
			cout << "\nINVALID INPUT" << endl;
			cout << endl;
		}
	}while(place != 1 && place != 2 && place != 3 && place != 4 && place != 5
		   && place != 6 && place != 7 && place != 8 && place != 9);
}

//Play menu & calls other functions
void play(int board[][COLS], char play[][COLS], const int rows){
	int input = 0;
	int turn = 1;
	char player = '.';
	int playernum = 0;
	bool win = false;

	do{
		if(turn == 1 || turn == 3 || turn == 5 || turn == 7 || turn == 9){
			player = 'X';
			playernum = 1;
		}
		else{
			player = 'O';
			playernum = 2;
		}
		cout << "Player #" << playernum << " - Pick a spot on the board to place your piece" << endl;
		cout << "Choose from the following menu:" << endl;
		cout << "1. print current board" << endl;
		cout << "2. enter spot to play" << endl;
		cin >> input;
		switch(input){
		case 1:
			displayBoard(play, rows);
			cout << endl;
			break;
		case 2:
			playerInput(board, play, rows, player);
			cout << endl;
			win = wintest(play, rows, player);
			if(win)
				cout << "Player #" << playernum <<" wins!" << endl;
			else
				turn++;
			break;
		default:
			cout << "\nINVALID INPUT" << endl;
			cout << endl;
		}
	}while(turn <= 9 && !win);

	if(!win)
		cout << "Draw: There is no winner..." << endl;
}

//Checks for winner
bool wintest(char play[][COLS], const int rows, const char player){
	bool win = false;

	int row = 0;
	while(row < rows && !win){
		int count = 0;
		for(int col = 0; col < COLS; col++){
			if(play[row][col] == player)
				count++;
		}
		if(count == 3)
			win = true;
		else
			row++;
	}

	int col = 0;
	while(col < COLS && !win){
		int count = 0;
		for(int row = 0; row < rows; row++){
			if(play[row][col] == player)
				count++;
		}
		if(count == 3)
			win = true;
		else
			col++;
	}

	if(play[0][0] == player && play[1][1] == player && play[2][2] == player && !win)
		win = true;
	
	if(play[2][0] == player && play[1][1] == player && play[0][2] == player && !win)
		win = true;

	return win;
}

//Asks if players want to play again
bool playAgain(){
	char input = '.';
	bool contin = false;

	do{
		cout << "\nWould you like to play again?" << endl;
		cout << "Do NOT include parenthesis with selection!" << endl;
		cout << "Please type (Y) to play again and (N) to quit:";
		cin >> input;
		switch(input){
		case 'y':
		case 'Y':
			contin = true;
			break;
		case 'n':
		case 'N':
			contin = false;
			break;
		default:
			cout << "\nINVALID INPUT" << endl;
		}
	}while(input != 'y' && input != 'Y' && input != 'n' && input != 'N');

	cout << endl;

	return contin;
}

//Diagonal win (Player #1)
/*Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
3

INVALID INPUT

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
1
__________
| *| *| *|
| *| *| *|
| *| *| *|
__________

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:-1

INVALID INPUT

__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:10

INVALID INPUT

__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:1

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
1
__________
| X| *| *|
| *| *| *|
| *| *| *|
__________

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:2

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
1
__________
| X| O| *|
| *| *| *|
| *| *| *|
__________

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:3

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
1
__________
| X| O| X|
| *| *| *|
| *| *| *|
__________

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:4

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
1
__________
| X| O| X|
| O| *| *|
| *| *| *|
__________

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:5

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
1
__________
| X| O| X|
| O| X| *|
| *| *| *|
__________

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:6

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
1
__________
| X| O| X|
| O| X| O|
| *| *| *|
__________

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:7

Player #1 wins!

Would you like to play again?
Do NOT include parenthesis with selection!
Please type (Y) to play again and (N) to quit:n

Press any key to continue . . .*/



//Horizontal win (Player #1)
/*Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:1

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:4

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:2

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:5

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:3

Player #1 wins!

Would you like to play again?
Do NOT include parenthesis with selection!
Please type (Y) to play again and (N) to quit:n

Press any key to continue . . .*/



//Vertical win (Player #2)
/*Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:1

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:2

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:3

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:5

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:4

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:8

Player #2 wins!

Would you like to play again?
Do NOT include parenthesis with selection!
Please type (Y) to play again and (N) to quit:n

Press any key to continue . . .*/



//Draw
/*Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:5

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:1

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:7

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:3

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:9

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:8

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:2

Player #2 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:4

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
1
__________
| O| X| O|
| O| X| *|
| X| O| X|
__________

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
2
__________
| 1| 2| 3|
| 4| 5| 6|
| 7| 8| 9|
__________
Choose a spot on the board, 1 - 9:6

Draw: There is no winner...

Would you like to play again?
Do NOT include parenthesis with selection!
Please type (Y) to play again and (N) to quit:y

Player #1 - Pick a spot on the board to place your piece
Choose from the following menu:
1. print current board
2. enter spot to play
*/