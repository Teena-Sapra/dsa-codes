#include<iostream>
using namespace std;
void Maxheapify(int arr[], int n, int i){
    int largest=i;
    int left= 2*i;
    int right = 2*i+1;
    if(left<=n && arr[largest]< arr[left]){
        largest= left;
    }
    if(right<=n && arr[largest] < arr[right] ){
        largest= right;
    }
    if(largest!=i){
        swap(arr[largest], arr[i]);
        Maxheapify(arr, n, largest);
    }
}
void heapSortInc(int arr[], int n){
    int size=n;
    while(size>1){
        swap(arr[size], arr[1]);
        size--;

        Maxheapify(arr,size, 1);
    }
}
void Minheapify(int arr[], int n, int i){
    int smallest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[left]<arr[smallest]){
        smallest=left;
    }
    if(right<=n && arr[right]<arr[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[i], arr[smallest]);
        Minheapify(arr,n,smallest);
    }
}
void heapSortDec(int arr[], int n){
    int size=n;
    while(size>1){
        swap(arr[1],arr[size]);
        size--;
        Minheapify(arr,size,1);
    }
}
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int arr[]={-1,54,53,55,52,50};
    int n=5;
    /*for(int i=n/2;i>0; i--){
        Maxheapify(arr,n,i);
    }
    heapSortInc(arr,n);*/
    for(int i=n/2; i>0; i--){
        Minheapify(arr,n,i);
    }
    heapSortDec(arr,n);
    for(int i=1; i<=n; i++){ 
        cout<<arr[i]<<" ";
    }
    return 0;

}