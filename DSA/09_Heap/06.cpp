
https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i : nums){
            minHeap.push(i);

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};


https://www.geeksforgeeks.org/problems/k-largest-elements4206/1

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i : arr){
            minHeap.push(i);
            
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};


https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int n  = arr.size();
        for(int i = 0; i < k+1; i++){
            minHeap.push(arr[i]);
        }
        
        int idx = 0;
        
        for(int i = k+1; i < n; i++){
            arr[idx++] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[i]);
        }
        while(!minHeap.empty()){
            arr[idx++] = minHeap.top();
            minHeap.pop();
        }
    }
};


https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
class Solution {
  public:
    int minCost(vector<int>& arr) {
        
        //we will use a min heap and insert all rope lengths in it.
        
        
        //always extract two smallest elements, combine them,
        //add cost, push the combined rope back
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i : arr){
            pq.push(i);
        }
        int totalCost = 0;
        
        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            
            int cost = first + second;
            totalCost += cost;
            
            pq.push(cost);
        }
        return totalCost;
    }
};





https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
     //max heap   
     //pair{distance, value}
     //we want the largest distance at top

     priority_queue<pair<int, int>> maxHeap;

     for(int i : arr){
        int distance = abs(i  - x);
        maxHeap.push({distance, i});

        if(maxHeap.size()> k){
            maxHeap.pop();
        }
     }

     vector<int> result;
     while(!maxHeap.empty()){
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
     }
     sort(result.begin(), result.end());
     return result;
    }
};




https://leetcode.com/problems/top-k-frequent-elements/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i : nums){
            freq[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(auto i : freq){
            int number = i.first;
            int count = i.second;

            minHeap.push({count, number});

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();

        }
        return result;
    }
};





https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1


/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
  int countNodes(Node* root){
      if(root==NULL) return 0;
      return 1 + countNodes(root->left) + countNodes(root->right);
  }
  bool isCBT(Node* root, int idx, int count){
      if(root==NULL) return true;
      
      if(idx >= count) return false;
      
      else{
         bool left = isCBT(root->left, 2 * idx + 1, count);
         bool right = isCBT(root->right, 2 * idx + 2, count);
         
         return (left && right);
      }
  }
  
  bool isMaxOrderHeap(Node* root){
      if(root->left == NULL && root->right == NULL) return true;
      
      if(root->right == NULL) return (root->data > root->left->data);
      
      else{
          bool left = isMaxOrderHeap(root->left);
          bool right = isMaxOrderHeap(root->right);
          
          return (left && right && (root->data > root->left->data && root->data > root->right->data));
      }
  }
    bool isHeap(Node* tree) {
        // code here
        int idx = 0;
        int totalCount = countNodes(tree);
        if(isCBT(tree, idx, totalCount) && isMaxOrderHeap(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};





