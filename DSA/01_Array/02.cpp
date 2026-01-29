// https://www.geeksforgeeks.org/problems/reverse-an-array/0

// class Solution {
//   public:
//     void reverseArray(vector<int> &arr) {
//         // code here
//         int i = 0;
//         int j = arr.size() - 1;
        
//         while(i < j){
//             swap(arr[i++], arr[j--]);
//         }
//     }
// };




// https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

// class Solution {
//   public:
//     bool isSorted(vector<int>& arr) {
//         // code here
//         for(int i = 0; i <arr.size()-1; i++){
//             if(arr[i] > arr[i+1]) return false;
//         }
//         return true;
//     }
// };

// https://leetcode.com/problems/running-sum-of-1d-array/

// class Solution {
// public:
//     vector<int> runningSum(vector<int>& nums) {
//         for(int i = 1; i < nums.size()-1; i++){
//             nums[i] = nums[i] + nums[]i-1;
//         }
//     }
// };

https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1
// class Solution {
//   public:
//     int largest(vector<int> &arr) {
//         // code here
        
//         //run a loop on size of array{
//         // int largest
//             //if the ith element is greater than largest
//             //update largets
//         }
//         // return largest
        
//     }
// };


https://www.geeksforgeeks.org/problems/second-largest3735/1
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = INT_MIN, s_largest = INT_MIN;
        
        for(int i : arr){
            if(i > largest){
                s_largest = largest;
                largest = i;
            }
            else if(i > s_largest && i < largest){
                s_largest = i;
            }
        }
        
        return s_largest == INT_MIN ? -1 : s_largest;
    }
};



https://leetcode.com/problems/max-consecutive-ones/description/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, currCount = 0;

        for(int i : nums){
            if(i == 1){
                currCount++;
                maxCount = max(maxCount, currCount);
            }
            else{
                currCount = 0;
            }
        }
        return maxCount;
    }
};