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

class Queue {
private:
    Node* front;    // Pointer to front of queue
    Node* rear;     // Pointer to rear of queue
    int size;       // Current number of elements

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // PSEUDO-CODE: ENQUEUE OPERATION
    // BEGIN
    //   CREATE newNode with value
    //   IF queue is empty THEN
    //     SET front = newNode
    //     SET rear = newNode
    //   ELSE
    //     SET rear.next = newNode
    //     SET rear = newNode
    //   END IF
    //   INCREMENT size
    // END
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // PSEUDO-CODE: DEQUEUE OPERATION
    // BEGIN
    //   IF queue is empty THEN
    //     PRINT "Queue Underflow"
    //     RETURN -1
    //   END IF
    //   SET temp = front
    //   SET value = temp.data
    //   SET front = front.next
    //   IF front is null THEN
    //     SET rear = null
    //   END IF
    //   DELETE temp
    //   DECREMENT size
    //   RETURN value
    // END
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    // PSEUDO-CODE: PEEK OPERATION
    // BEGIN
    //   IF queue is empty THEN
    //     PRINT "Queue is empty"
    //     RETURN -1
    //   END IF
    //   RETURN front.data
    // END
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // PSEUDO-CODE: IS EMPTY OPERATION
    // BEGIN
    //   RETURN (size == 0)
    // END
    bool isEmpty() {
        return (size == 0);
    }

    // PSEUDO-CODE: GET SIZE OPERATION
    // BEGIN
    //   RETURN size
    // END
    int getSize() {
        return size;
    }
};

// Main function to test the queue
int main() {
    Queue q;
    
    // Test operations
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    
    cout << "Front element: " << q.peek() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "New front: " << q.peek() << endl;
    cout << "Size: " << q.getSize() << endl;
    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}