https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n  = nums2.size();
        unordered_map<int, int> mp;
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            else{
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> result;
        for(int i = 0; i < nums1.size(); i++){
            result.push_back(mp[nums1[i]]);
        }

        return result;

    }
};


https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> left(n);
        vector<int> right(n);

        //find the previous smaller
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();

        //find next smaller
        for(int i = n - 1; i >=0 ; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n;
            }
            else{
                right[i] = st.top();
            }
            st.push(i);
        }

        //calculate max area
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int height = heights[i];
            int width = right[i] - left[i] - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};