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

    int brr[size]={0};
    int j=0;
    for(int i=j; i<size; i++){
        if(arr[i]!=0){
            brr[j++]=arr[i];
        }
    }

    cout<<"One sided zero Array is: "<<endl;
    for(int i=0; i<size; i++){
        cout<<brr[i]<<" ";
    }cout<<endl;

    return 0;
}