#include<iostream>
#include<climits>
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

//     for(int i=0; i<size; i++){
//         for(int j=i+1; j<size; j++){
//             if(arr[j]<arr[i]){
//                 int temp=arr[i];
//                 arr[i]=arr[j];
//                 arr[j]=temp;
//             }
//         }
//     }
//     // cout<<"Sorted Array is: "<<endl;
//     // for(int i=0; i<size; i++){
//     //     cout<<arr[i]<<" ";
//     // }cout<<endl;

//     cout<<"Second Largest element is: "<<arr[size-2]<<endl;
//     return 0;
// }


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

    int max=INT_MIN;
    int s_max=INT_MIN;

    for(int i=0; i<size; i++){
        if(arr[i]>max){
            s_max=max;
            max=arr[i];
        }
        else if(arr[i]>s_max && arr[i]!=max){
            s_max=arr[i];
        }
    }

    cout<<"Largest element is : "<<max<<endl;
    if(s_max==INT_MIN)
        cout<<"There is no second largest element"<<endl;
    else
        cout<<"Second element is : "<<s_max<<endl;

    return 0;
}