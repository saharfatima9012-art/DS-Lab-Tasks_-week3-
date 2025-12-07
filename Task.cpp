#include <iostream>
using namespace std;

// Implement a class to wrap dynamic array operations and manage memory
class ArrayWrapper {
private:
    int* data;  // Raw pointer to the dynamic array.
    int size;   // Current size of the array.

public:
    // Constructor: Takes size 'n', allocates memory, and initializes elements.
    // Dynamic Allocation: Use 'new int[n]' to reserve memory on the heap.
    ArrayWrapper(int n) : size(n) {
        data = new int[size];
        cout << "Dynamic ArrayWrapper created successfully with size " << size << "." << endl;

        // Initialize values
        for (int i = 0; i < size; ++i) {
            data[i] = i * 10 + 5;
        }
    }

    // Destructor (~ArrayWrapper): CRITICAL for cleaning up dynamically allocated memory.
    ~ArrayWrapper() {
        // Memory Management: Use 'delete[]' to free the entire array block.
        delete[] data;
        data = nullptr; // Setting pointer to nullptr after delete prevents DANGLING POINTERS.
        cout << "ArrayWrapper memory freed safely. (Destructor called)" << endl;
    }

    // Method to read an element by index (O(1) access) const
    int getElement(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        return -1; // Error value
    }

    // Method to print the array.
    void print() const {
        cout << "Wrapper Array: [ ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << (i == size - 1 ? "" : ", ");
        }
        cout << " ]" << endl;
    }
};

int main() {
    cout << "--- Task 1 Demonstration ---" << endl;
    ArrayWrapper wrapper(4);
    wrapper.print();
    cout << "Element at index 2: " << wrapper.getElement(2) << endl;
    // Destructor will be called automatically when 'wrapper' goes out of scope.
    return 0;
}