#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void input (vector<char> &);
int convert (vector<char> &);
int calculate (int, int);
vector<char> convertBack (int);
void romanDisplay(vector<char> &);

void main(){
	vector<char> roman1;
	cout << "Roman Numeral Set 1" << endl;
	input(roman1);
	int number1 = convert(roman1);
	cout << endl;

	vector<char> roman2;
	cout << "Roman Numeral Set 2" << endl;
	input(roman2);
	int number2 = convert(roman2);
	cout << endl;

	int total = calculate(number1, number2);
	vector<char> romanTotal = convertBack(total);
	romanDisplay(romanTotal);
	cout << endl;
}

//Inputting Roman Numeral Sets
void input(vector<char> &nums){
	char input;
	char proceed = 'Y';
	int i = 0;
	while(proceed == 'Y' || proceed == 'y'){
		cout << "Please input Roman Numerals(I,V,X,L,C,D,M) #" << setw(2) << i + 1 << ";";
		cin >> input;
		switch(input){
		case 'i':
		case 'I':
			nums.push_back(input);
			i++;
			break;
		case 'v':
		case 'V':
			nums.push_back(input);
			i++;
			break;
		case 'x':
		case 'X':
			nums.push_back(input);
			i++;
			break;
		case 'l':
		case 'L':
			nums.push_back(input);
			i++;
			break;
		case 'c':
		case 'C':
			nums.push_back(input);
			i++;
			break;
		case 'd':
		case 'D':
			nums.push_back(input);
			i++;
			break;
		case 'm':
		case 'M':
			nums.push_back(input);
			i++;
			break;
		default:
			cout << "INVALID INPUT!" << endl;
			break;
		}
		cout << "Continue adding Roman Numerals? (Y/N)";
		cin >> proceed;
	}
} 

//Coverting Roman Numeral Sets to ints
int convert(vector<char> &roman){
	int total = 0;
	for(int i = 0; i < roman.size(); i++){
		if(roman.at(i) == 'I' || roman.at(i) == 'i')
			total += 1;
		else if(roman.at(i) == 'V' || roman.at(i) == 'v')
			total += 5;
		else if(roman.at(i) == 'X' || roman.at(i) == 'x')
			total += 10;
		else if(roman.at(i) == 'L' || roman.at(i) == 'l')
			total += 50;
		else if(roman.at(i) == 'C' || roman.at(i) == 'c')
			total += 100;
		else if(roman.at(i) == 'D' || roman.at(i) == 'd')
			total += 500;
		else if(roman.at(i) == 'M' || roman.at(i) == 'm')
			total += 1000;
	}

	return total;
}

//Calculating chosen method for both Roman Numeral Sets
int calculate(int num1, int num2){
	char input;
	int calculation;
	cout << "Please choose method of calculation (+,-,*,/):";
	cin >> input;
	switch(input){
	case '+':
		calculation = num1 + num2;
		break;
	case '-':
		calculation = num1 - num2;
		break;
	case '*':
		calculation = num1 * num2;
		break;
	case '/':
		calculation = num1 / num2;
		break;
	}

	return calculation;
}

//Convert Total to Roman Numeral
vector<char> convertBack(int total){
	vector<char> romanTotal;
	do {
		if (total >= 1000) {
			romanTotal.push_back('M');
			total -= 1000;
		}
		else if (total >= 500) {
			romanTotal.push_back('D');
			total -= 500;
		}
		else if (total >= 100) {
			romanTotal.push_back('C');
			total -= 100;
		}
		else if (total >= 50){
			romanTotal.push_back('L');
			total -= 50;
		}
		else if (total >= 10) {
			romanTotal.push_back('X');
			total -= 10;
		}
		else if (total >= 5) {
			romanTotal.push_back('V');
			total -= 5;
		}
		else if (total >= 1) {
			romanTotal.push_back('I');
			total -= 1;
		}
	} while (total != 0);

	return romanTotal;
}

//Display Roman Numeral Total
void romanDisplay(vector<char> &romanTotal){
	for (int i = 0; i < romanTotal.size(); i++)
		cout << romanTotal.at(i);
}

//Addition
/*Roman Numeral Set 1
Please input Roman Numerals(I,V,X,L,C,D,M) # 1;Z
INVALID INPUT!
Continue adding Roman Numerals? (Y/N)y
Please input Roman Numerals(I,V,X,L,C,D,M) # 1;I
Continue adding Roman Numerals? (Y/N)Y
Please input Roman Numerals(I,V,X,L,C,D,M) # 2;i
Continue adding Roman Numerals? (Y/N)Y
Please input Roman Numerals(I,V,X,L,C,D,M) # 3;V
Continue adding Roman Numerals? (Y/N)Y
Please input Roman Numerals(I,V,X,L,C,D,M) # 4;v
Continue adding Roman Numerals? (Y/N)Y
Please input Roman Numerals(I,V,X,L,C,D,M) # 5;X
Continue adding Roman Numerals? (Y/N)y
Please input Roman Numerals(I,V,X,L,C,D,M) # 6;x
Continue adding Roman Numerals? (Y/N)Y
Please input Roman Numerals(I,V,X,L,C,D,M) # 7;L
Continue adding Roman Numerals? (Y/N)y
Please input Roman Numerals(I,V,X,L,C,D,M) # 8;l
Continue adding Roman Numerals? (Y/N)y
Please input Roman Numerals(I,V,X,L,C,D,M) # 9;C
Continue adding Roman Numerals? (Y/N)y
Please input Roman Numerals(I,V,X,L,C,D,M) #10;c
Continue adding Roman Numerals? (Y/N)Y
Please input Roman Numerals(I,V,X,L,C,D,M) #11;D
Continue adding Roman Numerals? (Y/N)y
Please input Roman Numerals(I,V,X,L,C,D,M) #12;d
Continue adding Roman Numerals? (Y/N)Y
Please input Roman Numerals(I,V,X,L,C,D,M) #13;M
Continue adding Roman Numerals? (Y/N)y
Please input Roman Numerals(I,V,X,L,C,D,M) #14;m
Continue adding Roman Numerals? (Y/N)n

Roman Numeral Set 2
Please input Roman Numerals(I,V,X,L,C,D,M) # 1;I
Continue adding Roman Numerals? (Y/N)n

Please choose method of calculation (+,-,*,/):+
MMMCCCXXXIII
Press any key to continue . . .*/

//Subtraction
/*Roman Numeral Set 1
Please input Roman Numerals(I,V,X,L,C,D,M) # 1;X
Continue adding Roman Numerals? (Y/N)Y
Please input Roman Numerals(I,V,X,L,C,D,M) # 2;V
Continue adding Roman Numerals? (Y/N)N

Roman Numeral Set 2
Please input Roman Numerals(I,V,X,L,C,D,M) # 1;I
Continue adding Roman Numerals? (Y/N)y
Please input Roman Numerals(I,V,X,L,C,D,M) # 2;i
Continue adding Roman Numerals? (Y/N)n

Please choose method of calculation (+,-,*,/):-
XIII
Press any key to continue . . .*/

//Multiplication
/*Roman Numeral Set 1
Please input Roman Numerals(I,V,X,L,C,D,M) # 1;X
Continue adding Roman Numerals? (Y/N)N

Roman Numeral Set 2
Please input Roman Numerals(I,V,X,L,C,D,M) # 1;V
Continue adding Roman Numerals? (Y/N)n

Please choose method of calculation (+,-,*,/):*
L
Press any key to continue . . .*/

//Division
/*Roman Numeral Set 1
Please input Roman Numerals(I,V,X,L,C,D,M) # 1;M
Continue adding Roman Numerals? (Y/N)N

Roman Numeral Set 2
Please input Roman Numerals(I,V,X,L,C,D,M) # 1;D
Continue adding Roman Numerals? (Y/N)n

Please choose method of calculation (+,-,*,/):/
II
Press any key to continue . . .*/