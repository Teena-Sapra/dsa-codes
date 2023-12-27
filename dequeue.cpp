#include<iostream>
using namespace std;
class dequeue{
    public:
    int *arr;
    int front;
    int size;
    int rear;
    dequeue(int n){
        size=n;
        front=-1;
        rear=-1;
        arr= new int[size];
    }
    bool isFull(){
        return ((front==0 && rear=size-1) ||  (front!=0  && rear==(front-1)%(size-1)));
    }
    void pushFront(int d){
        if(this->isFull()){
            cout<<"full"<<endl;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(front==0){
            front=n-1;
        }
        else{
            front--;
        }
        arr[front]=d;
    }
    void pushRear(int d){
        if(this->isFull()){
            cout<<"Full";
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(rear==size-1){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=d;

    }
    bool isEmpty(){
        return (front==rear);
    }
    int popFront(){
        if(this->isEmpty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        else{
            int data=arr[front];
            if(front==size-1){
                front=0;
            }
            else{
                front++;
                if(front==rear){
                    front=-1;
                    rear=-1;
                }
            }
            return data;
        }
    }
    int popRear(){
        if(this->isEmpty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        else{
            int data=arr[rear];
            if(rear==0){
                rear=size-1;
            }
            else{
                rear--;
                if(front==rear){
                    front=-1;
                    rear=-1;
                }
            }
            return data;
        }

    }
};