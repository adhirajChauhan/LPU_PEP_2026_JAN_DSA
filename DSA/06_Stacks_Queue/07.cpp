#include<iostream>
#include<stack>
using namespace std;

int prefixEval(string s){
    //create a stack

    //traverse from right to left

    //if(s[i] is operand -> push in the stack

    // else if it is operator -> create two variables to store top two elements, pop them and evalute with operator,
    //push the result back in stack

    // return the last remaining element from stack -> it is the answer

    stack<int> st;

    for(int i = s.length() - 1; i >= 0; i--){
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');
        }
        else{
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();

            switch(s[i]){
                case '+':
                    st.push(operand1 + operand2);
                    break;
                    case '-':
                    st.push(operand1 - operand2);
                    break;

                    case '*':
                    st.push(operand1 * operand2);
                    break;

                case '/':
                    st.push(operand1 / operand2);
                    break;
                case '^':
                    st.push(pow(operand1 , operand2));
                    break;
            }
        }
    }
    return st.top();
}
 
int main()
{
 
}