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

int sumOfNodes(Node* root){
    if(root == NULL) return 0;

    int ls = sumOfNodes(root->left);
    int rs = sumOfNodes(root->right);

    return root->data + ls + rs;

}
 
int main()
{
 
}