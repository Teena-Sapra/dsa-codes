#include<iostream>
#include<stack>
#include<string>
using namespace std;
void postfixToInfix(string s){
    stack<string> st;
    for(int i=0; i<s.length(); i++){
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z')){
            st.push(string(1, c));
        }
        else{
            string value1 = st.top();
            st.pop();
            string value2 = st.top();
            st.pop();
            st.push("(" + value2 + c + value1 + ")");
        }
    }
    cout<<st.top();
}
int main(){
    string exp ="abc-+de-fg-h+/*";
    postfixToInfix(exp);
    return 0;
}