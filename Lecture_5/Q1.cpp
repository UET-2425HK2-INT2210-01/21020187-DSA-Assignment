#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* first_child;
    Node* next_sibling;
    Node(int val) : data(val), first_child(nullptr), next_sibling(nullptr) {}
};

class Tree {
private:
    Node* nodes[100] = {nullptr};
    bool is_child[100] = {false};
    int n, m, root;

public:
    Tree(int nodes_count, int edges_count) : n(nodes_count), m(edges_count) {}

    void addEdge(int u, int v) {
        if (!nodes[u]) nodes[u] = new Node(u);
        if (!nodes[v]) nodes[v] = new Node(v);

        if (!nodes[u]->first_child) {
            nodes[u]->first_child = nodes[v];
        } else {
            Node* temp = nodes[u]->first_child;
            while (temp->next_sibling) temp = temp->next_sibling;
            temp->next_sibling = nodes[v];
        }
        is_child[v] = true;
    }

    void findRoot() {
        for (int i = 1; i <= n; i++) {
            if (nodes[i] && !is_child[i]) {
                root = i;
                break;
            }
        }
    }

    int height(Node* node) {
        if (!node) return 0;
        int max_child_height = 0;
        for (Node* child = node->first_child; child; child = child->next_sibling) {
            max_child_height = max(max_child_height, height(child));
        }
        return 1 + max_child_height;
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        for (Node* child = node->first_child; child; child = child->next_sibling) {
            preorder(child);
        }
    }

    void postorder(Node* node) {
        if (!node) return;
        for (Node* child = node->first_child; child; child = child->next_sibling) {
            postorder(child);
        }
        cout << node->data << " ";
    }

    bool isBinaryTree() {
        for (int i = 1; i <= n; i++) {
            if (nodes[i]) {
                int count = 0;
                for (Node* child = nodes[i]->first_child; child; child = child->next_sibling) {
                    count++;
                    if (count > 2) return false;
                }
            }
        }
        return true;
    }

    void inorder(Node* node) {
        if (!node) return;
        if (node->first_child) {
            inorder(node->first_child);
            cout << node->data << " ";
            if (node->first_child->next_sibling) inorder(node->first_child->next_sibling);
        } else {
            cout << node->data << " ";
        }
    }

    void process() {
        findRoot();
        cout << height(nodes[root]) - 1 << endl;
        preorder(nodes[root]); cout << endl;
        postorder(nodes[root]); cout << endl;
        if (isBinaryTree()) {
            inorder(nodes[root]); cout << endl;
        } else {
            cout << "NOT BINARY TREE" << endl;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Tree tree(n, m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }
    tree.process();
    return 0;
}
