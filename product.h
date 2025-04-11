#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    string category;
    double price;
    int stock;
    bool seasonal;
    int demandCount;
public:
    
    Product() : name(""), category(""), price(0.0), stock(0) ,seasonal(false) {}
    Product(string pname, string pcategory, double pprice, int pstock);
    Product(string pname, string pcategory, double pprice, int pstock,int d);
    void updateStock(int quantity);
    void updatePrice(double newPrice);
    string getDetails()const;
     void incrementDemandCount();  // Increases demand count by 
    string getname(){return name;}
    string getCategory(){return category;}
    int getstock(){return stock;}
    double getPrice(){return price;}
    Product& operator=(const Product& other) {
        if (this == &other) // Self-assignment check
            return *this;

        // Assign member variables
        name = other.name;
        category = other.category;
        price = other.price;
        stock = other.stock;

        return *this;
    }
    
    bool getSeasonal(){return seasonal;}
    void setPrice(double p){price=p;}
    void setStock(int s){stock=s;}
    void setcategory(string c){category=c;}
    void setseasonal(){seasonal=true;}
    int getDemandCount() const { return demandCount; }

    
};
#endif // PRODUCT_H
