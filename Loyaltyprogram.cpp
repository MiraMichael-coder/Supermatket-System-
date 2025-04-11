#include <iostream>
#include "Loyaltyprogram.h"
#include <iterator>
#include <string>

using namespace std;


// Constructor for the loyalty program
loyaltyprogram::loyaltyprogram()
{
    customerCount = 0;


}

// Add a new customer to the linked list
void loyaltyprogram::addnewcustomer(string id ,string name,int rp)
{
    customerCount++;
    int points = rp;

    // If no ID is provided, generate one
    if (id=="") {
        id = "CUST" + to_string(customerCount);
    }

    customerprofile newcustomer(id, name, points);  // Create a new customer profile
    customers.addtoTail(newcustomer);  // Add the new customer to the linked list
}

// Get customer's profile using the ID
customerprofile* loyaltyprogram::getcustomerprofile(const string& id) {
    // Assuming 'customers' is your linked list and each node contains a 'customerprofile' object
    auto* current = customers.head; // Start with the head of the list

    while (current != nullptr) {
        if (current->info.getID() == id) { // Replace 'info' with the data member holding the customerprofile
            cout << "Customer found: " << current->info.getname() << endl; // Debug: print customer name
            return &(current->info);
        }
        current = current->next; // Move to the next node
    }

    cout << "Customer not found for ID: " << id << endl; // Debug: indicate customer not foun
}
customerprofile* loyaltyprogram::getcustomer( string name) {
    
return customers.search(name);
}
// Display all customer's profiles
void loyaltyprogram::displayall() const
{
        linkedlist<customerprofile>::ListNode* current = customers.head;  // Get the head of the linked list

        if (current == nullptr)
        {
            return;
        }

        // Loop through all customers and display their profile
        while (current != nullptr)
        {
            current->info.getDetails();  // Display customer profile (displayprofile is a method of customerprofile)
            current = current->next;
        }
}
// Get exclusive offers based on customer's points

loyaltyprogram::~loyaltyprogram()
{
    // The linked list destructor will take care of cleaning up all customer nodes.

}
