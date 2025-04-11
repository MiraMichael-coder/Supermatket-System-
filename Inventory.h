#ifndef INVENTORY_H
#define INVENTORY_H


#include "Product.h"
#include "Category.h"
#include <iostream>
#include <string>
#include<vector>
#include "ProrityQueue.h" 
#include "SystemLog.h" 
#include "LinkedListTemplate.h"
using namespace std;

class Inventory {

   
    
public:

    linkedlist<Product> inventoryList;  // Generic linked list for products
    linkedlist<Category> categoryList; // Generic linked list for categories
    PriorityQueue lowStockQueue;
    // Private helper functions
    // Constructor
     Inventory(const linkedlist<Product>&productList):inventoryList(productList) {}
      Inventory();
    // Public methods
    void addProduct(Product product,SystemLog&log);
    void updateProduct(string name, Product updatedProduct,SystemLog&log);
    void removeProduct(string name,SystemLog&log);
    Product searchProduct(string name,SystemLog&log);
    void generateInventoryReport(SystemLog&log);
    void alertLowStock(int threshold,SystemLog&log);
    void addCategory(Category category,SystemLog&log);
    void searchProductInCategory(string categoryName, string productName,SystemLog&log);
    void addProductToCategory(string categoryName, Product product,SystemLog&log);
    void removeProductFromCategory(string name,SystemLog&log);
    void display();
    void displayproduct();
    void updatestock(string name,int s,SystemLog&log);
    void updateprice(string name,double p,SystemLog&log);
    void updatecaetgory(string name,string category,SystemLog&log);
    void applydiscount(string name,SystemLog&log);
    void  displaycategoryonly();
   
};

#endif // INVENTORY_H
