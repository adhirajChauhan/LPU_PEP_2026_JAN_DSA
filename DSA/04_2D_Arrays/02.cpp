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

void rowSum(int arr[][4], int row, int col){
    for(int i = 0; i < 3; i++){
        int sum = 0;
        for(int j = 0; j < 4; j++){
            sum += arr[i][j];
        } cout << sum << endl;
    } 
}

int maxRowSum(int arr[][4], int row, int col){
    int maximum = INT_MIN;
    int rowIdx = -1;

    for(int i = 0 ;i < 3; i++){
        int sum =0;
        for(int j = 0; j < 4; j++){
            sum += arr[i][j];
        }
        if(sum  > maximum ){
            maximum = sum;
            rowIdx = i;
        }

    }
    return rowIdx;
}

void wavePrint(int arr[][4], int row, int col){
    for(int c = 0; c < 4; c++){
        if(c%2 == 0){
            for(int r = 0; r < 3; r++){
                cout << arr[r][c] << " ";
            }
        }
        else{
            for(int r = 2; r >=0; r--){
                cout << arr[r][c] << " ";
            }
        }
    }
}


void spiralPrint(int arr[][4], int row, int col){
    int topRow = 0;
    int bottomRow = row - 1; 
    int leftCol = 0;
    int rightCol = col - 1;


    while(topRow <= bottomRow && leftCol <= rightCol){
        //Print top row
        for(int i = leftCol; i <= rightCol; i++){
            cout << arr[topRow][i] << " ";
        }
        topRow++;
        //Print Right col
        for(int i = topRow; i <= bottomRow; i++){
            cout << arr[i][rightCol] << " ";
        }
        rightCol--;

        //Print bottom ROw
        for(int i = rightCol; i >= leftCol; i--){
            cout << arr[bottomRow][i] << " ";
        }
        bottomRow--;

        //Pront left col

        for(int i = bottomRow; i>= topRow; i--){
            cout << arr[i][leftCol] << " ";
        }
        leftCol++;
    }
}
 
int main()
{
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    // if(isPresent(arr, 26,3,4)) cout << "Element is Present "<< endl;
    // else cout << "Element is not present" << endl;

    cout << maxRowSum(arr, 3,4);


}