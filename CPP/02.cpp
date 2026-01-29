#include<iostream>
using namespace std;
 
int main()
{

    // int i = 0;

    // while(i < 10){
    //     cout << i << " ";
    //     i++;
    // }

    // do{
    //     cout << i << " ";
    //     i++;
    // }
    // while(i < 10)

    // for(int i  = 0; i < 3; i++){
    //     for(int j = 0 ;  j < 3; j++){
    //         cout << i << " - " << j << endl;
    //     }
    // }

    // cout << i << endl;




    //Example

    int pin = 1234;
    int enteredCode;

    while(enteredCode != pin){
        cout << "Enter pin  : ";
        cin >> enteredCode;
    }

    cout << "Access granted";

 
}