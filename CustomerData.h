#include "PersonData.h"
#include <string>
using namespace std;

#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

class CustomerData : public PersonData{
private:
	string cNumber;
	bool mList;
public:
	CustomerData():PersonData(){
		cNumber = "NONE";
		mList = true;
	}
	CustomerData(string ln, string fn, string a, string c, string z, string p, string num, bool m):PersonData(ln, fn, a, c, z, p){
		cNumber = num;
		mList = m;
	}
	~CustomerData(){	
	}
	void setCustNum(string c){
		cNumber = c;
	}
	void setMailList(bool m){
		mList = m;
	}
	string getCustNum(){
		return cNumber;
	}
	bool getMailList(){
		return mList;
	}
};

#endif