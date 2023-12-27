#include<iostream>
using namespace std;
void merge(int*arr, int s, int e){
    int mid=(s+e)/2;
    int l1=mid-s+1;
    int l2=e-mid;
    int*first= new int[l1];
    int*second= new int[l2];
    //copy values
    int k=s;
    for(int i=0; i<l1; i++){
        first[i]=arr[k];
        k++;
    }
    k=mid+1;
    for(int i=0; i<l2; i++){
        second[i]=arr[k];
        k++;
    }
    //merge 2 sorted arrays
    int index1=0;
    int index2=0;
    //k is the main array index
    k=s;
    while(index1<l1 && index2<l2){
        if(first[index1]<second[index2]){
            arr[k]=first[index1];
            k++;
            index1++;
        }
        else{
            arr[k]=second[index2];
            k++;
            index2++;
        }
    }
    while(index1<l1){
        arr[k]=first[index1];
        k++;
        index1++;
    }
    while(index2<l2){
        arr[k]=second[index2];
        k++;
        index2++;
    }

}
void mergeSort(int*arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}
int main(){
    int a[5]={1,5,6,3,4};
    mergeSort(a, 0, 4);
    for(int i=0; i<5; i++){
        cout<<a[i]<<" ";
    }
}