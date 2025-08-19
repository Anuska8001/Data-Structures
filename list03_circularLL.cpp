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

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            this->next = NULL;
            delete next;
        }
        cout<<"Node freed: "<<value<<endl;
    }
};

void InsertAtHead(Node* &head){

    int data;
    cout<<"Enter data : ";
    cin>>data;
    Node* temp = new Node(data);

    if(!head){
        head = temp;
        head->next = head;
    }
    else{
        Node* temp2 = head;
        while(temp2->next != head){
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->next = head;
        head = temp;        
    }
}

void InsertAtTail(Node* &head){

    int data;
    cout<<"Enter data : ";
    cin>>data;
    Node* temp = new Node(data);

    if(!head){
        head = temp;
        head->next = head;
    }
    else{
        Node* temp2 = head;
        while(temp2->next != head){
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->next = head;
    }
}

int CalculateLength(Node* &head){
    int count = 1;
    Node* temp = head; 
    while(temp->next != head){
        temp = temp->next;
        count++;
    }
    return count;
}

void InsertAtPosition(Node* &head){
    int pos;
    cout<<"Enter position : ";
    cin>>pos;
    int len = CalculateLength(head);
    cout<<"Length is : "<<len<<endl;
    if(pos > len+1 || pos < 1){
        cout<<"Insertion not possible";
    }
    else if(pos == 1){
        InsertAtHead(head);
    }
    else if(pos == len+1){
        InsertAtTail(head);
    }
    else{
        int data;
        int cnt = 1;
        Node* t = head;
        cout<<"Enter data : ";
        cin>>data;
        Node* temp = new Node(data);
        while(cnt < pos-1){
            t = t->next;
            cnt++;
        }
        temp->next = t->next;
        t->next = temp;
    }
}
 
void Traverse(Node* &head){
    Node* temp = head;
    if(!head){
        cout<<"Empty List"<<endl;
        return;
    }
    while(temp->next != head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

void DeleteAtHead(Node* &head){
    if(!head){
        cout<<"List is empty... Deletion is not possible"<<endl;
    }
    else if(head->next == head){
        delete head;
        head = NULL;
    }
    else{
        Node* t = head;
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        t->next = NULL;
        delete t;
    }
}

void DeleteAtTail(Node* &head){
    if(!head){
        cout<<"List is empty... Deletion is not possible"<<endl;
    }
    else if(head->next == head){
        delete head;
        head = NULL;
    }
    else{
        Node* t1 = head;
        Node* t2 = head;
        while(t2->next != head){
            t1 = t2;
            t2 = t2->next;
        }
        t1->next = head;
        t2->next = NULL;
        delete t2;
    }
}

void DeleteAtPosition(Node* &head){
    if(!head){
        cout<<"Deletion not possible";
        return;
    }
    int pos;
    cout<<"Enter position : ";
    cin>>pos;
    int len = CalculateLength(head);
    cout<<"Length is : "<<len<<endl;
    if(pos > len+1 || pos < 1){
        cout<<"Deletion not possible";
    }
    else if(pos == 1){
        DeleteAtHead(head);
    }
    else if(pos == len){
        DeleteAtTail(head);
    }    
    else{
        int cnt = 1;
        Node* t1 = head;
        Node* t2 = head;
        while(cnt < pos){
            t1 = t2;
            t2 = t2->next;
            cnt++;
        }
        t1->next = t2->next;
        t2->next = NULL;
        delete t2;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int choice;

    do{
        cout<<"\n................Circular Linked List................\n"<<
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

            // case 8:
            // exit(0);

            default:
            cout<<"Invalid Choice";
        }
    }while(true);

    return 0;
}
