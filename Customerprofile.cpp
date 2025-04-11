#include "Customerprofile.h"
#include<iostream>
#include<string>
using namespace std;
//Default constructor
customerprofile::customerprofile() : customerID(""), name(""), rewardpoints(0) {}

// Parameterized constructor
customerprofile::customerprofile(string id, string n, int rp)
    : customerID(id), name(n), rewardpoints(rp) {}

//getters
string customerprofile::getID() const
{
	return customerID;
}
string customerprofile::getname() const
{
	return name;
}
void customerprofile::addrewardpoint(int points)
{
	rewardpoints += points;
}
int customerprofile::getrewarpoints() const
{
	return rewardpoints;
}
void customerprofile::getDetails()const
{
	cout << "Customer id: " << customerID << endl;
	cout << "Customer name: " << name << endl;
	cout << "Reward points: " << rewardpoints << endl;

}
