#include "Product.h"
#include<iostream>
#include<string>
#include <iomanip> 
using namespace std;
Product::Product(string pname, string pcategory, double pprice, int pstock)
    : name(pname), category(pcategory), price(pprice), stock(pstock) {}
Product::Product(string pname, string pcategory, double pprice, int pstock,int d)
    : name(pname), category(pcategory), price(pprice), stock(pstock),demandCount(d) {}
void Product::updateStock(int quantity) {
    stock = quantity;
    cout << "Stock updated to: " << stock << endl;
}

void Product::updatePrice(double newPrice) {
    price = newPrice;
    cout << "Price updated to: $" << price << endl;
}

string Product::getDetails() const{
    stringstream ss;
        ss << fixed << setprecision(2);  // Fixed-point notation, 2 decimal places
        ss << "Name: " << name << "\nCategory: " << category << "\nPrice: $" 
           << price << "\nStock: " << stock;
        return ss.str();
}
void Product::incrementDemandCount() {
    demandCount++;
}
