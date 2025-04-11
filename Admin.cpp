#include "Admin.h"
#include <iostream>
#include <limits>

using namespace std;

void Admin::viewInventoryAlerts(Analytics& analytics, PriorityQueue& lowStockQueue) {
    analytics.generateInventoryAlerts(lowStockQueue);
    
}
Admin::~Admin(){}
// Analytics and Reporting
void Admin::viewSalesReports(Analytics& analytics, OrderQueue& orderQueue, linkedlist<Product>* productList) {
    analytics.generateSalesReport(orderQueue, productList);
}

void Admin::viewCustomerBehavior(Analytics& analytics, loyaltyprogram& loyaltyProgram, const string& customerId) {
    analytics.analyzeCustomerBehavior(loyaltyProgram, customerId);
}
void Admin::processOrders(OrderQueue& orderQueue, linkedlist<Product>* productList) {
    if (orderQueue.isEmpty()) {
        cout << "No orders in the queue to process.\n";
        return;
    }

    cout << "Enter Order ID to update status: ";
    string orderId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    getline(cin, orderId);

    bool orderFound = false;
    queue<Order> tempQueue;

    while (!orderQueue.isEmpty()) {
        Order currentOrder = orderQueue.processNextOrder();

        if (currentOrder.getOrderId() == orderId) {
            orderFound = true;
            cout << "Order found: " << currentOrder.getOrderId() << "\n";
            cout << "Current Status: " << currentOrder.getStatus() << "\n";

            cout << "Enter new status for the order: ";
            string newStatus;
            getline(cin, newStatus);

            currentOrder.updateStatus(newStatus);
            cout << "Order status updated successfully.\n";
        }

        tempQueue.push(currentOrder); // Preserve order in the temporary queue
    }

    // Re-add all orders back to the queue
    while (!tempQueue.empty()) {
        Order tempOrder = tempQueue.front();
        orderQueue.addOrder(tempOrder, productList);
        tempQueue.pop();
    }

    if (!orderFound) {
        cout << "Order with ID " << orderId << " not found in the queue.\n";
    }
}


Admin::Admin(string n,string p)
{
    name=n;
    password=p;
}
bool Admin::validatepass(string pass)
{
    return password==pass;
}

 void Admin::addProduct(Inventory& inventory,  Product product,SystemLog&log)
 {
     inventory.addProduct(product,log);
 }
void Admin:: updateProduct(Inventory& inventory,string productName, Product updatedProduct,SystemLog&log)
{
    inventory.updateProduct(productName,updatedProduct,log);
}
void Admin::updatePrice(Inventory& inventory, string productName, double p,SystemLog&log)
{
    inventory.updateprice(productName,p,log);
    
}
void Admin::updatestock(Inventory& inventory, string  productName,int stock,SystemLog&log)
{
     inventory.updatestock(productName,stock,log);
    
}
void Admin::deleteProduct(Inventory& inventory, string productName,SystemLog&log)
{
    inventory.removeProduct(productName,log);
}
void Admin::addcategory(Inventory& inventory,Category category,SystemLog&log)
{
    inventory.addCategory(category,log);
}
void Admin::viewlowstock(Inventory& inventory,int threshold,SystemLog&log)
{
    inventory.alertLowStock(threshold,log);
}
void Admin::applydiscount(Inventory& inventory,string name,SystemLog&log)
{
    inventory.applydiscount(name,log); //seasonal discount 
}
