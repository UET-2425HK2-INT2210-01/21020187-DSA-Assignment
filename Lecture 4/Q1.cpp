#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* nextNode;
};

// Function to create a new node with the given value
Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->value = data;
    newNode->nextNode = NULL;
    return newNode;
}

class LinkedList {
    Node* firstNode = NULL;
public:
    // Add an element at the end of the linked list
    void insert()
    {
        int data;
        cin >> data;
        Node* newNode = createNode(data);
        if (isEmpty())
        {
            newNode->nextNode = firstNode;
            firstNode = newNode;
            return;
        }
        else {
            Node* temp = firstNode;
            while (temp->nextNode != NULL)
            {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
        }
    }

    // Check if the linked list is empty
    bool isEmpty()
    {
        return firstNode == NULL;
    }

    // Search for an element in the linked list and print its index
    void find()
    {
        int data;
        cin >> data;
        Node* temp = firstNode;
        int index = 0;
        while (temp->value != data)
        {
            index++;
            temp = temp->nextNode;
        }
        cout << index << endl;
    }

    // Print the linked list in reverse order
    void printReverse()
    {
        Node* temp = firstNode;
        int arr[100]; // Temporary array to store values
        int count = 0;
        while (temp != NULL)
        {
            arr[count] = temp->value;
            temp = temp->nextNode;
            count++;
        }

        // Print values in reverse order
        for (int i = count - 1; i >= 0; i--)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};

int main()
{
    int numOperations;
    cin >> numOperations;
    LinkedList list;
    for (int i = 0; i < numOperations; i++)
    {
        string command;
        cin >> command;
        if (command == "append")
        {
            list.insert();
        }
        else if (command == "search")
        {
            list.find();
        }
        else if (command == "reverse")
        {
            list.printReverse();
        }
    }

    return 0;
}
