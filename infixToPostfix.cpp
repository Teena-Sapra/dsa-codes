#include<iostream>
#include<stack>
#include<string>
using namespace std;
int precedence(char c){
    if(c=='^'){
        return 3;
    }
    if(c=='*' || c=='/'){
        return 2;
    }
    if(c=='+' || c=='-'){
        return 1;
    }
    return -1;
}
void infixToPostfix(string s){
    stack<char> st;
    string ans;
    for(int i=0; i<s.length(); i++){
        char c=s[i]; 
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            ans+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(st.top())>=precedence(c)){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
            ans+=st.top();
            st.pop();
    }
    cout<<ans;
}
int main(){
    string exp="a+(b*(c-d)/e)";
    infixToPostfix(exp);
    return 0;
}