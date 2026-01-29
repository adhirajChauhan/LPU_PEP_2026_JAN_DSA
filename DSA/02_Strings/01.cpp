#include<iostream>
using namespace std;
 
int main()
{
    // char arr[5] = {'h', 'e','l', 'l', 'o'};
    // string str = "There are " + to_string(30+50) + " students in class";

    string s1 = "Hello";
    string s2 = "hello";

    // if(s1 == s2){
    //     cout << "Strings are same";
    // }
    // else cout << "Strings are not same";

    int x = s1.compare(s2);
    if(x==0) cout << "Same"; else cout << "different";
   
}