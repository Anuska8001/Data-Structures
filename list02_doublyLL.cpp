#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->prev != NULL && this->next != NULL){
            this->prev = NULL;
            this->next = NULL;
            delete next;
        }
        cout<<"Node freed: "<<value<<endl;
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

void InsertAtHead(Node* &head, Node* &tail){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    Node* temp = new Node(data);

    if(!head){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void InsertAtTail(Node* &head, Node* &tail){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    Node* temp = new Node(data);

    if(!head){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }    
}

void InsertAtPosition(Node* &head, Node* &tail){
    int len = CalculateLength(head);
    int pos, data, cnt=1;
    cout<<"Enter position: ";
    cin>>pos;

    if(pos>len+1 || pos<1){
        cout<<"Insertion is not possible";
        return;
    }

    if(pos==1){
        InsertAtHead(head, tail);
        return;
    }

    if(pos==len+1){
        InsertAtTail(head, tail);
        return;
    }

    cout<<"Enter data: ";
    cin>>data;
    Node* newNode = new Node(data);
    Node* temp=head;

    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    Node* temp2 = temp->next;
    temp2->prev = newNode;
    newNode->next = temp2;
    temp->next = newNode;
    newNode->prev = temp;
}

void Traverse(Node* &head, Node* &tail){
    Node* temp = head;
    if(!head && !tail){
        cout<<"Empty List"<<endl;
        return;
    }
    if (head == tail){
        cout<<head->data<<endl;
        cout<<"Head: "<<head->data<<endl;
        cout<<"Tail: "<<tail->data<<endl;
        return;
    }    
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
        cout<<endl;
        cout<<"Head: "<<head->data<<endl;
        cout<<"Tail: "<<tail->data<<endl;
}

void DeleteAtHead(Node* &head){
    if(!head){
        cout<<"List is empty...No deletion possible"<<endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void DeleteAtTail(Node* &tail){
    if(!tail){
        cout<<"Deletion is not possible"<<endl;
        return;
    }
    Node* temp = tail;
    temp->prev->next = NULL;
    tail = temp->prev;
    delete temp;
}

void DeleteAtPosition(Node* &head, Node* &tail){
    int len = CalculateLength(head);
    int pos;
    cout<<"Enter position: ";
    cin>>pos;
    if(pos<1 || pos>len+1){
        cout<<"Deletion is not possible..."<<endl;
        return;
    }
    if(pos == 1){
        DeleteAtHead(head);
        return;
    }
    if(pos == len){
        DeleteAtTail(tail);
        return;
    }
    int cnt = 1;
    Node* temp = head;
    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }
    Node* t1 = temp->next;
    temp->next = t1->next;
    t1->next->prev = t1->prev;
    delete t1;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int choice;

    do{
        cout<<"\n................Doubly Linked List................\n"<<
                "1. Insert at Head\n"<<
                "2. Insert at Tail\n"<<
                "3. Insert at position\n"<<
                "4. Traverse\n"<<
                "5. Delete at Head\n"<<
                "6. Delete at Tail\n"<<
                "7. Delete at Position\n"<<
                "8. Exit"<<endl;

        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice){

            case 1:
            InsertAtHead(head, tail);
            break;

            case 2:
            InsertAtTail(head, tail);
            break;

            case 3:
            InsertAtPosition(head, tail);
            break;

            case 4:
            Traverse(head, tail);
            break;

            case 5:
            DeleteAtHead(head);
            break;

            case 6:
            DeleteAtTail(tail);
            break;

            case 7:
            DeleteAtPosition(head, tail);
            break;

            case 8:
            exit(0);

            default:
            cout<<"Invalid Choice";
        }
    }while(true);

    return 0;
}

