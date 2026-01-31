#include<iostream>
using namespace std;

bool isSorted(int arr[], int size){

}

bool linearSearch(int arr[], int size, int key){
    if(size == 0) return false;

    if(arr[0] == key) return true;

    else{
        return linearSearch(arr+1, size -1, key);
    }
}

bool binarySearch(int arr[], int left, int right, int key){
    //using recursion  
    if(left>right) return false;
    int mid = left + (right-left)/2; 
    if(arr[mid] == key) return true;

    else if(arr[mid] < key){
        return binarySearch(arr, mid+1, right, key);
    }
    else{
        return binarySearch(arr, left, mid-1, key);

    }



}
 
int main()
{
 
}