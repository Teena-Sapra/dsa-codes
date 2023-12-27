//Reverse a string using stack
#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char> s;
    string str="teena";
    for(int i=0; i<str.length(); i++){
        char ch=str[i];
        s.push(ch);
    }
    string ans="";
    while(!s.empty()){
        char ch=s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout<<ans;
    return 0;
}