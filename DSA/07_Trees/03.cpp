https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        // code here
        if(root == NULL) return -1;
        
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
        
  
    }
};






