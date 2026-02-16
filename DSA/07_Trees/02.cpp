#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// void inorder(Node* root){
//     if(root== NULL) return;

//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);

// }

// void preOrder(Node* root){
//     if(root== NULL) return;

//     cout << root->data << " ";
//     preOrder(root->left);
//     preOrder(root->right);

// }

// void postOrder(Node* root){
//     if(root== NULL) return;

//     postOrder(root->left);
//     postOrder(root->right);
//     cout << root->data << " ";

// }

int countNodes(Node* root){
    //base case 
    if(root==NULL) return 0;

    //count nodes in lst
    int x = countNodes(root->left);

    //count nodes in rst
    int y = countNodes(root->right);

    return x + y + 1;

}

int countLeaf(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL) return 1;
    int x = countLeaf(root->left);
    int y = countLeaf(root->right);

    return x + y;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);


        cout << countLeaf(root) << endl;



}





