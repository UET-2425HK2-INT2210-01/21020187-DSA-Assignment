#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;

    Node(char x) {
        data = x;
        next = nullptr;
    }
};

class Stack {
    Node* head = nullptr;

public:
    // Destructor to avoid memory leaks
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Push an element onto the stack
    void push(char x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    // Pop an element from the stack
    char pop() {
        if (isEmpty()) return '\0';
        Node* temp = head;
        char topData = temp->data;
        head = head->next;
        delete temp;
        return topData;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return head == nullptr;
    }
};

bool isValid(const string& s) {
    Stack st;
    for (char x : s) {
        if (x == '(' || x == '[' || x == '{') {
            st.push(x);
        } else {
            if (st.isEmpty()) return false;
            char top = st.pop();
            if ((x == ')' && top != '(') || (x == ']' && top != '[') || (x == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.isEmpty();
}

int main() {
    string str;
    cin >> str;

    if (isValid(str)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
}
