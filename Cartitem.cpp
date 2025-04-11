#include "CartItem.h"
#include <iostream>
#include <string>
#include <sstream> 
#include <iomanip>
using namespace std;

// Constructor

// Get the total price for the CartItem
double CartItem::getTotalPrice()  {
    return product.getPrice() * quantity; // Assuming Product has a getPrice() method
}

// Get details of the CartItem
string CartItem::getDetails()  
{
    stringstream ss;
    ss << product.getDetails() << "\nQuantity: " << quantity
       << "\n Subtotal Price: $" << fixed << setprecision(2) << getTotalPrice();
    return ss.str();
}


// Update the quantity of the item
void CartItem::updateQuantity(int qty) {
        quantity = qty;
        cout << "Quantity updated to: " << quantity << endl;
    }
