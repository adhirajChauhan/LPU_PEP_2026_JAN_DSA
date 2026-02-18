/*
A Binary Search tree(BST) is a special type of tree where
    #Every node has at most two children
    #For Every node -
        All values in the LST are smaller
        All values in RST are greater
    #Both LST and RST are also BST

    #inorder traversal of a BST is always sorted
*/



https://leetcode.com/problems/search-in-a-binary-search-tree/
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root->val == val){
            return root;
        }
        if(val < root->val) return searchBST(root->left, val);
        
        return searchBST(root->right, val);
    }
};



https://leetcode.com/problems/range-sum-of-bst/
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;

        if(root->val >= low && root->val <= high){
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        else if(root->val < low){
            return rangeSumBST(root->right, low, high);
        }
        else{
            return rangeSumBST(root->left, low, high);
        }
    }
};




https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* buildBSTHelper(vector<int>& nums, int l, int r){
       //find mid element -> (l+r)/2
        //make nums[mid] the curr node
        //recursively build - 
            // LST -> nums[l]....mid-1
            //RST -> nums[mid+1]....r
            // return ...
            if(l > r) return NULL;
            int mid = (l+r)/2;

            TreeNode* node = new TreeNode(nums[mid]);
            node->left = buildBSTHelper(nums,l, mid -1);
            node->right = buildBSTHelper(nums, mid+1, r);
            return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBSTHelper(nums, 0, nums.size()-1);
    }
};



https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);

        if(val < root->val){
            root->left = insertIntoBST(root->left, val);
        }
        else{
            root->right = insertIntoBST(root->right, val);

        }
        return root;
    }
};





https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    void inorder(TreeNode* root, vector<int>& values){
        if(root==NULL) return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> values;
        inorder(root, values);

        int left = 0;
        int right = values.size() - 1;
        while(left < right){
            int sum = values[left] + values[right];
            if(sum==k) return true;
            else if(sum < k) left++;
            else right--;
        }
        return false;
    }
};

https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
        int count = 0;
        int ans = -1;
    void inorder(TreeNode* root, int k){

        if(root==NULL) return;
        inorder(root->left, k);
        count++;
        if(count == k) ans = root->val;
        inorder(root->right,k);

    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};



https://leetcode.com/problems/validate-binary-search-tree/

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
    bool validate(TreeNode* node, long long min, long long max){
        //if node is null
        // if node->val <= min OR >= max -> false
        //recursively validate :
            // LST (min, node->val)
            // RST(node->val, max)
        //if both are true then only return tru
        if(node == NULL) return true;

        if(node->val <= min || node->val >= max) return false;

        return validate(node->left, min, node->val) && validate(node->right, node->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};





https://leetcode.com/problems/delete-node-in-a-bst/
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

 //Step 1 -> find the node to be deleted by comparisons
 //Step 2 -> restructure its children while preserving BST order
    // There can be 3 cases for deleting a node
        //Case 1 -> No children (leaf node) -> this can be deleted directly
        //Case 2 -> One child -> replace the current node with its only child
        //Case -> two children -> to maintain the BST order, we need can either choose inorder successor(smallest value RST) or inorder predecessor(largest value in LST) and replace with current node

class Solution {
public:
    TreeNode* minElement(TreeNode* node){
        while(node->left != NULL){
            node = node->left;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==NULL) return NULL;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            //Case 1 : Node has no left child
            // in this replace the node with its right child
            if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            //Case 2 : Node has no right child
            // in this erplace the node with its left child
            else if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            //Case 3 :  Node has two children
            // find inorder successor
            TreeNode* temp = minElement(root->right);
            //copy the min element value in the node which we were suppose to del
            root->val = temp->val;

            //delete the successor from RST (as we have already copied the value)
            root->right = deleteNode(root->right,temp->val);
        }
        return root;
    }
};