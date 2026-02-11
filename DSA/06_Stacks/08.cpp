#include<iostream>
#include<stack>
using namespace std;
vector<int> nextGreaterElement(vector<int> & arr){
    int n = arr.size();
    stack<int> st;
    vector<int> nge(n);

    for(int i = n -1 ; i >= 0 ; i--){
        //remove all elemets smaller than or equal to current element
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}


vector<int> previousSmallerElement(vector<int> & arr){
    int n = arr.size();
    stack<int> st;
    vector<int> nge(n);

    for(int i = 0 ; i < n ; i++){
        //remove all elemets greater than or equal to current element
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}
 
int main()
{
    vector<int> arr = {4,5,2,10,8};

    vector<int> result = nextGreaterElement(arr);
    for(int i : result){
        cout << i << " ";
    }
 
}