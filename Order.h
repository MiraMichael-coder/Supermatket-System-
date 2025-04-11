#ifndef ORDER_H
#define ORDER_H
#include "Inventory.h"
#include "Product.h"
#include "CartItem.h"
#include "ShoppingCart.h"
#include "LinkedListTemplate.h"
#include "customerprofile.h"
#include <string>
using namespace std;


class Order {
    private:
        linkedlist<CartItem*> cartList; // Generic linked list for cart items
        ShoppingCart* cart;               // Pointer to shopping cart
        double Totalcost;                 // Total cost of the order
        string status;                    // Order status
        string estimateProcessingTime;    // Estimated processing time
        string orderID;
        customerprofile* customerid;      // Associated customer profile

        string generateOrderID();

    public:
         // Static members for promo codes and discounts
        static const string promoCodes[5];
        static const double discountRates[5];
        static const int thresholds[5];
        // Constructors and Destructor
        Order();
        Order(customerprofile* cust,const ShoppingCart& c);
        ~Order();
        Order(const Order& other);
        Order& operator=(const Order& other);
        // Core functionality
        void additemtoOrder(Inventory &in,SystemLog&log);                               // Add items to the order
        double calculateTotalCost(double taxRate);  // Calculate total cost with tax and discounts

        // Promo code handling
        int userActivatePromoCode();          // User prompts for promo code activation

        // Order status management
        void updateStatus(const string& newstatus);
        void setEstimatedProcessingTime(int hoursFromNow);

        // Getters
        double getTotalCost() const;
        string getStatus() const;
        string getEstimatedProcessingTime() const;
        customerprofile* getcustomer() const;
        linkedlist<CartItem*>* getCartItemsInorder();
        string getOrderId()const ;



        // Display order details
        void displayOrderDetails() const;
       // linkedlist<CartItem*>* Order::getCartItemsInorder() {
       //return &cartList;
};

#endif // ORDER_H
