#include <string>
using namespace std;

#ifndef PERSONDATA_H
#define PERSONDATA_H

class PersonData{
private:
	string lastName;
	string firstName;
	string address;
	string city;
	string zip;
	string phone;
public:
	PersonData(){
		lastName = "NONE";
		firstName = "NONE";
		address = "NONE";
		city = "NONE";
		zip = "NONE";
		phone = "NONE";
	}
	PersonData(string ln, string fn, string a, string c, string z, string p){
		lastName = ln;
		firstName = fn;
		address = a;
		city = c;
		zip = z;
		phone = p;		
	}
	~PersonData(){
	}
	void setLast(string ln){
		lastName = ln;
	}
	void setFirst(string fn){
		firstName = fn;
	}
	void setAddress(string a){
		address = a;
	}
	void setCity(string c){
		city = c;
	}
	void setZip(string z){
		zip = z;
	}
	void setPhone(string p){
		phone = p;
	}
	string getLast() const{
		return lastName;
	}
	string getFirst() const{
		return firstName;
	}
	string getAddress() const{
		return address;
	}
	string getCity() const{
		return city;
	}
	string getZip() const{
		return zip;
	}
	string getPhone() const{
		return phone;
	}
};

#endif