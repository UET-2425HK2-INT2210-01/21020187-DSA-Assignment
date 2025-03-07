#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int count_triplets() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr && temp->next->next != nullptr) {
            if (temp->data + temp->next->data + temp->next->next->data == 0) {
                count++;
            }
            temp = temp->next;
        }
        return count;
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
    cin >> n; // Read the number of elements
    DoublyLinkedList list;
    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        list.insert(x);
    }

    cout << list.count_triplets() << endl;

    return 0;
}
