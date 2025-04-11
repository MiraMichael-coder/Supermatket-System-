#ifndef CARTITEM_H
#define CARTITEM_H

#include "Product.h"

class CartItem {
private:
    Product product; // Associated Product object
    int quantity;    // Quantity of the product in the cart

public:
   CartItem( const Product& prod, int qty)
    : product(prod), quantity(qty) {}
    CartItem()
    {
        
    }
    // Get the total price for the CartItem
    double getTotalPrice();

    // Get details of the CartItem
    string getDetails() ;

    // Update the quantity of the item
    void updateQuantity(int qty);
    
Product getproduct(){return product;}
int getquantity(){return quantity;}
string getname(){return product.getname();}
};

#endif
