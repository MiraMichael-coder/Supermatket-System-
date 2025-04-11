#ifndef LINKEDLISTTEMPLATE_H
#define LINKEDLISTTEMPLATE_H

#include <string>
#include <iostream>

template<class T>
class linkedlist {
public:
    class ListNode {
    public:
        T info;
        ListNode* next;
        ListNode(T value) : info(value), next(nullptr) {}
    };

    ListNode* head;
    ListNode* tail;

    linkedlist() : head(nullptr), tail(nullptr) {}
    ~linkedlist() {
        ListNode* tmp = head;
        while (head != nullptr) {
            head = head->next;
            delete tmp;
            tmp = head;
        }
    }

    void addtoTail(T value) {
        ListNode* newnode = new ListNode(value);
        if (head == nullptr) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void removefromTail() {
        if (head == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        ListNode* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    void displaydetails() const {
        ListNode* current = head;
        while (current != nullptr) {
            std::cout << current->info.getDetails() << std::endl;
            current = current->next;
        }
        std::cout << std::endl;
    }

    T* search( const std::string& name) const {
        ListNode* current = head;
        while (current != nullptr) {
            if (current->info.getname() == name) {
                return &(current->info);
            }
            current = current->next;
        }
        return nullptr; // Returns a default-constructed object if not found
    }

    void removeByValue(T value) {
        if (head == nullptr) {
            return;
        }
        if (head->info.getname() == value.getname()) {
            ListNode* tmp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete tmp;
            return;
        }
        ListNode* current = head;
        ListNode* prev = nullptr;
        while (current != nullptr && current->info.getname() != value.getname()) {
            prev = current;
            current = current->next;
        }
        if (current != nullptr) {
            prev->next = current->next;
            if (current == tail) {
                tail = prev;
            }
            delete current;
        }
    }

    ListNode* getHead() const {
        return head;
    }
ListNode* mergeSort(ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
        return node; // Base case: List with 0 or 1 element is already sorted
    }

    // Split the list into two halves
    ListNode* middle = getMiddle(node);
    ListNode* nextOfMiddle = middle->next;
    middle->next = nullptr; // Split the list

    // Recursively sort each half
    ListNode* left = mergeSort(node);
    ListNode* right = mergeSort(nextOfMiddle);

    // Merge the two sorted halves
    return merge(left, right);
}

ListNode* getMiddle(ListNode* node) {
    if (node == nullptr) return nullptr;

    ListNode* slow = node;
    ListNode* fast = node->next;

    // Use the slow and fast pointer technique to find the middle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* left, ListNode* right) 
{
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    ListNode* result;

    // Compare demand counts and merge accordingly
    if (left->info.getDemandCount() >= right->info.getDemandCount()) {
        result = left;
        result->next = merge(left->next, right);
    } else { //left<=
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}


};

#endif // LINKEDLISTTEMPLATE_H
