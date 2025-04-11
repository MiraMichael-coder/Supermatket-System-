#include "Order.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <string>
#include <cmath>
#include "ShoppingCart.h"

using namespace std;

// Initialize static members
const string Order::promoCodes[5] = { "PROMO10", "PROMO20", "PROMO30", "PROMO40", "PROMO50" };
const double Order::discountRates[5] = { 0.10, 0.20, 0.30, 0.40, 0.50 }; // Corresponding discount rates
const int Order::thresholds[5] = { 50, 100, 150, 200, 300 }; // Thresholds for applying promo codes "points"

Order::Order()
    : cart(nullptr), Totalcost(0.0), status("Pending"), estimateProcessingTime("N/A"), customerid(nullptr) {
    orderID = generateOrderID();
}

Order::Order(customerprofile* cust, const ShoppingCart& c)
    : cart(new ShoppingCart(c)), Totalcost(0.0), status("Pending"), estimateProcessingTime("N/A"), customerid(cust) {
    orderID = generateOrderID();
}
Order::Order(const Order& other)
    : cart(new ShoppingCart(*other.cart)), Totalcost(other.Totalcost),
      status(other.status), estimateProcessingTime(other.estimateProcessingTime),
      orderID(other.orderID), customerid(other.customerid)
{
    linkedlist<CartItem*>::ListNode* current = other.cartList.head;
    while (current != nullptr) {
        cartList.addtoTail(new CartItem(*current->info));
        current = current->next;
    }
}
Order& Order::operator=(const Order& other) {
    if (this != &other) {
        // Clean up existing resources
        linkedlist<CartItem*>::ListNode* current = cartList.head;
        while (current != nullptr) {
            delete current->info;
            current = current->next;
        }
        delete cart;

        // Deep copy new resources
        cart = new ShoppingCart(*other.cart);
        Totalcost = other.Totalcost;
        status = other.status;
        estimateProcessingTime = other.estimateProcessingTime;
        orderID = other.orderID;
        customerid = other.customerid;

        current = other.cartList.head;
        while (current != nullptr) {
            cartList.addtoTail(new CartItem(*current->info));
            current = current->next;
        }
    }
    return *this;
}

Order::~Order() {
    // Free dynamically allocated memory
    linkedlist<CartItem*>::ListNode* current = cartList.head;
    while (current != nullptr) {
        delete current->info; // Delete each CartItem
        current = current->next;
    }
    delete cart;
}

string Order:: generateOrderID()
{ if(customerid)
   { orderID = customerid->getID();}
   else orderID="A000";
    return orderID;
}



void Order::additemtoOrder(Inventory &in,SystemLog&log)
{
    // Access items from the shopping cart
    linkedlist<CartItem>::ListNode* cartCurrent = cart->cartList.head;

    while (cartCurrent != nullptr)
    {
        CartItem* cartItem = &cartCurrent->info;

        if (cartItem->getquantity() > cartItem->getproduct().getstock()) {
            cout << "Insufficient stock for product: " << cartItem->getproduct().getname() << endl;
        } else {
            // Create a new CartItem for the order based on the cart item
            CartItem* newItem = new CartItem(cartItem->getproduct(), cartItem->getquantity());
            cartList.addtoTail(newItem);
            in.updatestock(cartItem->getproduct().getname(), cartItem->getproduct().getstock() - cartItem->getquantity(), log);
        }

        cartCurrent = cartCurrent->next;
    }


    cout << "All items from the shopping cart have been added to the order." << endl;
}

double Order::calculateTotalCost(double taxRate)
{
    double subtotal = 0.0;
     linkedlist<CartItem*>::ListNode* current = cartList.head;

    while (current != nullptr) {
        subtotal += current->info->getTotalPrice();
        current = current->next;
    }
    double promoDiscount = 0;
    int promoIndex = userActivatePromoCode(); // Prompt the user for a promo code

    if (promoIndex != -1)
    {
        promoDiscount = subtotal * discountRates[promoIndex];
    }
    double tax = subtotal * taxRate;

    Totalcost = subtotal + tax - promoDiscount ;


    int earnedPoints = floor(Totalcost);
    customerid->addrewardpoint(earnedPoints);


    cout << "Subtotal: $" << subtotal << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Promo Discount: $" << promoDiscount << endl;
    cout << "Total Cost: $" << Totalcost << endl;
    cout << "Reward Points Earned: " << earnedPoints << endl;

    return Totalcost;
}

int Order::userActivatePromoCode()
{
    cout << "Available Promo Codes:" << endl;
    // Check the subtotal and compare it with the thresholds
     for (int i = 0; i < 5; i++) {
        if (customerid!=nullptr && customerid->getrewarpoints() >= thresholds[i] &&
            (i == 4 || customerid->getrewarpoints() < thresholds[i + 1])||customerid->getrewarpoints()!=0) {
            cout << "Promo Code: " << promoCodes[i] << " (Discount: " << discountRates[i] * 100 << "%)" << endl;
            cout << "Enter this promo code to activate it (or press Enter to skip): ";

            string userCode;
            cin >> userCode;

            if (userCode == promoCodes[i]) {
                cout << "Promo Code Applied: " << promoCodes[i] << endl;
                return i;
            }
        }
    }

    cout << "No valid promo code applied.\n";
    return -1;
}


linkedlist<CartItem*>* Order :: getCartItemsInorder()
{
    return &cartList;
}

string  Order:: getOrderId()const { return orderID ;}

void Order::updateStatus(const string& newstatus)
{
    status = newstatus;
}

void Order::setEstimatedProcessingTime(int hoursFromNow)
{
    // Get the current time using the system clock
    auto now = std::chrono::system_clock::now();
    // Calculate the future time by adding the specified hours
    auto futureTime = now + chrono::hours(hoursFromNow);

    // Convert the future time to a time_t format for formatting purposes
    time_t futureTimeT = chrono::system_clock::to_time_t(futureTime);

    // Buffer to store the formatted date and time string
    char buffer[100];

    // Format the time into a readable string in the format "dd/mm/yyyy HH:MM:SS"
    if (strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", localtime(&futureTimeT)))
    {
        estimateProcessingTime = string(buffer); // Assign formatted time to the attribute
    }
    else
    {
        estimateProcessingTime = "Invalid Time"; // Handle formatting failure
    }
}

// Getter functions
double Order::getTotalCost() const { return Totalcost; }
string Order::getStatus() const { return status; }
string Order::getEstimatedProcessingTime() const { return estimateProcessingTime; }
customerprofile* Order::getcustomer() const { return customerid; }

void Order::displayOrderDetails() const
{
    cart->getDetails();
    cout << "Order-ID: "<< orderID <<endl;
    cout << "Order Status: " << status << endl;
    cout << "Estimated Processing Time: " << estimateProcessingTime << endl;
    cout << "Total Cost: $" << fixed << setprecision(2) << Totalcost << endl;

}
