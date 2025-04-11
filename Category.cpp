#include "Category.h"

// Constructor
Category::Category() : root(nullptr) {}
string Category::getname() const {
    return categoryName;
}

// Setter for categoryName
void Category::setCategoryName(const string& name) {
    categoryName = name;
}
// Helper function to insert a product in the BST
void Category::insert(Node*& node, Product product) {
    if (!node) {
        node = new Node(product);
    } else if (product.getname() < node->product.getname()) {
        insert(node->left, product);
    } else {
        insert(node->right, product);
    }
}

// Public insert method
void Category::insert(Product product) {
    insert(root, product);
    //cout << "Product inserted in BST.\n";
}

// Helper function to search for a product by name
Node* Category::search(Node* node, string name) {
    if (node==nullptr||node->product.getname() == name)
    {
        return node;
    }
    if (name < node->product.getname()) 
    {
        return search(node->left, name);
    }
    else 
       return search(node->right, name);
}

// Public search method
Product Category::search(string name) {
    Node* result = search(root, name);
    if (result) {
        return result->product;
    } else {
        cout << "Product not found.\n";
        return Product();
    }
}

// Helper function for in-order traversal
void Category::inOrderTraversal(Node* node) {
    if (!node) {
        return;
    }
    inOrderTraversal(node->left);
    cout << node->product.getDetails() << endl;
    inOrderTraversal(node->right);
}

// Public in-order traversal
void Category::inOrderTraversal() {
    inOrderTraversal(root);
}

void Category::deleteNode(string name) 
{
    root = deleteNodeHelper(root, name);
}
Node* Category::deleteNodeHelper(Node* root, string name) {
    if (root == nullptr) {
        return root; // Node not found
    }

    // Traverse the tree
    if (name < root->product.getname()) {
        root->left = deleteNodeHelper(root->left, name);
    } else if (name > root->product.getname()) {
        root->right = deleteNodeHelper(root->right, name);
    } else {
        // Node found: handle three cases

        // Case 1: Node has no children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: Node has one child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has two children
        Node* temp = findMin(root->right); // In-order successor
        root->product = temp->product; // Copy the in-order successor's content
        root->right = deleteNodeHelper(root->right, temp->product.getname()); // Delete the successor
    }
    return root;
}
 
// Helper function to find the minimum value node in the BST (leftmost node)
Node* Category::findMin(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}
