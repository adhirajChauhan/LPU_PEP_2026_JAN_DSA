#include<iostream>
using namespace std;

class MyStack{
    public:
    int *arr;
    int top;
    int size;

    MyStack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

     void push(int val){
        if(top == size -1){
            cout << "Stack Overflow "<< endl;
            return;
        }
        top++;
        arr[top] = val;
     }

     void pop(){
        if(top == -1){
            cout << "Stack Underflow " << endl;
            return;
        }
        top--;
     }

     int peek(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
     }
     bool isEmpty(){
        return top == -1;
     }
};
 


int main()
{
    MyStack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    // st.push(6);

    st.pop();
    st.pop();
    st.pop();
    // st.pop();
    // st.pop();
    // st.pop();

    cout << st.peek();


    cout << st.isEmpty();

}