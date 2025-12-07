#include <iostream>
using namespace std;

// Define the maximum size of the Array-based stack (fixed size)
#define MAX_SIZE 5

// STACK CLASS: Manages a fixed-size integer array
class StackArray {
private:
    int data[MAX_SIZE];  // The fixed size array storage
    int top;             // Index of the top element (LIFO tracker)

public:
    // Constructor: Initializes the stack as empty
    StackArray() : top(-1) {
        cout << "StackArray initialized (MAX size: " << MAX_SIZE << ")" << endl;
    }

    // Method 1: Push (Adding an element to the top)
    void push(int val) {
        // Check for Overflow (The array is full)
        if (top == MAX_SIZE - 1) {
            cout << "\nERROR: STACK OVERFLOW! Cannot push " << val << " (Array is full)." << endl;
            return;
        }
        // O(1) Push operation: Increment top, then store value
        data[++top] = val;
        cout << "Pushed: " << val << endl;
    }

    // Method 2: Pop (Removing and returning the top element)
    int pop() {
        // Check for Underflow (The array is empty)
        if (top == -1) {
            cout << "\nERROR: STACK UNDERFLOW! (Stack is empty)." << endl;
            return -1;
        }
        // O(1) Pop operation: Get value, then decrement top (LIFO)
        return data[top--];
    }

    // Method 3: Peek (Viewing the top element without removing it)
    int peek() const {
        if (top == -1) return -1;  // Return -1 if stack is empty
        return data[top];  // Return top element
    }

    // Helper to print the stack state
    void print() const {
        cout << "Stack (TOP->BOTTOM): [ ";
        // Print from top to bottom (LIFO order)
        for (int i = top; i >= 0; --i) {
            cout << data[i] << (i == 0 ? "" : ", ");
        }
        cout << " ]" << endl;
    }
};

// MAIN DEMONSTRATION
int main() {
    cout << "--- TASK 5: STACK ARRAY DEMO ---" << endl;

    StackArray myStack;
    
    // Pushing elements up to the capacity (5 elements)
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.print();  // Print stack after pushing 5 elements

    // Trigger Overflow error (trying to push 6th element)
    myStack.push(60);

    // Peek and Pop operations
    cout << "\nPeek (Top value): " << myStack.peek() << endl;  // Should be 50
    cout << "Popped value: " << myStack.pop() << endl;  // Should be 50
    myStack.print();  // Print stack after pop

    // Empty the stack by popping all elements
    myStack.pop();  // Pop 40
    myStack.pop();  // Pop 30
    myStack.pop();  // Pop 20
    myStack.pop();  // Pop 10

    // Trigger Underflow error (trying to pop from empty stack)
    myStack.pop();

    cout << "\n--- Demo Complete ---" << endl;
    return 0;
}