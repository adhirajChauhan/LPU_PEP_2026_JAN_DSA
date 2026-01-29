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