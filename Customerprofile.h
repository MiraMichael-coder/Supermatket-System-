#ifndef CUSTOMERPROFILE_H_INCLUDED
#define CUSTOMERPROFILE_H_INCLUDED
#include<iostream>
using namespace std;
class customerprofile
{
private:
	string customerID;
	string name;
	int rewardpoints;
public:
	customerprofile();
	customerprofile(string id, string n, int rp);
	string getID()const;
	string getname()const;
	int getrewarpoints()const;
	void addrewardpoint(int points);
	void getDetails()const;

   customerprofile& operator=(const customerprofile& other) {
        if (this != &other) {
            customerID = other.customerID;
            name = other.name;
            rewardpoints = other.rewardpoints;
        }
        return *this;
    }
};


#endif // CUSTOMERPROFILE_H_INCLUDED
