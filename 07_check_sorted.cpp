#include<iostream>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    int arr[size];

    //array input------------->
    cout<<"Enter the array: "<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    //array output------------>
    cout<<"Array is: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]>arr[i+1]){
                cout<<"Array is not sorted"<<endl;
                return 0;
            }
        }
    }
    cout<<"Array is sorted"<<endl;
    return 0;
}