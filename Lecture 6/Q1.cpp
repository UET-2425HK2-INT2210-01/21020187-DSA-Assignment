#include <iostream>
using namespace std;

// Define a node in the binary tree
struct TreeNode {
    int value;               // Value of the node
    TreeNode* left;          // Pointer to the left child
    TreeNode* right;         // Pointer to the right child

    TreeNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class that defines the binary search tree
class BinaryTree {
public:
    TreeNode* root = nullptr;  // Pointer to the root node of the tree

    // Function to insert a new value into the tree
    void insert(TreeNode*& currentNode, int newValue) {
        if (currentNode == nullptr) {
            currentNode = new TreeNode(newValue);  // Create a new node if current is null
            return;
        }

        if (newValue < currentNode->value) {
            insert(currentNode->left, newValue);   // Recur on left subtree if value is smaller
        } else if (newValue > currentNode->value) {
            insert(currentNode->right, newValue);  // Recur on right subtree if value is larger
        }
        // If value is equal, do nothing (duplicates not allowed)
    }

    // Function to find the node with the minimum value in a subtree
    TreeNode* findMin(TreeNode* currentNode) {
        while (currentNode && currentNode->left != nullptr) {
            currentNode = currentNode->left;  // Keep going left until no more left child
        }
        return currentNode;
    }

    // Function to remove a node with a specific value from the tree
    void remove(TreeNode*& currentNode, int deleteValue) {
        if (currentNode == nullptr) return;  // Base case: node is null

        if (deleteValue < currentNode->value) {
            remove(currentNode->left, deleteValue);   // Recur on left subtree
        } else if (deleteValue > currentNode->value) {
            remove(currentNode->right, deleteValue);  // Recur on right subtree
        } else {
            // Node to delete found
            if (currentNode->left == nullptr) {
                // No left child: replace with right child
                TreeNode* temp = currentNode->right;
                delete currentNode;
                currentNode = temp;
            } else if (currentNode->right == nullptr) {
                // No right child: replace with left child
                TreeNode* temp = currentNode->left;
                delete currentNode;
                currentNode = temp;
            } else {
                // Node has two children
                TreeNode* successor = findMin(currentNode->right);  // Find the smallest node in right subtree
                currentNode->value = successor->value;              // Replace current value with successor's value
                remove(currentNode->right, successor->value);       // Delete the successor
            }
        }
    }

    // In-order traversal to print the tree in ascending order
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

    // Insert elements into the tree
    int valuesToAdd[] = {2, 1, 10, 6, 3, 8, 7, 13, 20, 14, 0, 35};
    for (int val : valuesToAdd) {
        tree.insert(tree.root, val);
    }

    // Delete some elements from the tree
    int valuesToDelete[] = {6, 13, 35};
    for (int val : valuesToDelete) {
        tree.remove(tree.root, val);
    }

    // Print the tree using in-order traversal to verify the result
    cout << "Inorder traversal after insertions and deletions: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    return 0;
}
