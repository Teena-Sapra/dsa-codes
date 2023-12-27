#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int d){
        data=d;
        next=NULL;
    }
};
class queue{
    public:
    node*front;
    node*rear;
    queue(){
        front=NULL;
        rear=NULL;
    }
    void enqueue(int d){
        node*newNode= new node(d);
        if(front==NULL){
            front=rear=newNode;
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }
    }
    void dequeue(){
        if(front==NULL){
            cout<<"underflow"<<endl;
        }
        else{
            node*temp=front;
            if(front==rear){
                front=rear=NULL;
            }
            else{
                front=front->next;
            }
            delete temp;
        }
    }
};
int main(){
    queue q;
    q.enqueue(1);
    q.dequeue();
    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.front->data<<endl<<q.rear->data;
    return 0;
}