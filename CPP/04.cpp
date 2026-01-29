#include<iostream>
using namespace std;
 
int main()
{
    int age = 5;
    int &ref = age;

    ref = 20;

    cout << age << endl;
}