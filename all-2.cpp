#include <stdexcept> // For std::underflow_error
#include <iostream>  // For std::cout and std::endl

// ListNode class template
template <typename T>
class ListNode {
public:
    T value;                // Value of the node
    ListNode* nextNode;     // Pointer to the next node

    // Constructor to initialize the node
    ListNode(T value, ListNode* nextNode = nullptr) {
        this->value = value;
        this->nextNode = nextNode;
    }
};

// CustomStack class template
template <typename T>
class CustomStack {
private:
    ListNode<T>* stackTop;  // Pointer to the top of the stack
    int elementCount;       // Number of elements in the stack

public:
    // Constructor to initialize an empty stack
    CustomStack() {
        stackTop = nullptr;
        elementCount = 0;
    }

    // Add an item to the stack
    void add(T item) {
        stackTop = new ListNode<T>(item, stackTop);
        elementCount++;
    }

    // Remove and return the item at the top of the stack
    T remove() {
        if (isStackEmpty()) {
            throw std::underflow_error("Stack is empty - no elements to remove");
        }
        T itemValue = stackTop->value;
        ListNode<T>* oldTop = stackTop;
        stackTop = stackTop->nextNode;
        delete oldTop;
        elementCount--;
        return itemValue;
    }

    // Check if the stack is empty
    bool isStackEmpty() const {
        return stackTop == nullptr;
    }

    // Return the total number of items in the stack
    int getElementCount() const {
        return elementCount;
    }
};

// Main function to test the CustomStack class
int main() {
    CustomStack<int> myStack;

    // Add elements to the stack
    myStack.add(10);
    myStack.add(20);
    myStack.add(30);

    // Display the number of elements in the stack
    std::cout << "Number of elements: " << myStack.getElementCount() << std::endl;

    // Check if the stack is empty
    std::cout << "Is stack empty? " << (myStack.isStackEmpty() ? "Yes" : "No") << std::endl;

    // Remove elements from the stack
    std::cout << "Removed: " << myStack.remove() << std::endl;
    std::cout << "Removed: " << myStack.remove() << std::endl;

    // Display the number of elements in the stack after removal
    std::cout << "Number of elements: " << myStack.getElementCount() << std::endl;

    // Check if the stack is empty
    std::cout << "Is stack empty? " << (myStack.isStackEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
