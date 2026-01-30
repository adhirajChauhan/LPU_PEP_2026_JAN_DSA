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

bool binarySearch(){
    //using recursion
}
 
int main()
{
 
}