#include "ProrityQueue.h"
#include<iostream>
using namespace std;
// Adds a product to the priority queue (in sorted order based on stock)
void PriorityQueue::add(Product product) {
    auto it = lowStockProducts.begin();

    // Products with stock ≤ 10 should be at the front
    while (it != lowStockProducts.end() && 
           ((it->getstock() <= 10 && product.getstock() > 10) || 
            (it->getstock() <= product.getstock()))) {
        ++it;
    }

    // Insert the product at the correct position
    lowStockProducts.insert(it, product);
}


// Removes and returns the product with the lowest stock (at the front of the list)
Product PriorityQueue::removeLowestStock() {
    if (isEmpty()) {
        cout << "No products in the priority queue.\n";
        return Product("", "", 0.0, 0);  // Return a default product if the queue is empty
    }

    // The lowest stock product is at the front of the list
    Product lowestStockProduct = lowStockProducts.front();
    lowStockProducts.pop_front();  // Remove the product from the front

    return lowestStockProduct;
}

// Displays all products in the priority queue
void PriorityQueue::displayLowStockAlerts() {
    if (isEmpty()) {
        cout << "No products are low in stock.\n";
        return;
    }

    cout << "Low Stock Alerts:\n";
    for (const auto& product : lowStockProducts) {
        cout << product.getDetails() << endl;
    }
}

// Check if the queue is empty
bool PriorityQueue::isEmpty() const {
    return lowStockProducts.empty();
}

// Removes a product by reference
void PriorityQueue::removeByProduct(Product& product) {
    for (auto it = lowStockProducts.begin(); it != lowStockProducts.end(); ++it) {
        if (it->getname() == product.getname()) {  // Compare by product name (or other identifier)
            lowStockProducts.erase(it);
            return;
        }
    }
}
