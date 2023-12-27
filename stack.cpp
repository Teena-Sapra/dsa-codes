#include<iostream>
using namespace std;
class stack{
    public:
    int *arr;
    int top;
    int size;
    stack(int size){
        this->size=size;
        top=-1;
        arr= new int[size];
    }
    void push(int ele){
        if(size-top>1){
            top++;
            arr[top]=ele;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool isempty(){
        if(top>=0){
            return false;
        }
        else{
            return true;
        }
    }
};
int main(){
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(6);
    s.push(8);
    s.push(10);
    s.push(11);
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    s.pop();
    cout<<s.isempty()<<endl;
    s.pop();
    cout<<s.isempty()<<endl;
    return 0;
}