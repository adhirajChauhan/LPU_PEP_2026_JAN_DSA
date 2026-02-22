/*
    - priority queue is a special type of queue where elements are accessed on basis of priority, not the insertion order
    - by default it has highest element priority
    - internally it is implemented using heap (CBT) and max heap by default (largest element will be always on top)


*/

#include<iostream>
#include<queue>
using namespace std;
 
int main()
{
    // (max heap)
    priority_queue<int> pq_max;

    //(min heap)
    priority_queue<int, vector<int>, greater<int>> pq_min;

    pq_max.push(10);
    pq_max.push(5);
    pq_max.push(50);
    pq_max.push(20);

    cout << pq_max.size() << endl;

    while(!pq_max.empty()){
        cout << pq_max.top() << " ";
        pq_max.pop();
    }

}