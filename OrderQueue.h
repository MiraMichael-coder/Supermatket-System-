#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

#include <queue>
#include "Order.h"
using namespace std;
class OrderQueue {
private:
    queue<Order> orders;  // Queue to manage orders

public:
    void addOrder(Order& order, linkedlist<Product>* productList);
    Order processNextOrder();
    linkedlist<Product> *mostDemanded(linkedlist<Product>* productList) const;
    bool isEmpty() const { return orders.empty(); }
};


#endif // ORDERQUEUE_H
