#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int CalculateLength(Node* &head){
    int count = 1;
    Node* temp = head; 
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

void Insert(Node* &head){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    Node* newNode = new Node(data);
    if(!head){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void Traverse(Node* &head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

int MiddleElement(Node* &head){
    int len = CalculateLength(head);
    cout<<"Length is : "<<len<<endl;

    Node* temp = head;

    if(len%2 != 0){
        int mid = (len/2)+1;
        int cnt = 1;
        while(cnt != mid){
            cnt++;
            temp = temp->next;
        }
    cout<<"Middle of the Linked List is: "<<temp->data<<endl;
    }
    else{
        int mid = (len/2);
        int cnt = 1;
        while(cnt != mid){
            cnt++;
            temp = temp->next;
        }
    cout<<"Middle of the Linked List is: "<<temp->data<<" and "<<temp->next->data<<endl;
    }
}

int main(){
    Node* head = NULL;
    int k=1;
    do{
        Insert(head);
        cout<<"If want to insert, press 1 if not 0: ";
        cin>>k;
    }while(k!=0);

    cout<<endl<<"List is :"<<endl;
    Traverse(head);  
    
    MiddleElement(head);

    return 0;
}