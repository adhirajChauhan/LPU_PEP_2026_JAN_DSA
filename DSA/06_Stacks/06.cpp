https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

void deleteFronmStack(stack<int>&inputStack, int count, int size){
   if(inputStack.empty()|| count == size/2){
      inputStack.pop();
      return;
   }
   int temp = inputStack.top();
   inputStack.pop();
   deleteFronmStack(inputStack, count + 1, size);
      inputStack.push(temp);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count = 0;
   deleteFronmStack(inputStack, count, N);

}




https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;

                char top = st.top();
                if((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};






https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1

// User function Template for C++

class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        
        if(st.empty()){
            st.push(x);
            return st;
        }
        
        int topValue = st.top();
        st.pop();
         
        st = insertAtBottom(st, x);
        st.push(topVal);
        
        return st;
    }
    
};



https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
class Solution {
  public:
  int precedence(char c){
      if(c == '^') return 3;
      if(c == '*' || c == '/') return 2;
      if(c == '+' || c == '-') return 1;
      return -1;
  }
    string infixToPostfix(string& s) {
        // code here
        
        stack<char> st;
        string ans = "";
        
        for(char c : s){
            if(isalnum(c)){
                ans += c;
            }
            else if(c == '('){
                st.push(c);
            }
            else if(c == ')'){
                while(!st.empty() && st.top() != '(' ){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && precedence(st.top()) >= precedence(c) && !(c == '^' && st.top() == '^')){
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
        
    }
};

