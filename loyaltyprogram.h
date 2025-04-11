#ifndef LOYALTYPROGRAM_H_INCLUDED
#define LOYALTYPROGRAM_H_INCLUDED



#include<string>
#include "Customerprofile.h"
#include "LinkedListTemplate.h"

class loyaltyprogram
{
private:
    linkedlist<customerprofile> customers;      // Linked list to store customers
    int customerCount;

public:

    loyaltyprogram();//constructor
    void addnewcustomer(string id = "",string name = "",int rp=0);//add new customer to linked list
    customerprofile* getcustomerprofile(const string& customerId);//get customer's data using the ID
    void displayall() const;//display all customer's profiles
    string getexclusiveoffers(string customerId);//show customers offers
    customerprofile* getcustomer(string name);
    ~loyaltyprogram();//destructor to loyalty program class
};


#endif // LOYALTYPROGRAM_H_INCLUDED
