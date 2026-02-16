#include<iostream>
#include<queue>
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
 
 void levelOrder(Node* root){
    if(root==NULL) return;

    //first create a queue and push root and null
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();

        if(frontNode!= NULL){
            cout << frontNode->data << " ";

            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);

        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
 }
int main()
{
 
}