#include "Inventory.h"
#include "loyaltyprogram.h"
#include "SystemLog.h"
#include "Product.h"
#include "Category.h"
#include "ShoppingCart.h"
#include "Order.h"
#include "customerprofile.h"
#include "Admin.h"
#include "Loyaltyprogram.h"
#include "OrderQueue.h" 
#include <string>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


string capitalizeFirstLetter(const std::string& input) {
    if (input.empty()) {
        return input; // Return empty string if input is empty
    }

    std::string result = input;
    result[0] = std::toupper(result[0]); // Capitalize the first letter
    for (size_t i = 1; i < result.size(); ++i) {
        result[i] = std::tolower(result[i]); // Convert the rest to lowercase
    }

    return result;
}

void initializeLoyaltyProgram(loyaltyprogram& loyaltyProgram,linkedlist<Product> productList) {
    cout << "Initializing loyalty program with customers...\n";

    // Add customers to the loyalty program
   
    loyaltyProgram.addnewcustomer("CUST1","Zeina",120);
    loyaltyProgram.addnewcustomer("CUST2","Mira",30);
    loyaltyProgram.addnewcustomer("CUST3","Menna",300);
    loyaltyProgram.addnewcustomer("CUST4","Maya",80);
    cout << "Loyalty program initialized successfully with customers.\n";
}
void initializeProducts(Inventory& inventory, linkedlist<Product>& productList, SystemLog& log) {
       cout << "Initializing products...\n";
    // Add products to inventory
   Product p1("Apple", "Fruits",5.0, 100,2);
    Product p2("Banana", "Fruits", 3.5,43,6);
    Product p3("Carrot", "Vegetables",1.20, 155,7);
    Product p4("Orange", "Fruits",7.5, 10,8);
    Product p5("Pasta", "Cupboard",40.35, 60,9);
    Product p6("Candy", "Snack",45.5,60,10);
    Product p7("Softner", "Detergents", 170.8, 23,0);
    Product p8("Batteries", "Home", 230.01, 17,3);
    Product p9("Candles", "Home",60.99, 9,1);
    Product p10("Coke", "Beverages", 14.99, 11,5);
    Product p11("Chocolate", "Snack",50.032, 33,20);
    Product p12("Milk", "Dairy", 55, 115,4 );
    //Product p13("Greek Yogurt", "Dairy",35,3);
    //Product p14("Juice", "Beverages",12, 8);
    //Product p15("Chips", "Snacks",10,60);
    //Product p16("Tissues", "Tissues", 20,40);
    //Product p17("Shampoo", "Personalcare", 150,99);
    //Product p18("Conditioner","Personalcare",230,19);
    //Product p19("Babyfood", "Babyproducts", 50, 2);
    //Product p20("Cleaner", "Cleaning", 43, 50);
    inventory.addProduct(p1, log);
    inventory.addProduct(p2, log);
    inventory.addProduct(p3, log);
    inventory.addProduct(p4, log);
    inventory.addProduct(p5, log);
    inventory.addProduct(p6, log);
    inventory.addProduct(p7, log);
    inventory.addProduct(p8, log);
    inventory.addProduct(p9, log);
    inventory.addProduct(p10, log);
    inventory.addProduct(p11, log);
    inventory.addProduct(p12, log);
    //inventory.addProduct(p13, log);
    //inventory.addProduct(p14, log);
    //inventory.addProduct(p15, log);
    //inventory.addProduct(p16, log);
    //inventory.addProduct(p17, log);
    //inventory.addProduct(p18, log);
    //inventory.addProduct(p19, log);
    //inventory.addProduct(p20, log);
   
    productList.addtoTail(p1);
    productList.addtoTail(p2);
    productList.addtoTail(p3);
    productList.addtoTail(p4);
    productList.addtoTail(p5);
    productList.addtoTail(p6);
    productList.addtoTail(p7);
    productList.addtoTail(p8);
    productList.addtoTail(p9);
    productList.addtoTail(p10);
    productList.addtoTail(p11);
    productList.addtoTail(p12);
    //productList.addtoTail(p13);
    //productList.addtoTail(p14);
    //productList.addtoTail(p15);
   // productList.addtoTail(p16);
    //productList.addtoTail(p17);
    //productList.addtoTail(p18);
    //productList.addtoTail(p19);
    //productList.addtoTail(p20);


   
    cout << "Products initialized successfully.\n";
}
void initializeOrders(OrderQueue& orderQueue, loyaltyprogram& loyaltyProgram, linkedlist<Product>& productList) {
    cout << "Initializing orders...\n";

    // Fetch customers from the loyalty program
    customerprofile* customer1 = loyaltyProgram.getcustomerprofile("CUST1");
    customerprofile* customer2 = loyaltyProgram.getcustomerprofile("CUST2");

    if (!customer1 || !customer2) {
        cout << "Error: Customers not found in loyalty program. Ensure they are initialized.\n";
        return;
    }
    // Create shopping carts for orders
    ShoppingCart shoppingCart1;
    shoppingCart1.addItem(productList.head->info, 5); // Adding 5 apples
    shoppingCart1.addItem(productList.head->next->info, 10); // Adding 10 bananas
    Order order1(customer1, shoppingCart1);

    ShoppingCart shoppingCart2;
    shoppingCart2.addItem(productList.head->info, 2); // Adding 2 apples
    Order order2(customer2, shoppingCart2);

    // Add orders to the queue
    orderQueue.addOrder(order1, &productList);
    orderQueue.addOrder(order2, &productList);

    cout << "Orders initialized successfully.\n";
}
void displayadmin() {
    cout << "\n================= Admin Menu =================\n";
    cout << "1.  Add Product\n";
    cout << "2.  Update Product\n";
    cout << "3.  Update Product Price\n";
    cout << "4.  Update Product Stock\n";
    cout << "5.  Delete Product\n";
    cout << "6.  Add Category\n";
    cout << "7.  View Low Stock Alerts\n";
    cout << "8.  Apply Discount\n";
    cout << "9.  View Sales Reports\n";
    cout << "10. View Customer Behavior\n";
    cout << "11. View Inventory Alerts\n";
    cout << "12. Process Orders\n";
    cout << "13. Apply Promotions to Least Demanded Items\n";
    cout << "14. Display Inventory \n";
    cout << "0.  Exit\n";
    cout << "=============================================\n";
    cout << "Enter your choice: ";
}
void displaycustomer()
{
        cout << "\n--- Customer Menu ---" << endl;
        cout << "1. Browse Products by Category" << endl;
        cout << "2. Search Product by Name" << endl;
        cout << "3. View Cart" << endl;
        cout << "4. Review Cart" << endl;
        cout << "5. Checkout" << endl;
        cout << "6. Display Customer Profile" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
}
void adminmode(Admin &admin, Inventory& inventory, SystemLog& log, Analytics& analytics, OrderQueue& orderQueue, linkedlist<Product>* productList, loyaltyprogram& loyaltyProgram, PriorityQueue& lowStockQueue)
{
    int choice=-1;
    while(choice!=0)
    {   
        displayadmin();
         // Validate user input
        while (!(cin >> choice)) {
            cin.clear();                // Clear the error flag
            cin.ignore(10000, '\n');    // Discard invalid input
            cout << "Invalid input. Please enter a number from the menu: ";
        }

        switch (choice) {
            case 1: {
    // Add Product
    string name, category;
    double price;
    int stock;
    bool validInput = false;

    do {
        cout << "Enter product details...\n";
        cout << "Enter product name: ";
        cin >> name;
        name = capitalizeFirstLetter(name);

        cout << "Enter product category: ";
        cin >> category;
        category = capitalizeFirstLetter(category);

        cout << "Enter product price: ";
        cin >> price;
        if (price < 0) {
            cout << "Price cannot be negative. Please try again.\n";
            continue;
        }

        cout << "Enter product stock: ";
        cin >> stock;
        if (stock < 0) {
            cout << "Stock cannot be negative. Please try again.\n";
            continue;
        }

        validInput = true;
        Product product(name, category, price, stock);
        admin.addProduct(inventory, product, log);
        inventory.displayproduct();
    } while (!validInput); // Repeat until valid input is provided
    break;
}

    case 2: {
    // Update Product
    inventory.displayproduct();
    string productName, newCategory;
    double newPrice;
    int newStock;
    bool productFound = false;

    do {
        cout << "Enter the product name to update: ";
        cin >> productName;
        productName = capitalizeFirstLetter(productName);

        Product p = inventory.searchProduct(productName, log);
        if (p.getname().empty()) {
            cout << "Product not found. Please try again.\n";
            continue;
        }

        productFound = true;
        cout << "Enter updated product details...\n";
        cout << "Enter new category: ";
        cin >> newCategory;
        newCategory = capitalizeFirstLetter(newCategory);

        cout << "Enter new price: ";
        cin >> newPrice;
        if (newPrice < 0) {
            cout << "Price cannot be negative. Please try again.\n";
            productFound = false;
            continue;
        }

        cout << "Enter new stock: ";
        cin >> newStock;
        if (newStock < 0) {
            cout << "Stock cannot be negative. Please try again.\n";
            productFound = false;
            continue;
        }

        Product updatedProduct(productName, newCategory, newPrice, newStock);
        admin.updateProduct(inventory, productName, updatedProduct, log);
        cout << "Inventory after updates...." << endl;
        inventory.displayproduct();
    } while (!productFound); // Repeat until valid product and input are provided
    break;
}

    case 3: {
    // Update Price
    inventory.displayproduct();
    string productName;
    double newPrice;
    bool productFound = false;

    do {
        cout << "Enter the product name to update price: ";
        cin >> productName;
        productName = capitalizeFirstLetter(productName);

        Product p = inventory.searchProduct(productName, log);
        if (p.getname().empty()) {
            cout << "Product not found. Please try again.\n";
            continue;
        }

        productFound = true;
        cout << "Here is the old price: $" << p.getPrice() << endl;
        cout << "Enter new price: ";
        cin >> newPrice;
        if (newPrice < 0) {
            cout << "Price cannot be negative. Please try again.\n";
            productFound = false;
            continue;
        }

        admin.updatePrice(inventory, productName, newPrice, log);
        cout << "Inventory after updates...." << endl;
        inventory.displayproduct();
    } while (!productFound); // Repeat until valid product and input are provided
    break;
}          
case 4: {
    // Update Stock
    bool productFound = false;
    inventory.displayproduct();
    do {

        string productName;
        int newStock;
        cout << "Enter the product name to update stock: ";
        cin >> productName;

        // Capitalize the first letter of the product name
        productName = capitalizeFirstLetter(productName);

        Product p = inventory.searchProduct(productName, log);
        if (p.getname().empty()) {
            //cout << "Product not found. Please try again.\n";
        } else {
            productFound = true;
            cout << "Here is the old stock: " << p.getstock() << endl;
            cout << "Enter new stock quantity: ";
            cin >> newStock;
            admin.updatestock(inventory, productName, newStock, log);
            cout << "Inventory after updates...." << endl;
            inventory.displayproduct();
        }
    } while (!productFound); // Keep looping until the product is found
    break;
}

case 5: {
    // Delete Product
        bool productFound = false;
        inventory.displayproduct();
        do {

            string productName;
            cout << "Enter the product name to delete: ";
            cin >> productName;

            // Capitalize the first letter of the product name
            productName = capitalizeFirstLetter(productName);

            Product p = inventory.searchProduct(productName, log);
            if (p.getname().empty()) {
                //cout << "Product not found. Please try again.\n";
            } else {
                productFound = true;
                admin.deleteProduct(inventory, productName, log);
                cout << "Inventory after updates...." << endl;
                inventory.displayproduct();
            }
        } while (!productFound); // Keep looping until the product is found
        break;
    }
            case 6: {
                // Add Category
                inventory.displaycategoryonly();
                string categoryName;
                cout << "Enter the new category name: ";
                cin >> categoryName;
                Category category;
                category.setCategoryName(categoryName);
                admin.addcategory(inventory, category, log);
                cout<<"After adding new category..."<<endl;
                inventory.displaycategoryonly();
                break;
            }
            case 7: {
                // View Low Stock
                int threshold;
                cout << "Enter the stock threshold: ";
                cin >> threshold;
                admin.viewlowstock(inventory, threshold, log);
                break;
            }
case 8: {
    // Apply Discount
        bool productFound = false;
        do {
            inventory.displayproduct();
            string productName;
            cout << "Enter the product name to apply seasonal discount: ";
            cin >> productName;

            // Capitalize the first letter of the product name
            productName = capitalizeFirstLetter(productName);

            // Check if the product exists
            Product p = inventory.searchProduct(productName, log);
            if (p.getname().empty()) {
                cout << "Product not found. Please try again.\n";
            } else {
                productFound = true;
                admin.applydiscount(inventory, productName, log);
                cout << "Discount applied successfully!\n";
                inventory.displayproduct();
            }
        } while (!productFound); // Repeat until the product is found
        break;
    }
             case 9: {
                // View Sales Reports
                admin.viewSalesReports(analytics, orderQueue, productList);
                break;
            }
            case 10: {
                // View Customer Behavior
                string customerId;
                cout << "Enter the customer ID to view behavior: ";
                cin >> customerId;
                admin.viewCustomerBehavior(analytics, loyaltyProgram, customerId);
                break;
            }
           case 11: {
                // View Inventory Alerts
                admin.viewInventoryAlerts(analytics,lowStockQueue);
                break;
            }
            case 12: {
                // Process Orders
                admin.processOrders(orderQueue, productList);
                break;
                }
case 13: {
    cout << "Applying promotion to the least demanded items...\n";

    // Get the sorted product list by demand
    linkedlist<Product>* sortedProductList = orderQueue.mostDemanded(productList);

    // Check if the sorted list is valid and not empty
    if (!sortedProductList || sortedProductList->getHead() == nullptr) {
        cout << "No products available for promotion.\n";
        break;
    }

    // Traverse the list to find the least demanded products
    linkedlist<Product>::ListNode* node = sortedProductList->getHead();
    int promotionCount = 0;

    // Traverse to the last node (least demanded product)
    while (node && node->next) {
        node = node->next;
    }

    // Apply promotion to up to three least demanded products
    while (node && promotionCount < 3) {
        Product& product = node->info;
        cout << "Promoting product: " << product.getname() << ", Demand: " << product.getDemandCount() << endl;

        // Apply a 20% discount to the product price
        double oldPrice = product.getPrice();
        double newPrice = oldPrice * 0.8; // 20% discount
        inventory.updateprice(product.getname(), newPrice, log);

        // Log the promotion
        log.addLog("Promotion applied to product: " + product.getname() +
                   ". Old Price: $" + to_string(oldPrice) +
                   ", New Price: $" + to_string(newPrice));

        // Print updated product details
        cout << "New price for " << product.getname() << ": $" << newPrice << endl;

        // Find the previous node manually (reverse traversal in singly linked list)
        linkedlist<Product>::ListNode* prevNode = sortedProductList->getHead();
        while (prevNode && prevNode->next != node) {
            prevNode = prevNode->next;
        }
        node = prevNode; // Move to the previous node

        promotionCount++;
    }

    if (promotionCount == 0) {
        cout << "No products eligible for promotion.\n";
    } else {
        cout << "Promotions successfully applied to " << promotionCount << " products.\n";
    }

    break;
}

case 14: {
    // Display Products
    cout << "Displaying all products in the inventory...\n";
    inventory.display();
    break;
}
            case 0:
                cout << "Exiting Admin Menu...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}
void CustomerMode(Inventory &inventory , CartItem &cart, linkedlist<Product>& productList,Order &order, ShoppingCart&shopping, Category &category, SystemLog &log,OrderQueue &orderQueue,customerprofile*customer,loyaltyprogram &loyalty)
{

    int choice;
    customer->getDetails();
    do
    {
        displaycustomer();
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            while (true) { // Loop to allow retry for category selection
                cout << "Available Categories: " << endl;
                inventory.displaycategoryonly();  // Display all available categories

                string chosenCategory;
                cout << "Enter category to browse (or type 'exit' to return to main menu): ";
                cin >> chosenCategory;

                // Capitalize the first letter of the chosen category
                chosenCategory = capitalizeFirstLetter(chosenCategory);

                if (chosenCategory == "Exit") {
                    cout << "Returning to main menu." << endl;
                    break;  // Exit the category browsing
                }

                Category* c = inventory.categoryList.search(chosenCategory);
                if (c && c->getname() != "") {
                    while (true) { // Loop to allow retry for product selection
                        c->inOrderTraversal();  // Display products in the chosen category

                        string productName;
                        cout << "Enter product name to view or add to cart (or type 'back' to choose another category): ";
                        cin >> productName;

                        // Capitalize product name and search
                        productName = capitalizeFirstLetter(productName);

                        if (productName == "Back") {
                            cout << "Returning to category selection." << endl;
                            break;  // Exit product browsing and return to category selection
                        }

                        Product product = inventory.searchProduct(productName, log);
                        if (product.getname() != "") {
                            cout << "Product Found: " << product.getname() << " - $" << product.getPrice() << endl;
                            cout << "Add to cart? (1: Yes / 0: No): ";
                            int add, quan;
                            cin >> add;

                            if (add == 1) {
                                while (true) { // Loop to validate quantity input
                                    cout << "Enter quantity desired: ";
                                    cin >> quan;

                                    if (quan > 0 && quan <= product.getstock()) {
                                        shopping.addItem(product, quan);  // Add product to cart
                                        cout << "Added to cart." << endl;
                                        break;  // Exit quantity input loop after successful add
                                    } else if (quan <= 0) {
                                        cout << "Invalid quantity. Please enter a quantity greater than 0." << endl;
                                    } else {
                                        cout << "Requested quantity exceeds stock. Please enter a quantity less than or equal to " << product.getstock() << endl;
                                    }
                                }
                            } else {
                                cout << "Product not added to cart." << endl;
                            }
                            break;  // Exit product browsing loop
                        } else {
                            cout << "Product not found. Try again." << endl;
                        }
                    }
                } else {
                    cout << "No products found in this category. Try another category or type 'exit'." << endl;
                }
            }
            break;
        }
        case 2:
        {
                // Display all available products
                cout << "Available Products:\n";
                inventory.displayproduct(); // Method to display all products in the inventory

                string productName;
                bool productFound = false;

                do {
                    cout << "\nEnter the product name you want: ";
                    cin >> productName;

                    // Capitalize product name and search
                    productName = capitalizeFirstLetter(productName);
                    Product product = inventory.searchProduct(productName, log);

                    if (product.getname() != "") {
                        productFound = true;
                        cout << "Product Found: " << product.getname() << " - Price: $" << product.getPrice()
                             << " - Stock: " << product.getstock() << endl;

                        cout << "Add to cart? (1: Yes / 0: No): ";
                        int add, quan;
                        cin >> add;

                        if (add == 1) {
                            while (true) {
                                cout << "Enter quantity desired (Available: " << product.getstock() << "): ";
                                cin >> quan;

                                if (quan > 0 && quan <= product.getstock()) {
                                    shopping.addItem(product, quan);  // Add product to cart
                                    cout << "Added to cart." << endl;
                                    break;  // Exit quantity input loop after successful add
                                } else if (quan <= 0) {
                                    cout << "Invalid quantity. Please enter a quantity greater than 0." << endl;
                                } else {
                                    cout << "Requested quantity exceeds stock. Please enter a quantity less than or equal to "
                                         << product.getstock() << endl;
                                }
                            }
                        } else {
                            cout << "Product not added to cart.\n";
                        }
                    } else {
                        cout << "Product not found. Please try again.\n";
                    }
                } while (!productFound);  // Loop until a valid product is found
                break;
            }


        case 3:
        {
            cout<<"\n---Shopping Cart---"<<endl;
            shopping.getDetails();
            break;
        }

        case 4:
            {
                cout << "\n--- Shopping Cart Review ---" << endl;
                shopping.getDetails();  // Display current cart details

                string response;
                bool validResponse = false;

                // Ask user if they want to edit the cart
                do {
                    cout << "\nWould you like to edit your cart? (yes / no): ";
                    cin >> response;
                    for (size_t i = 0; i < response.length(); ++i) {
                        response[i] = tolower(response[i]);
                    }

                    if (response == "yes") {
                        validResponse = true;
                        bool editing = true;
                        while (editing) {
                            cout << "\nWhat would you like to do?" << endl;
                            cout << "1. Add an item" << endl;
                            cout << "2. Remove an item" << endl;
                            cout << "3. Update item quantity" << endl;
                            cout << "4. Exit cart editing" << endl;
                            cout << "Enter your choice: ";
                            int editChoice;
                            cin >> editChoice;

                            if (editChoice == 1) {
                                // Add item logic
                                while (true) {
                                    cout << "Enter product name to add (or type 'exit' to skip): ";
                                    string productName;
                                    cin.ignore();
                                    getline(cin, productName);
                                    productName = capitalizeFirstLetter(productName);

                                    if (productName == "Exit") break;

                                    Product product = inventory.searchProduct(productName, log);
                                    if (product.getname() != "") {
                                        while (true) {
                                            cout << "Enter quantity to add: ";
                                            int quantity;
                                            cin >> quantity;

                                            if (quantity > 0 && quantity <= product.getstock()) {
                                                shopping.addItem(product, quantity);
                                                cout << "Product added to cart." << endl;
                                                break;
                                            } else {
                                                cout << "Invalid quantity. Please enter a value between 1 and " << product.getstock() << "." << endl;
                                            }
                                        }
                                        break;  // Exit outer loop after successfully adding
                                    } else {
                                        cout << "Product not found. Try again? (yes / no): ";
                                        string retry;
                                        cin >> retry;
                                        if (tolower(retry[0]) != 'y') break;
                                    }
                                }
                            } else if (editChoice == 2) {
                                // Remove item logic
                                while (true) {
                                    cout << "Enter product name to remove (or type 'exit' to skip): ";
                                    string productName;
                                    cin.ignore();
                                    getline(cin, productName);
                                    productName = capitalizeFirstLetter(productName);

                                    if (productName == "Exit") break;

                                    CartItem* n = shopping.cartList.search(productName);
                                    if (n != nullptr) {
                                        int quantityToRemove;
                                        while (true) {
                                            cout << "Enter quantity to remove: ";
                                            cin >> quantityToRemove;

                                            if (quantityToRemove > 0 && quantityToRemove <= n->getquantity()) {
                                                if (quantityToRemove == n->getquantity()) {
                                                    shopping.removeItem(productName);
                                                    cout << "Product removed from cart." << endl;
                                                } else {
                                                    n->updateQuantity(n->getquantity() - quantityToRemove);
                                                    cout << "Updated cart. " << n->getquantity() << " remaining in cart." << endl;
                                                }
                                                break;
                                            } else {
                                                cout << "Invalid quantity. Please enter a value between 1 and " << n->getquantity() << "." << endl;
                                            }
                                        }
                                        break;  // Exit outer loop after success
                                    } else {
                                        cout << "Product not found. Try again? (yes / no): ";
                                        string retry;
                                        cin >> retry;
                                        if (tolower(retry[0]) != 'y') break;
                                    }
                                }
                            } else if (editChoice == 3) {
                                // Update item quantity logic
                                while (true) {
                                    cout << "Enter product name to update (or type 'exit' to skip): ";
                                    string productName;
                                    cin.ignore();
                                    getline(cin, productName);
                                    productName = capitalizeFirstLetter(productName);

                                    if (productName == "Exit") break;

                                    CartItem* n = shopping.cartList.search(productName);
                                    if (n != nullptr) {
                                        while (true) {
                                            cout << "Enter new quantity: ";
                                            int newQuantity;
                                            cin >> newQuantity;

                                            Product product = inventory.searchProduct(productName, log);
                                            if (newQuantity > 0 && newQuantity <= product.getstock()) {
                                                n->updateQuantity(newQuantity);
                                                cout << "Updated quantity. " << n->getquantity() << " in cart now." << endl;
                                                break;
                                            } else {
                                                cout << "Invalid quantity. Enter a value between 1 and " << product.getstock() << "." << endl;
                                            }
                                        }
                                        break;
                                    } else {
                                        cout << "Product not found. Try again? (yes / no): ";
                                        string retry;
                                        cin >> retry;
                                        if (tolower(retry[0]) != 'y') break;
                                    }
                                }
                            } else if (editChoice == 4) {
                                // Exit cart editing
                                editing = false;
                                cout << "Exiting cart editing." << endl;
                            } else {
                                cout << "Invalid choice. Please try again." << endl;
                            }
                        }
                    } else if (response == "no") {
                        validResponse = true;
                        cout << "No changes made to the cart." << endl;
                    } else {
                        cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
                    }
                } while (!validResponse);
                break;
            }
        case 5:
        {
                 // Show cart details to the user
                cout << "\n--- Your Cart ---\n";
                shopping.getDetails();  // Display all items in the cart
                double taxRate = 0.14;


                if(shopping.cartList.head!=nullptr)
                {
                    Order order(customer,shopping);
                    order.additemtoOrder(inventory,log);
                // Calculate total cocustomert before applying promo code

                // Dicustomerplay order de
                //cout << "\n--- Order Detailcustomer ---\n";
                //order.dicustomerplayOrderDetailcustomer();
                    // Calculate the total cocustomert after applying the promo code
                    cout<<customer->getID()<<endl;
                    double totalCostAfterPromo = order.calculateTotalCost(taxRate);
                    cout << "Total after applying promo code: $" << fixed << setprecision(2) << totalCostAfterPromo << endl;

                    int earnedPoints = totalCostAfterPromo; // Reward points based on total cost
                    customer->addrewardpoint(earnedPoints);


                    orderQueue.addOrder(order,&productList);

                // Update order status and set estimated processing time based on real-time
                    order.updateStatus("Confirmed");
                    order.setEstimatedProcessingTime(24);  // Real-time estimated processing time

                    cout << "\nYour order has been placed successfully! Order ID: " << order.getOrderId() << endl;
                    cout << "Estimated processing time: " << order.getEstimatedProcessingTime() << endl;
                }
                else
                {

                    cout<<"No order to proceed"<<endl;
                }
                break;
        }
        case 6:
            {
                 cout << "\n--- Customer Profile ---\n";
                customer->getDetails();

                 break;
            }
        case 7:
            {
                cout << "Exiting the customer menu." << endl;
                break;
            }


        }
    }while(choice != 7);
}
int main() {
    // Initialize core components
    SystemLog log;               // System log
    Inventory inventory;         // Inventory
    Analytics analytics;         // Analytics
    OrderQueue orderQueue;       // Order queue
    loyaltyprogram loyaltyProgram;  // Loyalty program
    PriorityQueue lowStockQueue; // Low stock priority queue
    CartItem cart;
    Category category;
    Order order;
    ShoppingCart shopping;
    linkedlist<Product> productList; // Linked list for products
    Admin admin1("Cherry", "123");   // Admin
    // Initialize products, orders, and loyalty program
    initializeProducts(inventory, productList, log);
    initializeLoyaltyProgram(loyaltyProgram,productList);

    // Main program loop
    char choice;
    do {
        cout << "Enter choice (A: Admin Mode, C: Customer Mode, Q: Quit): ";
        cin >> choice;

        if (tolower(choice) == 'a') {
            // Admin Mode
            cout<<"Enter Password for admin:"<<endl;
            string pass;
            cin>>pass;
            if (admin1.validatepass(pass))
            adminmode(admin1, inventory, log, analytics, orderQueue, &productList, loyaltyProgram, lowStockQueue);
            else
              {
                    cout<<"Wrong Password...."<<endl;
                continue;
              }
        }
        else if (tolower(choice) == 'c')
        {
            string name;
            int points;
            char loginChoice;
            char proceedChoice;
            customerprofile currentCustomer ;
                    string id;
        // Ask if the user is a customer
                // Proceed with login or sign-up
                cout << "Are you an existing customer? (L: Login / S: Sign Up): ";
                cin >> loginChoice;
                if (tolower(loginChoice) == 'l')
                {
                        cout << "Enter Customer ID: ";
                        cin >> id;
                // Get customer profile using ID
                    customerprofile* currentCustomer = loyaltyProgram.getcustomerprofile(id);
                    if (currentCustomer != nullptr)
                    {
                            cout << "Welcome back, " << currentCustomer->getname() << "!" << endl;
                            currentCustomer->getDetails();  // Display customer details
                        if (currentCustomer->getID ()!= "" )
                        {
                            CustomerMode(inventory, cart, productList, order, shopping, category, log, orderQueue, currentCustomer, loyaltyProgram);
                        }
                    }
                }
                else if (tolower(loginChoice) == 's')
                {
                    string name;
                    cout << "Enter your name: ";
                    cin.ignore();
                    getline(cin, name);

                    loyaltyProgram.addnewcustomer("",name);
                    customerprofile *c= loyaltyProgram.getcustomer(name);
                    cout << "Account created! Welcome, " << c->getID() << ".\n";
                     cout << "Do you want to enter Customer Mode? (Y: Yes / N: No): ";
                cin >> proceedChoice;
                if (tolower(proceedChoice) == 'y')
                {
                    // Call Customer.Mode function here (pass necessary parameters)
                        CustomerMode(inventory, cart, productList, order, shopping, category, log, orderQueue, c, loyaltyProgram);
                }
            }
        }
         else if (tolower(choice) != 'q') {
            cout << "Invalid input. Please enter 'A', 'C', or 'Q'.\n";
        }
    } while (tolower(choice) != 'q');
    log.displayLogs();
    cout<<"Bye!"<<endl;
    
    return 0;
}
