#include<iostream>
using namespace std;
int binary_search(int arr[], int size, int key){
    int start=0, end=size-1;
    int mid= start+ (end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            end=mid-1;
        }
        if(arr[mid]<key){
            start=mid+1;
        }
        mid= start+ (end-start)/2;
    }
    return -1;
}
int main(){
    int arr[9]={2,3,5,8,9,11,45,67,78};
    cout<<binary_search(arr, 9, 40);
    return 0;
}