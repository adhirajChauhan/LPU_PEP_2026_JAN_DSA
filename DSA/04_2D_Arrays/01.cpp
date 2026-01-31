#include<iostream>
using namespace std;
 
int main()
{
    // int arr[3][4] = {{1,2,3,4},{5,6,7,8}, {9,10,11,12}};
    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    int arr[3][4];

//taking input row wise
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 4;j++){
    //         cin >> arr[i][j];
    //     }
    // }

    //taking input columnn wise
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3;j++){
            cin >> arr[j][i];
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }
}