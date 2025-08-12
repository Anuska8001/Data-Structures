#include<iostream>
#include<unordered_map>
using namespace std;


/*
brute force---------------------->

int main(){

    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    int arr[size];
    int visited[size] = {false};

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

    //counting---------->
    for(int i=0; i<size; i++){
        if(visited[i]==true)
            continue;
        int count=1;
        for(int j=i+1; j<size; j++){
            if(arr[i]==arr[j]){
                count++;
                visited[j]=true;
            }
        }
        cout<<"Frequency of "<<arr[i]<<" --> "<<count<<endl;
    }

    return 0;
}
*/

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

    unordered_map<int, int>freq;  //store key(element) and value(frequency)

    for(int i=0; i<size; i++){
        freq[arr[i]]++;
    }
    cout<<"Frequency of each element is: "<<endl;
    for(auto it:freq){
        cout<<it.first<<" --> "<<it.second<<endl;
    }
    return 0;
}