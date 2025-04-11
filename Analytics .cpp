#include "Analytics.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Analytics::generateSalesReport(const OrderQueue& orderQueue, linkedlist<Product>* productList) {
    // Get the sorted list of products from most to least demanded
    linkedlist<Product> sortedProductList = orderQueue.mostDemanded(productList);

    // Display the Sales Report
    cout << "Sales Report:\n";

    // Now, display the entire list in the order of demand
    linkedlist<Product>::ListNode* current = sortedProductList.getHead();
    int rank = 1; // Start ranking from 1
    while (current != nullptr) {
        cout << "Rank " << rank << ": "
            << current->info.getDetails();
            << " - Demand Count: " << current->info.getDemandCount()
            << endl;
        current = current->next;
        rank++;
    }
}
void Analytics::generateCategoryReport(const Inventory& inventory) {
    cout << "Category Popularity Report:\n";
    inventory.display(); // Assuming this displays category-wise product details
}

void Analytics::analyzeCustomerBehavior(const LoyaltyProgram& loyaltyProgram, const string& customerId) {
    customerprofile customer = loyaltyProgram.getcustomerprofile(customerId);
    if (customer.getID() != "") {
        cout << "Customer Behavior Report for: " << customer.getname() << "\n";
        cout << "Reward Points: " << customer.getrewarpoints() << "\n";
        cout << "Exclusive Offers: " << loyaltyProgram.getexclusiveoffers(customerId) << "\n";//checkkkkk
    }
    else {
        cout << "Customer not found.\n";
    }
}

void Analytics::generateInventoryAlerts(const PriorityQueue& lowStockQueue) {
    cout << "Inventory Alerts:\n";
    lowStockQueue.displayLowStockAlerts();
}

void Analytics::displaySystemLogs(const SystemLog& log) {
    cout << "System Logs:\n";
    log.displayLogs();
}
