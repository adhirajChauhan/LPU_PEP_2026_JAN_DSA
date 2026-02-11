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

https://leetcode.com/problems/min-stack/description/

class MinStack {
public:
stack<int> mainStack;
stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);

        if(minStack.empty() || val <= minStack.top()){
            minStack.push(val);
        }
        else{
            minStack.push(minStack.top());
        }
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */




https://leetcode.com/problems/implement-stack-using-queues/description/

class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        //enqueue in q2
        q2.push(x);

        //take all elements from q1, pop them and push in q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        //swap q1 and q2
        swap(q1, q2);


    }
    
    int pop() {
        int topVal = q1.front();
        q1.pop();
        return topVal;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */




https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size();
        for(int i = 0; i < n - 1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topVal = q.front();
        q.pop();
        return topVal;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */




https://www.geeksforgeeks.org/problems/queue-reversal/1

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        if(q.empty()) return;
        
        int temp = q.front();
        q.pop();
        
        //recursive
        reverseQueue(q);
        q.push(temp);
    }
};

https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        stack<int> st;
        
        if(k > q.size()) return q;
        
        //run a loop for k elements and push them in stack
        for(int i = 0; i < k; i++){
            st.push(q.front());
            q.pop();
        }
        //run a loop until st is empty and push all elements back in queue
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        //run a loop till size - k. pop all the elements of queue and push them bvack in queue again
        int n = q.size();
        for(int i = 0; i < n - k; i++){
            q.push(q.front());
            q.pop();
        }
        return q;
        
    }
};



https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1

class Solution {
  public:
  // 11 12 13 14 15 16 17 18 19 20
    void rearrangeQueue(queue<int> &q) {
        // code here
        stack<int> st;
        int halfSize = q.size()/2;
        
        //push first half elements into the stack
        //queue : 16 17 18 19 20 || stack : 15 14 13 12 11
        for(int i = 0 ; i < halfSize; i++){
            st.push(q.front());
            q.pop();
        }
    //enqueue back the stack elements
    // queue : 16 17 18 19 20 15 14 13 12 11
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    
    //dequeue the first half elements of queue and enqueue them back 
    //queue : 15 14 13 12 11 16 17 18 19 20
    for(int i = 0; i < halfSize; i++)
    {
        q.push(q.front());
        q.pop();
    }
    //again push the first half elements in stack
    //queue : 16 17 18 19 20 || stack : 11 12 13 14 15
    for(int i = 0; i < halfSize; i++){
        st.push(q.front());
        q.pop();
    }
    
    //interleave the elements of queue and stack
    // queue : 11 16 12 17 13 18 14 19 15 20
    while(!st.empty()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
        
    }
};






