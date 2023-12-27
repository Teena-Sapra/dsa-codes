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
        front=0;
        rear=0;
    }
    bool isFull(){
        return (rear==size);
    }
    void enqueue(int d){
        if(this->isFull()){
            cout<<"queue is full"<<endl;
        }
        else{
            arr[rear]=d;
            rear++;
        }
    }
    bool isEmpty(){
        return front==rear;
    }
    int dequeue(){
        if(this->isEmpty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        else{
            int data=arr[front];
            front++;
            if(front==rear){
                front=0;
                rear=0;
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
    queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    cout<<q1.dequeue();
    return 0;
}