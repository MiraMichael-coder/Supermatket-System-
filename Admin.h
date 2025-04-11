#ifndef ADMIN_H
#define ADMIN_H

#include "Inventory.h"
#include "loyaltyprogram.h"
#include "SystemLog.h"
#include "Product.h"
#include "Category.h"
#include "ShoppingCart.h"
#include "Order.h"
#include "Analytics .h"
#include "OrderQueue.h"

using namespace std;
class Admin
{
private:
    
   string name,password;
public:
    Admin();
    ~Admin();
    Admin(string n,string p);
    void addProduct(Inventory& inventory,  Product product,SystemLog&log);
    void updateProduct(Inventory& inventory, string productName,  Product updatedProduct,SystemLog&log);
    void updatePrice(Inventory& inventory,string productName, double p,SystemLog&log);
    void updatestock(Inventory& inventory, string  productName,int stock,SystemLog&log);
    void deleteProduct(Inventory& inventory, string productName,SystemLog&log);
    void addcategory(Inventory& inventory,Category category,SystemLog&log);
    void viewlowstock(Inventory& inventory,int threshold,SystemLog&log);
    void applydiscount(Inventory& inventory,string name,SystemLog&log);
   //validation
    bool validatepass(string pass);
    //Analytics
    void viewSalesReports(Analytics& analytics, OrderQueue& orderQueue, linkedlist<Product>* productList);
    void viewCustomerBehavior(Analytics& analytics, loyaltyprogram& loyaltyProgram, const string& customerId);
    void viewInventoryAlerts(Analytics& analytics, PriorityQueue& lowStockQueue);

    // Order Queue Management
    void processOrders(OrderQueue& orderQueue, linkedlist<Product>* productList);

       
};

#endif // ADMIN_H
