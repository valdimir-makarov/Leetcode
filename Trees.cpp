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

bool isBalanced(){



    
}

void preOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return; 
    }

   
    cout << root->data << " ";

   
    preOrderTraversal(root->left);

  
    preOrderTraversal(root->right);
}
 void postOrderTraversal(struct Node *root){
      if(root==NULL){
        cout<<root->data<<"";
        return ;
      }
       postOrderTraversal(root->left);
       postOrderTraversal(root->right);


 }




int main() {
    struct Node *root = CreateNode(3);

    root->left = CreateNode(2);
    root->right = CreateNode(5);
    root->left->left = CreateNode(11);
    root->left->right = CreateNode(23);
    root->right->left = CreateNode(6);
    root->right->right = CreateNode(7);

    
    cout << "Root Node: " << root->data << endl;
    cout << "Left Child of Root: " << root->left->data << endl;
    cout << "Right Child of Root: " << root->right->data << endl;
    cout << "Left Child of Left Subtree: " << root->left->left->data << endl;
    cout << "Right Child of Left Subtree: " << root->left->right->data << endl;
    cout << "Left Child of Right Subtree: " << root->right->left->data << endl;
    cout << "Right Child of Right Subtree: " << root->right->right->data << endl;

    cout<<"pre order traversal"<<endl;
    preOrderTraversal(root);

    return 0;
}
