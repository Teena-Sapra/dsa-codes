#include<iostream>
using namespace std;
void selection_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min_index=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
}
int main(){
    int arr[5]={4,5,1,3,2};
    selection_sort(arr, 5);
    for(int i=0; i<5; i++){
        cout<<arr[i];
    }
    return 0;
}