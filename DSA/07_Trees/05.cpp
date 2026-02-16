
https://leetcode.com/problems/sum-of-left-leaves/
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;

        int sum = 0;

        if(root->left && root->left->left == NULL && root->left->right == NULL){
            sum += root->left->val;
        }
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        return sum;


    }
};




https://leetcode.com/problems/same-tree/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if both are null
        if(p == NULL && q == NULL) return true;

        //if one is null means not identical
        if(p == NULL || q == NULL) return false;

        //are values different?
        if(p-> val != q->val){
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        
    }
};



https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode* invertTree(TreeNode* root) {
        if(root== NULL) return NULL;

         TreeNode* leftInverted = invertTree(root->left);
         TreeNode* rightInverted = invertTree(root->right);

         root->left = rightInverted;
         root->right = leftInverted;

         return root;


    }
};



https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
        vector<int> levelElements;
        for(int i = 0 ; i < levelSize; i++){
           TreeNode* frontNode = q.front();
            q.pop();

            levelElements.push_back(frontNode->val);

            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);

        }
        result.push_back(levelElements);
        }
        return result;

    }
};