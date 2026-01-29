#include<iostream>
using namespace std;

void increment(int &x){
    x++;
    cout << "Inside function : " << x << endl;
}
 
int main()
{
    // int age = 5;
    // increment(age);

    // cout << "In main function : " << age << endl;



    // int a = 5;
    // int &ref = a;

    // int *ptr = &a;

    // cout << a << endl;
    // cout << &ref << endl;
    // cout << ptr << endl;
    // cout << *ptr << endl;


    // int x = 10;
    // int *p = &x;
    // *p = 20;

    int x = 10;
    int &r = x;
    r++;

    cout << x;


}