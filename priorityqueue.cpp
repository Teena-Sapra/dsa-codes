#include<iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        size=0;
        arr[0]=-1;
    }
    void swap(int &a, int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void insert(int val){
        size++;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void maxHeapify(int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;
        if(left<=size && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=size && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            maxHeapify(largest);
        }
    }
    int extractMax(){
        swap(arr[1],arr[size]);
        int ans=arr[size];
        size--;
        maxHeapify(1);
        return ans;
    }
    int maximum(){
        return arr[1];
    }
    void incKey(int i, int key){
        if(arr[i]>key){
            cout<<"new key is smaller than old key";
            return;
        }
        arr[i]=key;
        int index=i;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
};
int main(){
    heap pq;
    return 0;
}