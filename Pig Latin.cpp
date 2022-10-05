#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool vowelCheck(string);
string swap(string);

void main(){
	string s = "";
	bool valid = false;

	do{
		cout << "Please enter a sentence:";
		getline(cin, s);
		int last = s.length() - 1;

		if(ispunct(s[last])){
			valid = true;
		}
		else{
			cout << "Your sentence must end with a punctuation!\n" << endl;
		}
	}while(!valid);

	string sub = "";
	string final = "";
	int subStart = 0;
	int charCount = 0;
	bool vowel = false;

	for(int i = 0; i < s.length();i++){
		charCount++;
		if(isspace(s[i]) || ispunct(s[i])){
			sub = s.substr(subStart, charCount - 1);
			subStart = i + 1;
			vowel = vowelCheck(sub);
			if(vowel)
				sub = swap(sub);
			final.append(sub);
			final += s[i];
			charCount = 0;
		}
	}

	cout << final << endl;
}

//Checks each word for vowels
bool vowelCheck (string s){
	bool vowel = false;

	for(int i = 0; i < s.length() && vowel == false; i++){
		if(toupper(s[i]) == 'A'||toupper(s[i]) == 'E'||toupper(s[i]) == 'I'
		||toupper(s[i]) == 'O'||toupper(s[i]) == 'U'||toupper(s[i]) == 'Y'){
			vowel = true;
		}
	}

	return vowel;
}

//Checks if first character is a vowel, adds "ay" if true, else moves first character to the end of string until true
string swap (string s){
	char tempChar = '.';
	string tempString = "";
	bool pig = false;

	while(!pig){
		if(toupper(s[0]) == 'A'||toupper(s[0]) == 'E'||toupper(s[0]) == 'I'
			||toupper(s[0]) == 'O'||toupper(s[0]) == 'U'||toupper(s[0]) == 'Y'){
				s.append("ay");
				pig = true;
		}
		else{
			tempChar = s[0];
			tempString = s.substr(1,s.length() - 1);
			s = tempString;
			s += tempChar;
		}
	}

	return s;
}

/*Please enter a sentence:No punct
Your sentence must end with a punctuation!

Please enter a sentence:Testing 123, this is a sentence... I suppose.
estingTay 123, isthay isay aay entencesay... Iay upposesay.
Press any key to continue . . .*/