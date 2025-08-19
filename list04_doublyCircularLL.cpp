#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL && this->prev != NULL){
            this->next = NULL;
            this->prev = NULL;
            delete next;
        }
        cout<<"Node freed: "<<value<<endl;
    }
};

void InsertAtHead(Node* &head){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    Node* temp = new Node(data);
    if(!head){
        head = temp;
        head->next = head;
        head->prev = head;
    }
    else{
        Node* t1 = head;
        while(t1->next != head){
            t1 = t1->next;
        }
        temp->prev = t1;   
        temp->next = head;
        t1->next = temp;
        head->prev = temp; 
        head = temp;
    }
}

void InsertAtTail(Node* &head){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    Node* temp = new Node(data);
    if(!head){
        head = temp;
        head->next = head;
        head->prev = head;
    }
    else{
        Node* t1 = head;
        while(t1->next != head){
            t1 = t1->next;
        }
        temp->prev = t1;
        t1->next = temp;
        temp->next = head;
        head->prev = temp;
    }
}

int CalculateLength(Node* &head){
    int cnt = 1;
    Node* temp = head;
    while(temp->next != head){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void InsertAtPosition(Node* &head){
    int len = CalculateLength(head);
    int pos;
    cout<<"Enter position: ";
    cin>>pos;
    if(pos<1 || pos>len+1){
        cout<<"Insertion not possible"<<endl;
    }
    else if(pos == 1){
        InsertAtHead(head);
    }
    else if(pos == len+1){
        InsertAtTail(head);
    }
    else{
        int cnt = 1;
        int data;
        cout<<"Enter data: ";
        cin>>data;
        Node* temp = new Node(data);
        Node* t1 = head;
        while(cnt < pos-1){
            t1 = t1->next;
            cnt++;
        }
        t1->next->prev = temp;
        temp->next = t1->next;
        t1->next = temp;
        temp->prev = t1;
    }
}

void Traverse(Node* &head){
    if(!head){
        cout<<"Empty List"<<endl;
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

void DeleteAtHead(Node* &head){
    if(!head){
        cout<<"Empty List...Deletion not possible";
    }
    else{
        Node* temp = head;
        Node* t1 = head;
        while(t1->next != head){
            t1 = t1->next;
        }
        temp->next->prev = t1;
        t1->next = temp->next;
        head = temp->next;
        delete temp;
    }
}

void DeleteAtTail(Node* &head){
    if(!head){
        cout<<"Empty List...Deletion not possible";
    }
    else{
        Node* temp = head;
        Node* t1 = head;
        while(temp->next != head){
            t1 = temp;
            temp = temp->next;
        }
        head->prev = t1;
        t1->next = head;
        delete temp;
    }
}

void DeleteAtPosition(Node* &head){
    int len = CalculateLength(head);
    int pos;
    cout<<"Enter position: ";
    cin>>pos;
    if(pos<1 || pos>len+1){
        cout<<"Deletion not possible"<<endl;
    }
    else if(pos == 1){
        DeleteAtHead(head);
    }
    else if(pos == len){
        DeleteAtTail(head);
    }
    else{
        int cnt = 1;
        Node* temp = head;
        while(cnt < pos-1){
            temp = temp->next;
            cnt++;
        }
        Node* t1 = temp->next;
        temp->next = t1->next;
        t1->next->prev = temp;
        delete t1;
    }
}

int main(){
    Node* head = NULL;

    int choice;

    do{
        cout<<"\n................Doubly Circular Linked List................\n"<<
                "1. Insert at Head\n"<<
                "2. Insert at Tail\n"<<
                "3. Insert at position\n"<<
                "4. Traverse\n"<<
                "5. Delete at Head\n"<<
                "6. Delete at Tail\n"<<
                "7. Delete at Position\n"<<
                "8. Exit"<<
                endl;

        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice){

            case 1:
            InsertAtHead(head);
            break;

            case 2:
            InsertAtTail(head);
            break;

            case 3:
            InsertAtPosition(head);
            break;

            case 4:
            Traverse(head);
            break;

            case 5:
            DeleteAtHead(head);
            break;

            case 6:
            DeleteAtTail(head);
            break;

            case 7:
            DeleteAtPosition(head);
            break;

            case 8:
            exit(0);

            default:
            cout<<"Invalid Choice";
        }
    }while(true);

    return 0;
}
