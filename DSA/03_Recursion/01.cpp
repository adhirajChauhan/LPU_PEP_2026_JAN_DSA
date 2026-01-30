#include<iostream>
using namespace std;

void print(int n){
    if(n == 0) return;

    print(n-1);
    cout << n << " ";
}

int factorial(int n){
    //base case
    if(n == 0 || n == 1) return 1;

    return n * factorial(n-1);
}

int fib(int n){
    if(n == 0) return 0;
    if(n==1) return 1;

    return fib(n-1) + fib(n-2);
}
 
int main()
{
    print(10);
}