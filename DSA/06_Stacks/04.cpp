#include<iostream>
using namespace std;

class MyQueue{
    public:
    int* arr;
    int front;
    int rear;
    int size;

    MyQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueueh(int val){
        if(rear == size-1){
            cout << "Queue overflow" << endl;
            return;
        }
        if(front == -1){
            front = 0;
        }
        rear++;
        arr[rear] = val;
    }

    void dequeue(){
        if(front == -1 || front > rear){
            cout << "Queue underflow" << endl;
            return;
        }
        front++;
    }

    //get the front element
    int getFront(){
        if(front == -1 || front > rear){
            cout << "Queueu is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    
};
 
int main()
{
 
}