#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;
void prefixToInfix(string s){
    stack<string> st;
    reverse(s.begin(), s.end());
    for(int i=0; i<s.length(); i++){
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z')){
            st.push(string(1,c));
        }
        else{
            string value1 = st.top();
            st.pop();
            string value2=st.top();
            st.pop();
            st.push("(" + value2 + c+ value1 +")");
        }
    }
    string ans= st.top();
    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.length(); i++){
        if(ans[i]=='('){
            ans[i]=')';
        }
        else if(ans[i]==')'){
            ans[i]='(';
        }
    }
    cout<<ans;
}
int main(){
    string exp="*+a-bc/-de+-fgh";
    prefixToInfix(exp);
    return 0;
}