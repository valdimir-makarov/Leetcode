#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node *CreateNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct Node *root = CreateNode(3);

    root->left = CreateNode(2);
    root->right = CreateNode(5);
    root->left->left = CreateNode(11);
    root->left->right = CreateNode(23);
    root->right->left = CreateNode(6);
    root->right->right = CreateNode(7);

    // Print values of nodes
    cout << "Root Node: " << root->data << endl;
    cout << "Left Child of Root: " << root->left->data << endl;
    cout << "Right Child of Root: " << root->right->data << endl;
    cout << "Left Child of Left Subtree: " << root->left->left->data << endl;
    cout << "Right Child of Left Subtree: " << root->left->right->data << endl;
    cout << "Left Child of Right Subtree: " << root->right->left->data << endl;
    cout << "Right Child of Right Subtree: " << root->right->right->data << endl;

    return 0;
}
