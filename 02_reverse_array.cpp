#include<iostream>
using namespace std;

int main(){
    int arr[20];
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    for(int i=0; i<size; i++){
    cout<<"Enter "<<i<<"th element of Array: ";
    cin>>arr[i];
    }

    cout<<"Array is: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    for(int i=0, j=size-1; i<j; i++, j--){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    cout<<"Reversed Array is: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

}