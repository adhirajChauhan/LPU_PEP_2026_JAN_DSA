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