#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int prec(char c){
    if(c=='^'){
        return 3;
    }
    if(c=='*' || c=='/'){
        return 2;
    }
    if(c=='+' || c=='-'){
        return 1;
    }
    return 0;
}
string rev(string s){
    reverse(s.begin(), s.end());
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
    }
    return s;
}
void infixToPrefix(string s){
    stack<char> st;
    string ans;
    string temp= rev(s);
    for(int i=0; i<temp.length(); i++){
        char c=temp[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z')|| (c>='0' && c<='9')){
            ans+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(st.top()!='('){
                ans+= st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(st.top())>=prec(c)){
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
    reverse(ans.begin(), ans.end());
    cout<<ans;
}
int main(){
    string exp = "(a+b^c)*d+e^5";
    infixToPrefix(exp);
    return 0;
}