#include<iostream>
using namespace std;
bool find(int arr[], int size, int key){
    for(int i=0; i<size;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int key;
    cout<<"enter value to search:";
    cin>>key;
    bool ans= find(arr,10,key);
    if(ans){
        cout<<"it exists";
    }else{
        cout<<"it does not exist";
    }
    return 0;
}