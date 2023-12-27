#include<iostream>
using namespace std;
int partition(int arr[], int s, int e){
    int pivot=arr[s];
    int c=0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot){
            c++;
        }
    }
    int pivotIndex=s+c;
    int temp=arr[pivotIndex];
    arr[pivotIndex]=arr[s];
    arr[s]=temp;

    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex ){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int p=partition(arr, s, e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);

}
int main(){
    int a[5]={1,5,6,3,4};
    quickSort(a, 0, 4);
    for(int i=0; i<5; i++){
        cout<<a[i]<<" ";
    }
}