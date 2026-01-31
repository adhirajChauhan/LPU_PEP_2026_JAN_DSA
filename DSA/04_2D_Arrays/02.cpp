#include<iostream>
using namespace std;

bool isPresent(int arr[][4], int target, int row, int col){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(arr[i][j] == target)
            {
                return true;
            }
            
        }
    }
    return false;
}
 
int main()
{
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    if(isPresent(arr, 26,3,4)) cout << "Element is Present "<< endl;
    else cout << "Element is not present" << endl;


}