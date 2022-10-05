#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;

void main(){
	ifstream input ("text.txt");
	char temp;

	int numCount = 0;
	int upperCount = 0;
	int lowerCount = 0;
	int otherCount = 0;
	int totalCount = 0;

	while(input.get(temp)){
		if(isdigit(temp))
			numCount++;
		else if(isupper(temp))
			upperCount++;
		else if(islower(temp))
			lowerCount++;
		else
			otherCount++;
		totalCount++;
		cout << temp;
	}

	cout << endl;
	cout << "\nThere are " << upperCount << " uppercase letters, " << lowerCount << " lowercase letters, " << numCount 
		 << " numbers,\n" << otherCount << " other characters, " << "and " << totalCount << " total characters." << endl;
}

/*No one is unaware of the name of that famous English shipowner, Cunard.
In 1840 this shrewd industrialist founded a postal service between Liverpool and
 Halifax, featuring three wooden ships with 400-horsepower paddle wheels and a b
urden of 1,162 metric tons.
Eight years later, the company's assets were increased by four 650-horsepower sh
ips at 1,820 metric tons, and in two more years, by two other vessels of still g
reater power and tonnage.
In 1853 the Cunard Co., whose mail-carrying charter had just been renewed, succe
ssively added to its assets the Arabia, the Persia, the China, the Scotia, the J
ava, and the Russia, all ships of top speed and, after the Great Eastern, the bi
ggest ever to plow the seas.
So in 1867 this company owned twelve ships, eight with paddle wheels and four wi
th propellers.
If I give these highly condensed details, it is so everyone can fully understand
 the importance of this maritime transportation company, known the world over fo
r its shrewd management.
No transoceanic navigational undertaking has been conducted with more ability, n
o business dealings have been crowned with greater success.
In twenty-six years Cunard ships have made 2,000 Atlantic crossings without so m
uch as a voyage canceled, a delay recorded, a man, a craft, or even a letter los
t.
Accordingly, despite strong competition from France, passengers still choose the
 Cunard line in preference to all others, as can be seen in a recent survey of o
fficial documents.
Given this, no one will be astonished at the uproar provoked by this accident in
volving one of its finest steamers

There are 29 uppercase letters, 1228 lowercase letters, 30 numbers,
304 other characters, and 1591 total characters.
Press any key to continue . . .*/