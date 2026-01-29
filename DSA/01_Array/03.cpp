#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    vector<int> vec1 = {2,3,1,5,4};

    // cout << vec1[6];

    // cout << vec1.at(6);

    vec1.push_back(10);

    for(int i : vec1){
        cout << i << " ";
    }

    vec1.pop_back();

    for(int i : vec1){
        cout << i << " ";
    }

    vec1.size();

    vec1.clear();
}