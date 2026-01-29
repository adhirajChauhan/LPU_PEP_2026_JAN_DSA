#include<iostream>
#include<vector>
using namespace std;

string reverseString(string &s){
    int l = 0; int r = s.length() - 1;
    
    while(l < r){
        swap(s[l++], s[r--]);
    }
    return s;
}

string removeDulpicates(string &s){
    vector<bool> visited(256, false);
    string result = "";

    for(char i : s){
        if(!visited[i]){
            result.push_back(i);
            visited[i] = true;
        }
    }
    return result;
}
 
int main()
{
 
}




