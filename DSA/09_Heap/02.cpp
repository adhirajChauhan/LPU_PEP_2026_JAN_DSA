#include<iostream>
using namespace std;

class MaxHeap{
    public:
    vector<int> heap;

    void bubbleUp(int index){

        while(index> 0){
            //find the parent
            int parent = (index - 1)/2;

            //if curr node > than parent
            if(heap[index] > heap[parent]){
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else{
                break;
            }
        }

    }
    void bubbleDown(){
        
        int i  = 0;
        int size = heap.size(); 
        while(i < size){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if(left < size &&heap[left] > heap[largest]){
                largest = left;
            }
            if(right < size && heap[right] > heap[largest]){
                largest = right;
            }
            if(largest != i){
                swap(heap[i], heap[largest]);
                i = largest;
            }
            else{
                break;
            }
        }

    


    }

    void insert(int value){
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }
};
 
int main()
{
 
}