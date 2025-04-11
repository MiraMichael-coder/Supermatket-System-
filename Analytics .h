#ifndef ANALYTICS_H
#define ANALYTICS_H


#include "OrderQueue.h"
#include "Inventory.h"
#include "Loyaltyprogram.h"
#include "SystemLog.h"

class Analytics {
public:
    void generateSalesReport( OrderQueue& orderQueue, linkedlist<Product>* productList);
    void generateCategoryReport( Inventory& inventory);
    void analyzeCustomerBehavior( loyaltyprogram& LoyaltyProgram, const string& customerId);
    void generateInventoryAlerts( PriorityQueue& lowStockQueue);
    void displaySystemLogs(const SystemLog& log);
};

#endif // ANALYTICS_H

