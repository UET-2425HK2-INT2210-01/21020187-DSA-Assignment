#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of queue

class Queue {
private:
    int arr[MAX_SIZE];    // Array to store queue elements
    int front;           // Index of front element
    int rear;            // Index of last element
    int size;            // Current number of elements

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // PSEUDO-CODE: ENQUEUE OPERATION
    // BEGIN
    //   IF queue is full THEN
    //     PRINT "Queue Overflow"
    //     RETURN false
    //   END IF
    //   INCREMENT rear
    //   SET arr[rear] = value
    //   INCREMENT size
    //   RETURN true
    // END
    bool enqueue(int value) {
        if (size >= MAX_SIZE) {
            cout << "Queue Overflow" << endl;
            return false;
        }
        rear++;
        arr[rear] = value;
        size++;
        return true;
    }

    // PSEUDO-CODE: DEQUEUE OPERATION
    // BEGIN
    //   IF queue is empty THEN
    //     PRINT "Queue Underflow"
    //     RETURN -1
    //   END IF
    //   SET temp = arr[front]
    //   INCREMENT front
    //   DECREMENT size
    //   RETURN temp
    // END
    int dequeue() {
        if (size <= 0) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int temp = arr[front];
        front++;
        size--;
        return temp;
    }

    // PSEUDO-CODE: PEEK OPERATION
    // BEGIN
    //   IF queue is empty THEN
    //     PRINT "Queue is empty"
    //     RETURN -1
    //   END IF
    //   RETURN arr[front]
    // END
    int peek() {
        if (size <= 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
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
    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}