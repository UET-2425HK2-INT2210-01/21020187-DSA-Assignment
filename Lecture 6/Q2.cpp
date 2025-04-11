#include <iostream>
using namespace std;

// Structure representing a node in the binary search tree
struct TreeNode {
    int value;               // Data stored in the node
    TreeNode* left;          // Pointer to the left child node
    TreeNode* right;         // Pointer to the right child node

    // Constructor to initialize the node with a value
    TreeNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class that implements the Binary Search Tree (BST)
class BinaryTree {
public:
    TreeNode* root = nullptr;  // Pointer to the root node of the BST

    // Function to insert a new value into the BST
    void insert(TreeNode*& currentNode, int newValue) {
        // If the current position is null, create a new node here
        if (currentNode == nullptr) {
            currentNode = new TreeNode(newValue);
            return;
        }

        // Recursively insert to the left if the new value is smaller
        if (newValue < currentNode->value) {
            insert(currentNode->left, newValue);
        }
        // Recursively insert to the right if the new value is greater
        else if (newValue > currentNode->value) {
            insert(currentNode->right, newValue);
        }
        // Duplicate values are not inserted in the tree
    }

    // Helper function to find the node with the minimum value in a subtree
    TreeNode* findMin(TreeNode* currentNode) {
        // Traverse left until the leftmost node is reached
        while (currentNode && currentNode->left != nullptr) {
            currentNode = currentNode->left;
        }
        return currentNode;
    }

    // Function to delete a node with a given value from the BST
    void remove(TreeNode*& currentNode, int deleteValue) {
        if (currentNode == nullptr) return;  // Base case: node not found

        // Recursively search for the node to delete
        if (deleteValue < currentNode->value) {
            remove(currentNode->left, deleteValue);
        } else if (deleteValue > currentNode->value) {
            remove(currentNode->right, deleteValue);
        } else {
            // Node found - now handle the 3 possible deletion cases

            // Case 1: Node has no left child
            if (currentNode->left == nullptr) {
                TreeNode* temp = currentNode->right;
                delete currentNode;
                currentNode = temp;
            }
            // Case 2: Node has no right child
            else if (currentNode->right == nullptr) {
                TreeNode* temp = currentNode->left;
                delete currentNode;
                currentNode = temp;
            }
            // Case 3: Node has two children
            else {
                TreeNode* successor = findMin(currentNode->right);  // Get the inorder successor (smallest in right subtree)
                currentNode->value = successor->value;              // Copy its value to current node
                remove(currentNode->right, successor->value);       // Delete the inorder successor
            }
        }
    }

    // In-order traversal: prints the tree in ascending order
    void inorderTraversal(TreeNode* currentNode) {
        if (currentNode != nullptr) {
            inorderTraversal(currentNode->left);
            cout << currentNode->value << " ";
            inorderTraversal(currentNode->right);
        }
    }
};

int main() {
    BinaryTree tree;

    // Insert multiple values into the BST
    int valuesToAdd[] = {2, 1, 10, 6, 3, 8, 7, 13, 20, 14, 0, 35};
    for (int val : valuesToAdd) {
        tree.insert(tree.root, val);
    }

    // Remove specific values from the BST
    int valuesToDelete[] = {6, 13, 35};
    for (int val : valuesToDelete) {
        tree.remove(tree.root, val);
    }

    // Output the result of in-order traversal after insertions and deletions
    cout << "Inorder traversal after insertions and deletions: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    return 0;
}
