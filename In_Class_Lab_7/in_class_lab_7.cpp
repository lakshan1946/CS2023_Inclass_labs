#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL)
    return;

  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  // If the tree is empty, return a new node
  if (root == NULL) {
    struct node* newNode = new node;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    root = newNode;
    return root;
  }
  if (key < root->key)
    root->left = insertNode(root->left, key);
  else
    root->right = insertNode(root->right, key);

  // Return the node pointer
  return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Base case
  if (root == NULL)
    return root;

  // If the key to be deleted is less than the root's key, it can be located in the left subtree.
  if (key < root->key)
    root->left = deleteNode(root->left, key);

  // If the key to be deleted is higher than the root's key, it can be located in the right subtree.
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // node with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete(root);
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      delete(root);
      return temp;
    }
    struct node *temp = root->right;
    while (temp->left != NULL)
      temp = temp->left;
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }

  // Return the node pointer
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
