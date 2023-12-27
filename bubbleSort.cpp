#include<iostream>
using namespace std;
int main(){
    int arr[5]={3,2,5,4,1};
    for(int i=0; i<5-1; i++){
        bool swap=false;
        for(int j=0; j<5-i; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=true;
            }
        }
        if(swap==false){
            break;
        }
    }
    for(int i=0; i<5; i++){
        cout<<arr[i];
    }
    return 0;
}