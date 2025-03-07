#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

struct Queue {
    Node* head;
    Node* tail;
    Queue() : head(nullptr), tail(nullptr) {}

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (head == nullptr) return; // Queue is empty
        Node* temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n; // Read the number of operations
    Queue q;
    string operation;
    int x;

    for (int i = 0; i < n; i++) {
        cin >> operation;
        if (operation == "enqueue") {
            cin >> x;
            q.enqueue(x);
        } else if (operation == "dequeue") {
            q.dequeue();
        }
    }

    q.print();
    return 0;
}
