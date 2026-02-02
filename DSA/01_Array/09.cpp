
https://www.geeksforgeeks.org/problems/aggressive-cows/1
class Solution {
  public:
  bool canPlace(vector<int> &stalls, int k, int distance){
    
        int lastPos = stalls[0];
        int cowPlaced = 1;
      for(int i = 1; i < stalls.size(); i++){
          if(stalls[i] - lastPos >= distance){
              cowPlaced++;
              lastPos = stalls[i];
              if(cowPlaced == k) return true;
          }
          
      }
      return false;
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        
        int low = 1;
        int high = stalls.back() - stalls.front();
        int ans = 0;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(canPlace(stalls, k, mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
        
    }
};