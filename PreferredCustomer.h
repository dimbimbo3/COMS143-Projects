#include "CustomerData.h"
#include <string>
using namespace std;

#ifndef PREFERREDCUSTOMER_H
#define PREFERREDCUSTOMER_H

class PreferredCustomer : public CustomerData {
private:
	double cPurchases;
	double cDiscount;
public:
	PreferredCustomer():CustomerData(){
		cPurchases = 0.0;
		cDiscount = 0;
	}
	PreferredCustomer (string ln, string fn, string a, string c, string z, string p, string num, bool m, double purchases):CustomerData(ln,fn,a,c,z,p,num,m){
		cPurchases = purchases;
		cDiscount = 0;
	}
	~PreferredCustomer(){
	}
	void setPurchases(double p) {
		cPurchases = p;
	}
	double getPurchases() {
		return cPurchases;
	}
	double getDiscount() {
		if (cPurchases >= 500 && cPurchases < 1000)
			cDiscount = 5;
		if (cPurchases >= 1000 && cPurchases < 1500)
			cDiscount = 6;
		if (cPurchases >= 1500 && cPurchases < 2000)
			cDiscount = 7;
		if (cPurchases >= 2000)
			cDiscount = 10;
		return cDiscount;
	}
};

#endif
