
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















