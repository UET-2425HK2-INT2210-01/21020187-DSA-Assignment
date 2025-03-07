#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    LinkedList() : head(nullptr) {}

    void insert(int p, int x) {
        Node* newNode = new Node(x);
        if (p == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < p - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void remove(int p) {
        if (head == nullptr) return;
        if (p == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < p - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        if (temp->next == nullptr) return;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
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
    LinkedList list;
    string operation;

    for (int i = 0; i < n; i++) {
        cin >> operation;
        if (operation == "insert") {
            int p, x;
            cin >> p >> x;
            list.insert(p, x);
        } else if (operation == "delete") {
            int p;
            cin >> p;
            list.remove(p);
        }
    }

    list.print();

    return 0;
}
