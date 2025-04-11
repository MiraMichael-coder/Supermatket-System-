#ifndef CATEGORY_H
#define CATEGORY_H

#include "Product.h"
#include <iostream>
#include <string>
using namespace std;
  struct Node {
        Product product; // The product stored in this node
        Node* left;      // Pointer to the left child
        Node* right;     // Pointer to the right child

        // Node constructor
        Node(Product p) : product(p), left(nullptr), right(nullptr) {}
    };

class Category {
private:
    // Node structure for the BST
  
    Node* root; // Root of the BST

    // Private helper functions
    void insert(Node*& node, Product product);
    Node* search(Node* node, string name);
    void inOrderTraversal(Node* node);
    Node* deleteNodeHelper(Node* root, string name);
    Node* findMin(Node* node);

public:
    // Constructor
    Category();

    // Public methods
    void insert(Product product);
    Product search(string name);
    void inOrderTraversal();
    void deleteNode(string name);

    // Additional helper methods
    string getname() const;
    void setCategoryName(const string& name);

private:
    string categoryName; // Name of the category
};

#endif // CATEGORY_H
