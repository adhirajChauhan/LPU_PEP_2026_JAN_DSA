#include<iostream>
using namespace std;

string firstRepChar(string s) {
        // code here.
        string ans = "";
        vector<bool> seen(256,false);
        for(char i : s){
            if(seen[i]) {
                ans += i;
                return ans;
                
            }
            seen[i] = true;
        }
        return "-1";
        
    }
 
int main()
{
    string s = "bcaaeebfdbbcbfcaeebdcb";

    cout << firstRepChar(s);
}   