#include<iostream>
using namespace std;

void insert(int arr[], int size){
    for(int i=0; i<size; i++){
    cout<<"Enter "<<i<<"th element of Array: ";
    cin>>arr[i];
    }
}

void traverse(int arr[], int size){
    cout<<"Array is: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void remove(int arr[], int size){
    int ele, flag=0;
    cout<<"Enter element to be deleted: ";
    cin>>ele;
    for(int i=0; i<size; i++){
        if(arr[i]==ele){
            flag=true;
            for(int j=i; j<size; j++)
                arr[i]=arr[j+1];
            size--;
            break;
        }
    }
    if(!flag)
        cout<<"Element not exist"<<endl;
    else{
        cout<<"Element deleted"<<endl;
        cout<<"Array is: "<<endl;
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
        
    }
}

int main(){
    int arr[20];
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    insert(arr, size);
    traverse(arr, size);
    remove(arr, size);
    return 0;
}