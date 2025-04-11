#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <string>
#include <list>
#include "Product.h"

class PriorityQueue {
private:
    list<Product> lowStockProducts;  // Using std::list to manage low-stock products

public:
    // Adds a product to the priority queue (in sorted order based on stock)
    void add(Product product);

    // Removes and returns the product with the lowest stock
    Product removeLowestStock();

    // Displays all products in the priority queue
    void displayLowStockAlerts();
 void removeByProduct(Product& product);
    // Check if the queue is empty
    bool isEmpty() const;
};

#endif // PRIORITYQUEUE_H
