#include<iostream>
using namespace std;

// int main(){
//     int arr[20];
//     int size;
//     cout<<"Enter size of array: ";
//     cin>>size;
//     for(int i=0; i<size; i++){
//     cout<<"Enter "<<i<<"th element of Array: ";
//     cin>>arr[i];
//     }
//     int max=arr[0];
//     for(int i=0; i<size; i++){
//         if(arr[i]>max)
//             max=arr[i];
//     }
//     cout<<"Array is: "<<endl;
//     for(int i=0; i<size; i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;
//     cout<<"Largest element is: "<<max<<endl;
//     return 0;
// }


// using sorting method------------------>

int main(){
    int arr[20];
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    for(int i=0; i<size; i++){
    cout<<"Enter "<<i<<"th element of Array: ";
    cin>>arr[i];
    }
    int max=arr[0];
    for(int i=0; i<size; i++){
        if(arr[i]>max)
            max=arr[i];
    }
    cout<<"Array is: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    // cout<<"Sorted Array is: "<<endl;
    // for(int i=0; i<size; i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;

    cout<<"Largest element is: "<<arr[size-1]<<endl;
    return 0;
}