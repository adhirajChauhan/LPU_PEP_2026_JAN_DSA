https://www.geeksforgeeks.org/problems/heap-sort/1

// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
  
    void heapify(vector<int>& arr, int n , int i){
        int largest = i;
        int left = 2 * i +1 ;
        int right = 2 * i + 2;
        
        if(left < size && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < size && arr[right] > arr[largest]){
            largest = right;
        }
        
        if(largest != i){
            swap(arr[i], arr[largest]);
            
            heapify(arr, n, largest);
        }
    }
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        for(int i = n/2 - 1; i >= 0; i--){
            heapify(arr, n, i);
        }
        
        for(int i = n - 1; i > 0; i--){
            swap(arr[0], arr[i]);
            
            heapify(arr, i, 0);
        }
        
        
        
    }
};