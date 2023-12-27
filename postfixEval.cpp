#include<iostream>
#include<stack>
#include<string>
using namespace std;
void postfixEval(string s){
    stack<int> st;
    for(int i=0; i<s.length(); i++){
        char c=s[i];
        if(c>='0' && c<='9'){
            st.push(c-'0');
        }
        else{
            int num1=st.top();
            st.pop();
            int num2= st.top();
            st.pop();
            switch(c){
                case '+':
                st.push(num1 + num2);
                break;
                case '-':
                st.push(num2-num1);
                break;
                case '*':
                st.push(num1*num2);
                break;
                case '/':
                st.push(num2/num1);
                break;
            }
        }
    }
    cout<<st.top();
}
int main(){
    string exp="12+";
    postfixEval(exp);
    return 0;
}