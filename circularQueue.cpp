#include<iostream>
using namespace std;
class queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    queue(int s){
        size=s;
        arr= new int[size];
        front=-1;
        rear=-1;
    }
    bool isFull(){
        return ((front==0 && rear==size-1) || (rear==(front-1)%(size-1)));
    }
    void enqueue(int d){
        if(this->isFull()){
            cout<<"queue is full"<<endl;
        }
        else{
            if(front==-1){
                front=0;
                rear=0;
            }
            else if(rear==size-1){
                rear=0;
            }
            else{
                rear++;
            }
            arr[rear]=d;
        }
    }
    bool isEmpty(){
        return (front==rear && rear==-1);
    }
    int dequeue(){
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
    int peek(){
        if(this->isEmpty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

};
int main(){
    queue q1(3);
    q1.enqueue(1);
    q1.enqueue(2);
    cout<<q1.dequeue();
    q1.enqueue(3);
    q1.enqueue(4);
    return 0;
}