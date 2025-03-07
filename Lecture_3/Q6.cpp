#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    
    // Push operation
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack\n";
    }
    
    // Pop operation
    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return -1; // Assuming -1 as error value
        }
        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }
    
    // Peek operation
    int peek() {
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return -1; // Assuming -1 as error value
        }
        return top->data;
    }
    
    // IsEmpty operation
    bool isEmpty() {
        return (top == nullptr);
    }
    
    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Main function to test the stack
int main() {
    Stack stack;
    
    // Test operations
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element: " << stack.peek() << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Top element: " << stack.peek() << endl;
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}