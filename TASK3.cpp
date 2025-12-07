#include <iostream>
using namespace std;

// 1. Node structure (Encapsulates data and pointer)
class SNode {
public:
    int data;     // Data stored in the node
    SNode* next;  // Pointer to the next node
    
    // Constructor: Initialize node with value and null next pointer
    SNode(int val) : data(val), next(nullptr) {}
};

// 2. StackList Class: Manages the collection of SNodes
class StackList {
private:
    SNode* head;  // Head pointer serves as the 'top' of the stack

public:
    // Constructor: Initialize empty stack
    StackList() : head(nullptr) {}

    // Destructor: CRITICAL for linked lists memory management
    ~StackList() {
        SNode* current = head;
        // Loop through all nodes and delete them one by one
        while (current != nullptr) {
            SNode* next_node = current->next;  // Store next node
            delete current;  // Delete current node
            current = next_node;  // Move to next node
        }
    }

    // Method 1: Push (Adding element - always at the head/top)
    void push(int val) {
        // O(1) Push: Create new node and make it the new head
        SNode* newNode = new SNode(val);  // Create new node
        newNode->next = head;  // New node points to current head
        head = newNode;  // Update head to new node
        cout << "Pushed: " << val << endl;
    }

    // Method 2: Pop (Removing the top element - always at the head)
    int pop() {
        // Check for Underflow (Stack is empty)
        if (head == nullptr) {
            cout << "\nERROR: STACK UNDERFLOW! (Stack is empty)." << endl;
            return -1;
        }
        // O(1) Pop: Remove node at head
        SNode* temp = head;  // Store current head
        int val = temp->data;  // Get data from head
        head = head->next;  // Move head to the next node
        delete temp;  // Free the memory of the removed node
        return val;  // Return popped value
    }

    // Helper to print the stack state
    void print() const {
        SNode* current = head;
        cout << "StackList (TOP->BOT): [ ";
        // Traverse the list and print all elements
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << ", ";  // Add comma if not last element
            }
            current = current->next;
        }
        cout << " ]" << endl;
    }
};

int main() {
    cout << "--- Task 3 Demonstration ---" << endl;
    StackList stack;
    
    // Push elements onto the stack
    stack.push(100);
    stack.push(200);
    stack.push(300);
    stack.print();  // Print current stack
    
    // Pop an element and display
    cout << "Popped value: " << stack.pop() << endl;
    
    // Push another element
    stack.push(400);
    stack.print();  // Print final stack state
    
    // Destructor handles cleanup automatically
    return 0;
}