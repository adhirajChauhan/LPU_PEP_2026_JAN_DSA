// #include<iostream>
// using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// int removeDuplicates(vector<int> &arr){

//     int i = 0;
//     for(int j = 1; j < arr.size(); j++){
//         if(arr[j] != arr[i]){
//             i++;
//             arr[i] = arr[j];
//         }
//     }
//     return i + 1;
// }
 
// int main()
// {
 
// }


// https://leetcode.com/problems/merge-sorted-array/

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = m - 1; j = n -1; k = m+n-1;
//             while(j >=0){
//                 if(i >= 0 && nums1[i] > nums2[j]){
//                     nums1[k] = num1[i];
//                     k--;
//                     i--;
//                 }
//                 else{
//                     num1[k] = nums2[j];
//                     k--;
//                     j--;
//                 }
//             }

//     }
// };



// https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// class Solution {
//   public:
//     void sort012(vector<int>& arr) {
//         // code here
//         int low = 0; mid = 0; high = arr.size() - 1;
        
//         while(mid <= high){
//             if(arr[mid] == 0){
//                 swap(arr[low++], arr[mid++]);
//             }
//             else if(arr[mid] == 1){
//                 mid++;
//             }
//             else{
//                 swap(arr[mid], arr[high--]);
//             }
//         }
//     }
// };





// https://www.geeksforgeeks.org/problems/common-elements1132/1
// class Solution {
//   public:
//     // Function to find common elements in three arrays.
//     vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
//                                vector<int> &arr3) {
//         // Code Here
//         int i = 0;
//         int j = 0;
//         int k = 0;
        
//         vector<int> result;
        
//         while(i < arr1.size() && j < arr2.size() && k < arr3.size()){
//             if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
//                 if(result.empty() || result.back() != arr1[i]){
//                     result.push_back(arr1[i]);
//                 }
//                 i++;
//                 j++;
//                 k++;
 
//             }
//             else if(arr1[i] < arr2[j]) i++;
//             else if(arr2[j] < arr3[k]) j++;
//             else k++;
//         }
//         return result;
        
//     }
// };

// https://www.geeksforgeeks.org/problems/pair-sum-in-a-sorted-and-rotated-array/1
// // User function Template for C++

// class Solution {
//   public:
//     bool pairInSortedRotated(vector<int>& arr, int target) {
//         // code here
//         int n = arr.size();
//         int pivot = -1;
        
//         //find the pivot(the largest element)
//         for(int i = 0; i < n -1; i++){
//             if(arr[i] > arr[i+1]){
//                 pivot = i;
//                 break;
//             }
//         }
        
//         if(pivot == -1){
//             pivot = n-1;
//         }
        
//         int low = (pivot+1)%n;
//         int high = pivot;
        
//         while(low != high){
//             int sum = arr[low] + arr[high];
//             if(sum == target) return true;
            
//             else if(sum < target) low = (low + 1)%n;
            
//             else high = (high - 1 + n)%n;
//         }
//         return false;
        
        
        
//     }
// };




// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


// class Solution {
// public:
//     int firstOccurance(vector<int> &nums, int target){
//         int left = 0, right = nums.size()-1;
//         int ans = -1;

//         // while(left <= right)
//         //find mid

//         //if mid is target ->store in ans variable and go left(because we will always find first occurance on left)

//         // else if mid < target -> go right
//         // else go left

//         while(left <= right){
//             int mid = (left + right)/2;
//             if(nums[mid] == target){
//                 ans = mid;
//                 right = mid - 1;
//             }
//             else if(nums[mid] < target){
//                 left = mid + 1;
//             }
//             else {
//                 right = mid - 1;
//             }
//         }
//         return ans;
//     }

//     int lastOccurance(vector<int> &nums, int target){
//         int left = 0, right = nums.size()-1;
//         int ans = -1;

//         while(left <= right){
//             int mid = (left + right)/2;
//             if(nums[mid] == target){
//                 ans = mid;
//                 left = mid + 1;
//             }
//             else if(nums[mid] < target){
//                 left = mid + 1;
//             }
//             else {
//                 right = mid - 1;
//             }
//         }
//         return ans;
//     }
//     vector<int> searchRange(vector<int>& nums, int target) {
//         return {firstOccurance(nums, target),lastOccurance(nums,target)};
//     }
// };



// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

// class Solution {
//   public:
//     int findFloor(vector<int>& arr, int x) {
//         // code here
//         int left = 0;
//         int right = arr.size()-1;
        
//         int ans = -1;
        
//         while(left <= right){
//             int mid = (left + right)/2;
            
//             if(arr[mid] == x){
//                 ans = mid;
//                 left = mid + 1;
//             }
//             else if(arr[mid] < x){
//                 ans = mid;
//                 left = mid +1;
//             }
//             else{
//                 right = mid - 1;
//             }
//         }
//         return ans;
        
//     }
// };


// https://leetcode.com/problems/maximum-subarray/

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int currSum = 0;
//         int maxSum = nums[0];

//         for(int i = 0; i<nums.size(); i++){
//             currSum += nums[i];
//             if(currSum > maxSum) maxSum = currSum;

//             if(currSum < 0) currSum = 0;
//         }
//         return maxSum;
//     }
// };



// https://www.geeksforgeeks.org/problems/reverse-array-in-groups0255/1


// class Solution {
//   public:
//     void reverseInGroups(vector<int> &arr, int k) {
//         // code here
//         int n = arr.size();
        
//         for(int i = 0; i < n; i+=k){
//             int start = i;
//             int end = min(i + k - 1, n-1);
            
//             while(start < end){
//                 swap(arr[start++], arr[end--]);
//             }
//         }
//     }
// };


// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

// class Solution {
//   public:
//     int maxSubarraySum(vector<int>& arr, int k) {
//         int n = arr.size();
//         // code here
//         int currSum = 0;
        
        
//         for(int i = 0; i < k; i++){
//             currSum+=arr[i];
//         }
//         int maxSum  = currSum;
        
//         for(int i = k; i < n;i++){
//             currSum = currSum - arr[i-k] + arr[i];
//             if(currSum > maxSum) maxSum = currSum;
//         }
//         return maxSum;
//     }
// };



// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         int n = nums.size();
//         // find total ones
//         // totalOnes = ?
//         int totalOnes = 0;
//         for(int i : nums){
//             if(i == 1) totalOnes++;
//         }

//         //intilize a window of size of totalOnes starting from beg
//         int currentOnes = 0;

//         for(int i = 0; i < totalOnes; i++){
//             if(nums[i] == 1){
//                 currentOnes++;
//             }
           
//         }
//         int maxOnes = currentOnes;

//     for(int i = totalOnes; i < n + totalOnes; i++){
        
//         currentOnes -= (nums[(i-totalOnes) % n]);

//         currentOnes += nums[(i)%n];

//         maxOnes = max(maxOnes,currentOnes);
//     }
//     return totalOnes - maxOnes;

//     }
// };


https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int findMaxElement(vector<int>& piles){
        int maximum = INT_MIN;

        for(int i = 0; i < piles.size(); i++){
            maximum = max(maximum, piles[i]);
        }
        return maximum;
    }

    long long calculateHours(vector<int>& piles, int k){
        long long totalHours = 0;
        for(int i = 0; i < piles.size(); i++){
            totalHours += ceil(double(piles[i])/double(k));
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMaxElement(piles);
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            
            long long totalHours = calculateHours(piles,mid);

            if(totalHours <= h){
                high = mid-1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }

        }
        return ans;
    }
};