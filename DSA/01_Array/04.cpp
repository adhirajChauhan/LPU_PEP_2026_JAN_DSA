#include<iostream>
using namespace std;

//find the key in array using linear search, if key is found and value of key  > 5, then return the double value of key otherwise return the half value of key
int linearSearch(int arr[], int key, int size){
        for(int i = 0; i < size; i++){
            if(arr[i] == key && key > 5) return 2 * key;
        }
        return -1;
}

int binarySearch(int arr[], int key, int size){
    int start = 0;
    int end = size - 1;

    while(start <= end){
        int mid = (start+end)/2;

        if(arr[mid] == key) return mid;

        else if(arr[mid] < key) start = mid+1;

        else end = mid - 1;
    }
    return -1;
}
 
int main()
{
    int arr[5] = {3,1,6,4,2};
    int key = 6;

    linearSearch(arr, key, 5)
}