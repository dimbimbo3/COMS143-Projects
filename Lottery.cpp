#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int arraySize ();
void randomize (int[], const int);
bool inputNum (int[], const int);
void winnerCheck(int[], int[], const int);
void playAgain (bool &);

void main(){
	srand(time(0));
	const int MAX = 6;
	int winner[MAX];
	int user[MAX];
	bool play = true;

	while(play == true){
		int pick = arraySize();
		randomize(winner, pick);
		bool ask = inputNum(user, pick);
		if (ask == false)
			randomize(user, pick);
		winnerCheck(winner, user, pick);
		playAgain(play);
		cout << endl;
	}
}

//Choose Pick Size
int arraySize(){
	int size = 0;
	int input = 0;

	while(input != 3 && input != 4 && input != 6){
		cout << "Which lottery would you like to play?" << endl;
		cout << "Do not include parenthesis with selection!" << endl;
		cout << "Please input (3) for pick 3, (4) for pick 4, or (6) for pick 6:";
		cin >> input;
		switch(input){
		case (3):
			size = 3;
			break;
		case (4):
			size = 4;
			break;
		case (6):
			size = 6;
			break;
		default:
			cout << endl;
			cout << "INVALID INPUT" << endl;
			cout << endl;
		}
	}

	cout << endl;
	
	return size;
}

//Randomize Lottery Numbers
void randomize (int lottery[], const int pick){
	for(int i = 0; i < pick; i++){
		int random = (rand() % 9);
		lottery[i] = random;
	}
}

//Ask & Input User Numbers
bool inputNum (int user[], const int pick){
	bool ask = true;
	char input = '.';
	int value;

	while(input != 'y' && input != 'Y' && input != 'n' && input != 'N'){
		cout << "Would you like to pick your numbers?" << endl;
		cout << "Do not include parenthesis with selection!" << endl;
		cout << "Please input (Y) to pick your numbers or (N) to randomize them:";
		cin >> input;
		switch(input){
		case('y'):
		case('Y'):
			ask = true;
			break;
		case('n'):
		case('N'):
			ask = false;
			break;
		default:
			cout << endl;
			cout << "INVALID INPUT" << endl;
			cout << endl;
		}
	}

	cout << endl;

	if (ask == true){
		int i = 0;
		do{
			cout << "Lottery numbers must be between 0-9!" << endl;
			cout << "Please input lottery #" << i + 1 << ":";
			cin >> value;
			if(value >= 0 && value <= 9){
				user[i] = value;
				i++;
			}
			else{
				cout << endl;
				cout << "INVALID NUMBER!" << endl;
				cout << endl;
			}
		}while (i < pick);
		cout << endl;
	}

	return ask;
}

//Check for Winner & Display Numbers
void winnerCheck (int winner[], int user[], const int size){
	int match = 0;

	for(int i = 0; i < size; i++){
		if(user[i] == winner[i])
			match++;
	}

	cout << endl;
	cout << setw(25) << "Winning Lottery Numbers =";
	for(int i = 0; i < size; i++){
		cout << " " << winner[i];
	}

	cout << endl;
	cout << left << setw(24) << "User Numbers " << "=";
	for(int i = 0; i < size; i++){
		cout << " " << user[i];
	}

	cout << endl;
	cout << "You have " << match << " matching numbers" << endl;

	if (match == size){
		cout << "You win!!!" << endl;
		cout << endl;
	}
	else{
		cout << "Sorry, you lose..." << endl;
		cout << endl;
	}
}

//Check if user wants to play again
void playAgain (bool &play){
	char input = '.';
	while(input != 'y' && input != 'Y' && input != 'n' && input != 'N'){
			cout << "Play again? Type (Y) to play or (N) to stop:";
			cin >> input;
			switch(input){
			case('y'):
			case('Y'):
				play = true;
				break;
			case('n'):
			case('N'):
				play = false;
				break;
			default:
				cout << endl;
				cout << "INVALID INPUT" << endl;
				cout << endl;
			}
	}
}

/*Which lottery would you like to play?
Do not include parenthesis with selection!
Please input (3) for pick 3, (4) for pick 4, or (6) for pick 6:1

INVALID INPUT

Which lottery would you like to play?
Do not include parenthesis with selection!
Please input (3) for pick 3, (4) for pick 4, or (6) for pick 6:3

Would you like to pick your numbers?
Do not include parenthesis with selection!
Please input (Y) to pick your numbers or (N) to randomize them:z

INVALID INPUT

Would you like to pick your numbers?
Do not include parenthesis with selection!
Please input (Y) to pick your numbers or (N) to randomize them:y

Lottery numbers must be between 0-9!
Please input lottery #1:-1

INVALID NUMBER!

Lottery numbers must be between 0-9!
Please input lottery #1:10

INVALID NUMBER!

Lottery numbers must be between 0-9!
Please input lottery #1:0
Lottery numbers must be between 0-9!
Please input lottery #2:1
Lottery numbers must be between 0-9!
Please input lottery #3:9


Winning Lottery Numbers = 3 0 5
User Numbers            = 0 1 9
You have 0 matching numbers
Sorry, you lose...

Play again? Type (Y) to play or (N) to stop:y

Which lottery would you like to play?
Do not include parenthesis with selection!
Please input (3) for pick 3, (4) for pick 4, or (6) for pick 6:4

Would you like to pick your numbers?
Do not include parenthesis with selection!
Please input (Y) to pick your numbers or (N) to randomize them:n


Winning Lottery Numbers = 1 1 0 5
User Numbers            = 2 6 6 5
You have 1 matching numbers
Sorry, you lose...

Play again? Type (Y) to play or (N) to stop:Y

Which lottery would you like to play?
Do not include parenthesis with selection!
Please input (3) for pick 3, (4) for pick 4, or (6) for pick 6:6

Would you like to pick your numbers?
Do not include parenthesis with selection!
Please input (Y) to pick your numbers or (N) to randomize them:N


Winning Lottery Numbers = 1 1 2 0 4 7
User Numbers            = 5 7 0 5 0 0
You have 0 matching numbers
Sorry, you lose...

Play again? Type (Y) to play or (N) to stop:n

Press any key to continue . . .*/