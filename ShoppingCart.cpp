#include "ShoppingCart.h"
using namespace std;

#include <stack>
#include <string>
#include "Product.h"
#include "CartItem.h"

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
    // The linkedlist constructor initializes head and tail to nullptr
}

ShoppingCart::~ShoppingCart() {
    // The linkedlist destructor will handle memory cleanup
}

void ShoppingCart::addItem(Product &product, int quantity) {
    if (quantity <= 0) {
        cout << "Quantity must be greater than 0." << endl;
        return;
    }

    // Create a new CartItem
    CartItem newItem(product, quantity);

    // Add to the linked list
    cartList.addtoTail(newItem);
    cout << "Added item: \n" << product.getDetails()
              << " with Quantity: " << quantity << endl;
    product.incrementDemandCount();

    // Update action history
    actionHistory.push("add");
}

void ShoppingCart::removeItem(const string &productName) {
    if (!cartList.head) {
        cout << "The Cart is empty." << endl;
        return;
    }

    // Search for the item
    CartItem *foundItem = cartList.search(productName);
    if (foundItem->getproduct().getname()=="") { // Assuming getname() returns empty string if not found
        cout << "Product not found in the cart: " << productName << endl;
        return;
    }

    // Push the removed item to history for undo
    removeHistory.push(*foundItem);

    // Remove the item from the linked list
    cartList.removeByValue(*foundItem);
    cout << "Removed item: " << productName << endl;

    // Update action history
    actionHistory.push("remove");
}

void ShoppingCart::updateItemQuantity(const string &productName)
{
    int newQuantity;
    cout << "Enter new quantity for product " << productName << ": ";
    cin >> newQuantity;

    if (newQuantity < 0) {
        cout << "Quantity can't be negative." << endl;
        return;
    }

    if (!cartList.head) {
        cout << "The cart is empty." << endl;
        return;
    }
            CartItem *found=cartList.search(productName);
        if(found->getproduct().getname()!=""){
            int stock = found->getproduct().getstock();
            if (newQuantity > stock)
                {
                cout << "Error: Quantity exceeds stock availability. Available stock: "
                          << stock << endl;
                return;
               }

            // Push the previous quantity to history for undo
            quantityHistory.push(found->getquantity());
            updateHistory.push(productName);

            // Update the quantity
            found->updateQuantity(newQuantity);
            cout << "Quantity updated successfully." << endl;

            // Update action history
            actionHistory.push("update");
            return;
    }

    cout << "Product not found in the cart: " << productName << endl;
}

void ShoppingCart::undoLastAction(SystemLog& log) {
    if (actionHistory.empty()) {
        cout << "No action to undo..." << endl;
        return;
    }

    string action = actionHistory.top();
    actionHistory.pop();
    cout << "Undoing action: " << action << endl;

    if (action == "add") {
        // Remove the last added item
        cartList.removefromTail();
        cout << "Last added item has been removed." << endl;
    }
    else if (action == "remove") {
        if (removeHistory.empty()) {
            cout << "No removed item to restore." << endl;
            return;
        }

        // Restore the last removed item
        CartItem lastRemoved = removeHistory.top();
        removeHistory.pop();
        cartList.addtoTail(lastRemoved);
        cout << "Restored removed item: " << lastRemoved.getproduct().getname() <<endl;
    }
    else if (action == "update") {
        if (quantityHistory.empty() || updateHistory.empty()) {
            cout << "No update to undo..." << endl;
            return;
        }

        string lastUpdatedProductName = updateHistory.top();
        updateHistory.pop();
        int previousQuantity = quantityHistory.top();
        quantityHistory.pop();

        // Traverse to find the item and revert the quantity
          CartItem *found=cartList.search(lastUpdatedProductName);
        if(found->getproduct().getname()!=""&& found){
                found->updateQuantity(previousQuantity);
                cout << "Reverted quantity for product: " << lastUpdatedProductName << endl;
            }

        }
    }
double ShoppingCart::calculateTotal() {
    double total = 0.0;

    if (!cartList.head) {
        cout << "The cart is empty." << endl;
        return total;
    }

    typename linkedlist<CartItem>::ListNode* current = cartList.head;
    while (current) {
        total += current->info.getTotalPrice();
        current = current->next;
    }

    return total;
}
void ShoppingCart::clearCart() {
    cartList.~linkedlist(); // Explicitly call the destructor to clear the list
    new(&cartList) linkedlist<CartItem>(); // Reinitialize the linked list
    cout << "Cart cleared." << endl;
}
void ShoppingCart::getDetails() {
    if (!cartList.head) {
        cout << "The cart is empty." << endl;
        return;
    }
    cartList.displaydetails();
}
ShoppingCart::ShoppingCart(const ShoppingCart& other) {
    typename linkedlist<CartItem>::ListNode* current = other.cartList.head;
    while (current != nullptr) {
        cartList.addtoTail(current->info); // Deep copy CartItems
        current = current->next;
    }

    // Copy stacks
    actionHistory = other.actionHistory;
    removeHistory = other.removeHistory;
    quantityHistory = other.quantityHistory;
    updateHistory = other.updateHistory;
}

// Assignment Operator
ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other) {
    if (this != &other) {
        // Clear current cart
        clearCart();

        // Deep copy cart items
        typename linkedlist<CartItem>::ListNode* current = other.cartList.head;
        while (current != nullptr) {
            cartList.addtoTail(current->info);
            current = current->next;
        }

        // Copy stacks
        actionHistory = other.actionHistory;
        removeHistory = other.removeHistory;
        quantityHistory = other.quantityHistory;
        updateHistory = other.updateHistory;
    }
    return *this;
}


