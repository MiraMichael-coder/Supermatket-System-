#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "LinkedListTemplate.h"
#include <stack>
#include <string>
#include "Product.h"
#include "CartItem.h"
#include "SystemLog.h"

using namespace std;

class ShoppingCart
{
    private:

        stack<string> actionHistory; // stores el add,remove,update strings
        stack<CartItem> removeHistory; //stores the object of removed items
        stack<int> quantityHistory; //keeps track of quantity through out
        stack<string>updateHistory; //stores string updates ,for when reversing update

    public:
        linkedlist<CartItem> cartList; //Generic linked list for cartitems
        ShoppingCart();
        ShoppingCart(const ShoppingCart& other);
        ~ShoppingCart();
        void addItem(Product &product , int quantity);
        void removeItem(const string & productname);
        void updateItemQuantity(const string & productname);
        void undoLastAction(SystemLog&log);
        double calculateTotal();
        void clearCart();
        void getDetails();
        ShoppingCart& operator=(const ShoppingCart& other);
        
        //Node* getHead() const { return head; } // is necessary because the head represents the starting point of a linked list.


};
#endif // SHOPPINGCART_H
