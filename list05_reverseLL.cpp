#include<iostream>
#include<stack>
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

/*
void ReverseIterative(Node* &head){

    if(!head){
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
*/

void ReverseStack(Node* &head){
    if(!head){
        return;
    }
    stack<Node*>s;
    Node* temp = head;
    while(temp){
        s.push(temp);
        temp = temp->next;
    }
    head = s.top();
    s.pop();
    temp = head;

    while(!s.empty()){
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

void Traverse(Node* &head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
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

    cout<<"Reversed Linked List is : "<<endl;

    // ReverseIterative(head);

    ReverseStack(head);
    
    Traverse(head);
      
    return 0;
}