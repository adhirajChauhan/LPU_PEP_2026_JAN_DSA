https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.length() != t.length()){
            return false;
       } 

       int arr[26] = {0};

       for(char i : s){
        arr[i - 'a']++;
       }

       for(char i : t){
        arr[i - 'a']--;
        if(arr[i - 'a'] < 0) return false; 
       }
       return true;
    }
};  

https://leetcode.com/problems/valid-palindrome-ii/
class Solution {
public:
    bool PalindromeHelper(string &s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left  = 0, right = s.size() - 1;
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }
            else{
                return PalindromeHelper(s, left + 1, right) || PalindromeHelper(s, left, right -1);
            }
        }
        return true;
    }
};


https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        int n = s.length();
        int m = t.length();

        while(i < n && j < m){
            if(s[i] == t[j]){
                i++;
            } 
            j++;
        }
        return (i == n);
    }
};



https://www.geeksforgeeks.org/problems/find-first-repeated-character4108/1

class Solution {
  public:
    string firstRepChar(string s) {
        // code here.
        string ans = "";
        vector<bool> seen(256,false);
        for(char i : s){
            if(seen[i]) {
                ans += i;
                return ans;
                
            }
            seen[i] = true;
        }
        return "-1";
        
    }
};


https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

class Solution {
public:

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        // First window
        for(int i = 0; i < k; i++) {
            if(isVowel(s[i]))
                count++;
        }

        int ans = count;

        // Sliding window
        for(int i = k; i < s.size(); i++) {

            if(isVowel(s[i - k]))
                count--;

            if(isVowel(s[i]))
                count++;

            ans = max(ans, count);
        }

        return ans;
    }
};

https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for(int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while(sum >= target) {

                minLen = min(minLen, right - left + 1);

                sum -= nums[left];
                left++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
