#include "Inventory.h"
#include<iostream>

using namespace std;
Inventory::Inventory(){}
//update product price
void Inventory::updateprice(string name,double p, SystemLog&log)
{
    
    Product *found= inventoryList.search(name);
    if(found != nullptr && found->getname() != "")
    {  found->setPrice(p);
       log.addLog("Updated product's price : " + name + " in inventory.");
    }
    else 
    {
        log.addLog("Attempted to update product's price: " + name + " but it was not found.");
        cout << "Product not found.\n";
    }
}
//update products category
void Inventory::updatecaetgory(string name, string category,SystemLog&log)
{
    Product *found=inventoryList.search(name);
    if(found != nullptr && found->getname() != "")
    {
        found->setcategory(category);
        log.addLog("Updated product's Category : " + name + " in inventory.");
        removeProductFromCategory(name,log);
        addProductToCategory(category,*found,log);
    }
    else 
    {
        log.addLog("Attempted to update product's Category: " + name + " but it was not found.");
        cout << "Product not found.\n";
    }
}
//Update product stock
void Inventory::updatestock(string name, int s ,SystemLog&log)
{
    Product *found=inventoryList.search(name);
    if(found != nullptr && found->getname() != "")
    {
        found->setStock(s);
        log.addLog("Updated product's stock : " + name + " in inventory.");
    }
    else{
        log.addLog("Attempted to update product's Stock: " + name + " but it was not found.");
        cout << "Product not found.\n";
    }
}
//Apply seasonal discount
void Inventory::applydiscount(string name,SystemLog& log)
{
    Product *found=inventoryList.search(name);
    if(found != nullptr && found->getname() != "")
    { 
        found->setseasonal();
        log.addLog("Applied seasonal discount on product: " + name + " in inventory.");
        double d=found->getPrice()*0.9;
        updateprice(name,d,log);
    }
     else{
        log.addLog("Attempted to apply seasonal discount on product: " + name + " but it was not found.");
        cout << "Product not found.\n";
    }
}
// Add product to inventory (linked list) and automatically to category
void Inventory::addProduct(Product product,SystemLog& log) {
    // Add to inventory linked list
    inventoryList.addtoTail(product);// Add product to the linked list
    // Add to the correct category's BST   
addProductToCategory(product.getCategory(), product,log);
    lowStockQueue.add(product);
    log.addLog("Added product: " + product.getname() + " to inventory.");
}

// Update the product details in inventory
void Inventory::updateProduct(string name, Product updatedProduct,SystemLog& log) {
    Product *existing = inventoryList.search(name);

    if(existing != nullptr && existing->getname() != "") {
        removeProduct(name, log);  // Remove the existing product
        addProduct(updatedProduct, log);  // Add the updated product
        log.addLog("Updated product: " + name + " in inventory.");
        cout << "Product updated.\n";
    } else {
        log.addLog("Attempted to update product: " + name + " but it was not found.");
        //cout << "Product not found.\n";
    }
}
// Remove product from inventory by name
void Inventory::removeProduct(string name,SystemLog& log) {
     Product *toRemove = inventoryList.search(name);
    if (toRemove!=nullptr&&toRemove->getname() != "") {  //if it is found !
        inventoryList.removeByValue(*toRemove);  // Use the new removeByValue function
        removeProductFromCategory(name, log);  // Remove the product from all categories
        lowStockQueue.removeByProduct(*toRemove);  // Remove from the low stock queue
        log.addLog("Removed product: " + name + " from inventory.");
        cout << "Product removed.\n";
    } else {
        log.addLog("Attempted to remove product: " + name + " but it was not found.");
        cout << "Product not found.\n";
    }
}
// Search for a product by name in the inventory
Product Inventory::searchProduct(string name, SystemLog& log) {
    Product *found = inventoryList.search(name);  // Search in the linked list
    if (found!=nullptr&&found->getname() != "") {
        log.addLog("Searched for product: " + name + " in inventory.");
        return *found;
    }
    log.addLog("Attempted to search for product: " + name + " in inventory, but it was not found.");
    cout << "Product not found.\n";
    return Product();
}
// Generate inventory report (list all products)
void Inventory::generateInventoryReport(SystemLog& log) {
   log.addLog("Generated inventory report.");
    cout << "Inventory Report:\n";
    inventoryList.displaydetails();
}
// Alert for products with low stock 
void Inventory::alertLowStock(int threshold ,SystemLog& log) {
    log.addLog("Low stock alert check triggered.");
    if (threshold==0)
    {
       if (lowStockQueue.isEmpty()) {
            cout << "No products with low stock at the moment.\n";
        } else {
            lowStockQueue.displayLowStockAlerts();
        }
        return;
    }
    else {
            
     linkedlist<Product>::ListNode* current = inventoryList.getHead();
    bool foundLowStock = false; // Flag to check if any low-stock product is found
    cout << "Low stock products (threshold: " << threshold << "):\n";
    if(!current)
    {cout<<"No low stock"<<endl; 
    return;
    }
    
    while (current != nullptr) {
        if (current->info.getstock() < threshold) {
            foundLowStock = true;
            log.addLog("Low stock alert for product: " + current->info.getname());
            cout << "- " << current->info.getname() << ": " << current->info.getstock() << " units left.\n";
        }
        current = current->next;
    }
   
}
}
// Add a new category to the inventory
void Inventory::addCategory(Category category,SystemLog& log) {
     categoryList.addtoTail(category);  // Add category to the linked list
    log.addLog("Added new category: " + category.getname() + " to inventory.");
}
// Add a product to a specific category's BST
void Inventory::addProductToCategory(string categoryName, Product product,SystemLog& log) {
    linkedlist<Category>::ListNode* temp = categoryList.head;
    while (temp) {
        if (temp->info.getname() == categoryName) 
            {
             temp->info.insert(product);  // Insert the product into the BST of the category
             log.addLog("Added product: " + product.getname() + " to category: " + categoryName + ".");
             //cout << "Product added to category: " << categoryName << endl;
            return;
            }

        temp = temp->next;
    }
    
    //cout << "Category not found. Creating a new category for the product.\n";
    // If category does not exist, create a new one
    Category newCategory;
    newCategory.setCategoryName(categoryName);
    addCategory(newCategory,log);
    addProductToCategory(categoryName, product,log);  // Recur to add the product
}
// Remove a product from a specific category
void Inventory::removeProductFromCategory(string name,SystemLog& log) {
    linkedlist<Category>::ListNode* current = categoryList.head;
     while(current)  {
        current->info.deleteNode(name);// Remove the product from the category
        log.addLog("Removed product: " + name + " from all categories.");
        current = current->next;
    }
}
// Search for a product in a specific category
void Inventory::searchProductInCategory(string categoryName, string productName,SystemLog& log) {
   Category *c=categoryList.search(categoryName);
        if (c&&c->getname()!="") {
           Product foundProduct = c->search(productName);
            if (foundProduct.getname() != "") {
                cout << "Found product in category " << categoryName << ": " << foundProduct.getname() << endl;
                return;
            }
        }
    
    cout << "Category not found or product not found in the category.\n";
}
void Inventory::display() {
     cout << "Displaying All Products in Inventory:\n";
    inventoryList.displaydetails();  // Display all products

    cout << "\nDisplaying All Categories in Inventory:\n";
    linkedlist<Category>::ListNode* current = categoryList.head;
     while(current)  {
        cout << "Category: " << current->info.getname() << endl;
        current=current->next;
    }
}
   void Inventory::displayproduct()
   {
        cout << "Displaying All Products in Inventory:\n";
        inventoryList.displaydetails();  // Display all products
   }
void Inventory :: displaycategoryonly()
{   cout << "\nDisplaying All Categories in Inventory:\n";
    linkedlist<Category>::ListNode* current = categoryList.head;
     while(current){
        cout << "Category: " << current->info.getname() << endl;
        current=current->next;
        }
}
