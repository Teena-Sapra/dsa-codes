#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
};
class stack{
    public:
    node*top;
    stack(){
        top=NULL;
    }
    void push(int d){
        node*temp = new node(d);
        if(!temp){
            cout<<"overflow"<<endl;
        }
        temp->next=top;
        top=temp;
    }
    void pop(){
        if(top==NULL){
            cout<<"stack underflow"<<endl;
        }
        else{
            node*temp=top;
            top=top->next;
            free(temp);
        }
    }
    void display(){
        node*temp =top;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    stack s;
    s.push(1);
    s.push(3);
    s.push(5);
    s.pop();
    s.push(7);
    s.display();
    return 0;
}
