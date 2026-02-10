#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class MyStack{
    public:
    Node* top;

    MyStack(){
        top = NULL;
    }

    void push(int val){
        Node* node = new Node(val);
        node->next = top;
        top = node;
    }

    void pop(){
        if(top == NULL){
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek(){
        if(top == NULL){
            cout << "Stack is Empty "<< endl;
            return;
        }
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }
};
 
int main()
{
 
}