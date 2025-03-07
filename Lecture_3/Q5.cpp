#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of stack

class Stack {
private:
    int arr[MAX_SIZE];    // Array to store stack elements
    int top;             // Index of top element
    int size;            // Current number of elements

public:
    Stack() {
        top = -1;        // Initialize top as -1 (empty stack)
        size = 0;        // Initialize size as 0
    }

    // PSEUDO-CODE: PUSH OPERATION
    // BEGIN
    //   IF stack is full THEN
    //     PRINT "Stack Overflow"
    //     RETURN false
    //   END IF
    //   INCREMENT top
    //   SET arr[top] = value
    //   INCREMENT size
    //   RETURN true
    // END
    bool push(int value) {
        if (size >= MAX_SIZE) {
            cout << "Stack Overflow" << endl;
            return false;
        }
        top++;
        arr[top] = value;
        size++;
        return true;
    }

    // PSEUDO-CODE: POP OPERATION
    // BEGIN
    //   IF stack is empty THEN
    //     PRINT "Stack Underflow"
    //     RETURN -1
    //   END IF
    //   SET temp = arr[top]
    //   DECREMENT top
    //   DECREMENT size
    //   RETURN temp
    // END
    int pop() {
        if (size <= 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int temp = arr[top];
        top--;
        size--;
        return temp;
    }

    // PSEUDO-CODE: PEEK OPERATION
    // BEGIN
    //   IF stack is empty THEN
    //     PRINT "Stack is empty"
    //     RETURN -1
    //   END IF
    //   RETURN arr[top]
    // END
    int peek() {
        if (size <= 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    // PSEUDO-CODE: IS EMPTY OPERATION
    // BEGIN
    //   RETURN (size == 0)
    // END
    bool isEmpty() {
        return (size == 0);
    }

    // PSEUDO-CODE: IS FULL OPERATION
    // BEGIN
    //   RETURN (size == MAX_SIZE)
    // END
    bool isFull() {
        return (size == MAX_SIZE);
    }
};

// Main function to test the stack
int main() {
    Stack s;
    
    // Test operations
    s.push(1);
    s.push(2);
    s.push(3);
    
    cout << "Top element: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "New top: " << s.peek() << endl;
    cout << "Is empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}