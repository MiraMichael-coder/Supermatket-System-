#include "OrderQueue.h"
#include <iostream>

using namespace std;

void OrderQueue::addOrder(Order& order, linkedlist<Product>* productList) {
   
    cout << "Adding Order ID: " << order.getOrderId() << " to the queue.\n";  // Debug
    orders.push(order);  // Add the order to the queue

    // Update demand for each product in the order
    linkedlist<CartItem*>::ListNode* current = order.getCartItemsInorder()->head;
    while (current != nullptr) {
        const string& productName = current->info->getproduct().getname();
        int quantity = current->info->getquantity();

        // Traverse the product linked list to find the matching product
        linkedlist<Product>::ListNode* productNode = productList->head;
        while (productNode != nullptr) {
            if (productNode->info.getname() == productName) {
                for (int j = 0; j < quantity; j++) {
                    productNode->info.incrementDemandCount();  // Increment demand count
                }
                break;  // Product found and updated
            }
            productNode = productNode->next;  // Move to the next product
        }
        current = current->next;  // Move to the next cart item
    }
}

Order OrderQueue::processNextOrder() {
    if (orders.empty()) 
        {
        cout << "No orders to process.\n";
        return Order();  // Return a default order
    }

    Order nextOrder = orders.front(); 
     // Get a copy of the first order
    cout << "Processing Order ID: " << nextOrder.getOrderId() << "\n";  // Debug

    orders.pop();  // Remove the original order from the queue

    return nextOrder;  // Return the copy
}

linkedlist<Product>* OrderQueue::mostDemanded(linkedlist<Product>* productList) const {
    // Check if the product list is valid
    if (productList == nullptr) {
        cout << "Error: Product list is null.\n";
        return nullptr;
    }

    // Check if the list is empty
    if (productList->getHead() == nullptr) {
        cout << "Warning: Product list is empty. Nothing to sort.\n";
        return productList;
    }

    // Sort the product list by demand using merge sort
    productList->head = productList->mergeSort(productList->getHead());

    // Return the sorted product list
    return productList;
}

