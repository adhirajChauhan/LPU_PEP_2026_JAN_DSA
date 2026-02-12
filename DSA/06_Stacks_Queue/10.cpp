https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
public:
    vector<int> data;
    int front;
    int rear;
    int size;
    int count;

    MyCircularQueue(int k) {
        front = 0;
        rear = -1;
        count= 0;
        size = k;
        data.clear();
        data.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        rear = (rear+1)%size;
        data[rear] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        
        front = (front+1)%size;
        count--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return data[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return data[rear];
    }
    
    bool isEmpty() {
        return (count==0);
    }
    
    bool isFull() {
        return (count==size);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */






https://leetcode.com/problems/gas-station/


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int balance = 0;
        int total_tank = 0;
        int curr_tank = 0;
        int start = 0;
       for(int i = 0; i< n; i++){
            balance = gas[i]  - cost [i];
            total_tank += balance;
            curr_tank += balance;

            if(curr_tank < 0){
                start = i + 1;
                curr_tank = 0;
            }
       } 

       //if total_tank is negative, no solution is there
       if(total_tank < 0) return -1;

        return start;
    }   
};






https://leetcode.com/problems/asteroid-collision/


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int curr : asteroids){
            bool destroyed = false;
            while(!st.empty() && st.top() > 0 && curr < 0){
                int topVal = st.top();

                if(abs(topVal) < abs(curr)){
                    st.pop();
                    continue;
                }
                //if top is greater, curr explode
                else if(abs(topVal) > abs(curr)){
                    destroyed = true;
                }
                //if equal , both explodes
                else{
                    st.pop();
                    destroyed = true;
                }

                break;
            }
            if(!destroyed) st.push(curr);
        }

         vector<int> result(st.size());
            for(int i = st.size()-1; i >=0; i--){
                result[i] = st.top();
                st.pop();
            }
            return result;
    }
};




https://leetcode.com/problems/online-stock-span/submissions/1916728885/


class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int currSpan = 1;

        while(!st.empty() && st.top().first <= price){
            currSpan += st.top().second;
            st.pop();
        }

        st.push({price, currSpan});

        return currSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */



https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        stack<int> st;
        
        //push all persons in stack
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        //find a potential celebrity
        while(st.size() > 1){
            int A = st.top();
            st.pop();
            
            int B = st.top();
            st.pop();
            
            //if A knows B then A cannot be a celebrity
            if(mat[A][B] == 1) st.push(B);
            else st.push(A);
            
        }
        // if(st.empty()) return -1;
        
        int potentialCandidate = st.top();
        
        for(int i = 0; i < n; i++){
            if(i == potentialCandidate) continue;
            if(mat[potentialCandidate][i] == 1) return -1;
            if(mat[i][potentialCandidate] == 0) return -1;
        }
        return potentialCandidate;
        
    }
};




