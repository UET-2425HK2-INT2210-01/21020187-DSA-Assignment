#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    int priority;
    Node* next;
    Node* prev;
};

// Function to create a new node with given value and priority
Node* createNode(int data, int priorityLevel)
{
    Node* newNode = new Node();
    newNode->value = data;
    newNode->priority = priorityLevel;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

class PriorityQueue {
    Node* front = NULL; // Head of the priority queue
public:
    // Check if the queue is empty
    bool isEmpty()
    {
        return front == NULL;
    }

    // Insert an element based on priority
    void enqueue()
    {
        int data, priorityLevel;
        cin >> data >> priorityLevel;
        Node* newNode = createNode(data, priorityLevel);

        if (isEmpty())
        {
            front = newNode;
            return;
        }

        // Insert at the beginning if the new node has the highest priority
        if (newNode->priority > front->priority)
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
            return;
        }

        Node* temp = front;
        // Traverse the queue to find the correct position
        while (temp->next != NULL && newNode->priority < temp->priority)
        {
            temp = temp->next;
        }

        // Insert at the end
        if (temp->next == NULL)
        {
            temp->next = newNode;
            newNode->prev = temp;
            return;
        }

        // Insert in the middle
        newNode->next = temp->next;
        temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
    }

    // Print all elements in the queue
    void printQueue()
    {
        Node* temp = front;
        while (temp != NULL)
        {
            cout << '(' << temp->value << ", " << temp->priority << "); ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Remove the highest-priority element
    void dequeue()
    {
        if (isEmpty()) return;

        Node* temp = front;
        front = front->next;
        
        if (front != NULL) {
            front->prev = NULL;
        }

        delete temp;
    }
};

int main()
{
    int numOperations;
    cin >> numOperations;
    PriorityQueue pq;
    string command;

    for (int i = 0; i < numOperations; i++)
    {
        cin >> command;
        if (command == "enqueue")
        {
            pq.enqueue();
        }
        else if (command == "dequeue")
        {
            pq.dequeue();
        }
    }

    pq.printQueue();
    return 0;
}
