
https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root== NULL) return -1;

        queue<TreeNode*> q;
        q.push(root);
        vector<long long> levelSum;

        while(!q.empty()){
            long long sum = 0;
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                sum += frontNode->val;

                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);

            }
            levelSum.push_back(sum);
        }
        sort(levelSum.rbegin(), levelSum.rend());
        if(levelSum.size() < k) return -1;

        return levelSum[k-1];

    }
};


https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> levelElements;

            for(int i = 0; i < levelSize; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                levelElements.push_back(frontNode->val);

                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);

            }
            if(!leftToRight){
                reverse(levelElements.begin(), levelElements.end());
            }
            result.push_back(levelElements);

            leftToRight = !leftToRight;
        }
        return result;


    }
};




https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    void traverseLeft(Node *root, vector<int> &ans){
        if(root==NULL || (root->left == NULL && root->right ==NULL)) return;
        
        ans.push_back(root->data);
        
        if(root->left) traverseLeft(root->left, ans);
        else traverseLeft(root->right, ans);
    }
    
        void traverseRight(Node *root, vector<int> &ans){
         if(root==NULL || (root->left == NULL && root->right ==NULL)) return;
         
         if(root->right) traverseRight(root->right, ans);
         else traverseRight(root->left, ans);
         
         ans.push_back(root->data);
    }
    void traverseLeaf(Node *root, vector<int> &ans){
        if(root==NULL) return;
        if(root->left ==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right,ans);
        
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL) return ans;
        ans.push_back(root->data);
        traverseLeft(root->left, ans);
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        traverseRight(root->right,ans);
        return ans;
        
    }
};



https://leetcode.com/problems/binary-tree-right-side-view/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            int lastValue = 0;
            for(int i = 0; i < levelSize;i++){
                TreeNode* frontNode = q.front();

                q.pop();
                lastValue = frontNode->val;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            result.push_back(lastValue);
        }
        return result;
    }
};