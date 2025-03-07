#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

struct Stack {
    Node* top;
    Stack() : top(nullptr) {}

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) return; // Stack is empty
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void print() {
        if (top == nullptr) return; // Stack is empty
        Node* temp = top;
        // Reverse print using recursion
        reversePrint(temp);
        cout << endl;
    }

    void reversePrint(Node* node) {
        if (node == nullptr) return;
        reversePrint(node->next);
        cout << node->data << " ";
    }
};

int main() {
    int n;
    cin >> n; // Read the number of operations
    Stack s;
    string operation;
    int x;

    for (int i = 0; i < n; i++) {
        cin >> operation;
        if (operation == "push") {
            cin >> x;
            s.push(x);
        } else if (operation == "pop") {
            s.pop();
        }
    }

    s.print();
    return 0;
}
