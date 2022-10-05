#include <iostream>
#include <string>
#include <iomanip>
#include "PreferredCustomer.h"
using namespace std;

void main(){
	string lastName = "";
	string firstName = "";
	string address = "";
	string city = "";
	string zip = "";
	string phone = "";
	string cNum = "";
	char input = '.';
	bool mail = true;
	double amount = 0.0;

	PreferredCustomer cust1;
	
	cout << "Please input your first name:";
	cin >> firstName;
	cust1.setFirst(firstName);

	cout << "Please input your last name:";
	cin >> lastName;
	cust1.setLast(lastName);

	cin.ignore();

	cout << "Please input your address:";
	getline(cin, address);
	cust1.setAddress(address);

	cout << "Please input your city:";
	cin >> city;
	cust1.setCity(city);

	cout << "Please input your zip code:";
	cin >> zip;
	cust1.setZip(zip);

	cout << "Please input your phone number:";
	cin >> phone;
	cust1.setPhone(phone);

	cout << "Please input your customer number:";
	cin >> cNum;
	cust1.setCustNum(cNum);

	while (toupper(input) != 'Y' && toupper(input) != 'N') {
		cout << "Would you like to be on the mailing list?" << endl;
		cout << "Type 'Y' for Yes or 'N' for No:";
		cin >> input;

		if (toupper(input) == 'Y')
			mail = true;
		else if (toupper(input) == 'N')
			mail = false;
		else
			cout << "INVALID INPUT!" << endl;
	}
	cust1.setMailList(mail);

	cout << "Please input your purchase amount:";
	cin >> amount;
	cust1.setPurchases(amount);

	cout << setprecision(2) << fixed;

	cout << "\nName: " << cust1.getFirst() << " " << cust1.getLast() << endl;
	cout << "Address: " << cust1.getAddress() << endl;
	cout << "City: " << cust1.getCity() << endl;
	cout << "Zip: " << cust1.getZip() << endl;
	cout << "Phone: " << cust1.getPhone() << endl;
	cout << "Customer Number: " << cust1.getCustNum() << endl;
	cout << "Mailing List: ";
	if (cust1.getMailList())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << "Purchase Amount: $" << cust1.getPurchases() << endl;
	cout << "Discount: " << cust1.getDiscount() << "%" << endl;


/*Please input your first name:bob
Please input your last name:mcgee
Please input your address:123 test
Please input your city:sussex
Please input your zip code:00000
Please input your phone number:9731112222
Please input your customer number:00000
Would you like to be on the mailing list?
Type 'Y' for Yes or 'N' for No:z
INVALID INPUT!
Would you like to be on the mailing list?
Type 'Y' for Yes or 'N' for No:y
Please input your purchase amount:500

Name: bob mcgee
Address: 123 test
City: sussex
Zip: 00000
Phone: 9731112222
Customer Number: 00000
Mailing List: Yes
Purchase Amount: $500.00
Discount: 5.00%
Press any key to continue . . .*/


/*Please input your first name:dan
Please input your last name:imbimbo
Please input your address:123 test
Please input your city:test
Please input your zip code:123
Please input your phone number:123
Please input your customer number:123
Would you like to be on the mailing list?
Type 'Y' for Yes or 'N' for No:n
Please input your purchase amount:1000

Name: dan imbimbo
Address: 123 test
City: test
Zip: 123
Phone: 123
Customer Number: 123
Mailing List: No
Purchase Amount: $1000.00
Discount: 6.00%
Press any key to continue . . .*/


/*Please input your first name:dan
Please input your last name:imbimbo
Please input your address:test 123
Please input your city:123
Please input your zip code:123
Please input your phone number:123
Please input your customer number:123
Would you like to be on the mailing list?
Type 'Y' for Yes or 'N' for No:Y
Please input your purchase amount:1500

Name: dan imbimbo
Address: test 123
City: 123
Zip: 123
Phone: 123
Customer Number: 123
Mailing List: Yes
Purchase Amount: $1500.00
Discount: 7.00%
Press any key to continue . . .*/


/*Please input your first name:dan
Please input your last name:imbimbo
Please input your address:test 123
Please input your city:test
Please input your zip code:123
Please input your phone number:123
Please input your customer number:123
Would you like to be on the mailing list?
Type 'Y' for Yes or 'N' for No:N
Please input your purchase amount:2000

Name: dan imbimbo
Address: test 123
City: test
Zip: 123
Phone: 123
Customer Number: 123
Mailing List: No
Purchase Amount: $2000.00
Discount: 10.00%
Press any key to continue . . .*/
}