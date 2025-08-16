#include<iostream>
using namespace std;

// int main(){
//     int size;
//     cout<<"Enter the size of array (size-1): ";
//     cin>>size;

//     int arr[size-1];

//     //array input------------->
//     cout<<"Enter the array: "<<endl;
//     for(int i=0; i<size; i++){
//         cin>>arr[i];
//     }

//     //array output------------>
//     cout<<"Array is: "<<endl;
//     for(int i=0; i<size; i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;

//     int sum=0;
//     for(int i=0; i<size; i++){
//         sum+=arr[i];
//     }

//     int n=arr[size-1];
//     int nat_sum = (n*(n+1))/2;

//     cout<<"Missing Element is : "<<nat_sum-sum<<endl;

//     return 0;
// }


int main(){
    int size;
    cout<<"Enter the size of array : ";
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

    int xor1=0, xor2 =0, j, k;
    for(j=1; j<=size+1; j++)
        xor1^=j;

    for(k=0; k<size; k++)
        xor2^=arr[k];

    cout<<"Missing element is: "<<(xor1^xor2)<<endl;

    return 0;
}