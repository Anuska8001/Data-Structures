#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;
    int len = 0;

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
    int d;
    cout<<"Enter data: ";
    cin>>d;
    Node* temp = new Node(d);
    if (head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

void InsertAtTail(Node* &head, Node* &tail){
    int d;
    cout<<"Enter data: ";
    cin>>d;
    Node* temp = new Node(d);

    if (tail == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

void InsertAtPosition(Node* &head, Node* &tail){
    Node* temp = head;
    int cnt = 1;
    int d, pos;
    cout<<"Enter position: ";
    cin>>pos;
    int len = CalculateLength(head);
    cout<<"Length is : "<<len<<endl;

    if(pos > len+1 || pos < 1){
        cout<<"Insertion not possible";
    }

    else if (pos == 1){
        InsertAtHead(head, tail);
    }

    else if (pos == len+1){
        InsertAtTail(head, tail);
    }

    else{
        cout<<"Enter data: ";
        cin>>d;
        while(cnt < pos-1){
            temp = temp->next;
            cnt++;
        }
        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    } 
}

void Traverse(Node* &head, Node* &tail){
    Node* temp = head;
    if (!head && !tail){
        cout<<"Empty List"<<endl;
        return;
    }
    if (head == tail){
        cout<<head->data<<endl;
        cout<<"Head: "<<head->data<<endl;
        cout<<"Tail: "<<tail->data<<endl;
        return;
    }
    
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
        cout<<"Head: "<<head->data<<endl;
        cout<<"Tail: "<<tail->data<<endl;
    
}

void DeleteAtHead(Node* &head, Node* &tail){
    if (!head){
        cout<<"Deletion not Possible"<<endl;
        return;
    }
    if (head == tail){
        cout<<"Node freed: "<<head->data<<endl;
        head = NULL;
        tail = NULL;
        delete(head);
    }
    else{
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete(temp);
    }
}

// void DeleteAtTail(Node* &head){                                   it will not update tail
//     Node* temp = head;
//     Node* prev = head;
//     while(temp->next != NULL){
//         prev = temp;
//         temp = temp->next;
//     }
//     prev->next = NULL;
//     temp->next = NULL;
//     delete(temp);
// }          

void DeleteAtTail(Node* &head, Node* &tail){
    Node* temp = head;
    Node* prev = head;

    if (!head){
        cout<<"Deletion not Possible"<<endl;
        return;
    }

    if (head == tail){
        cout<<"Node freed: "<<head->data<<endl;
        head = NULL;
        tail = NULL;
        delete(head);
    }
    else{
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        temp->next = NULL;
        delete(temp);
        tail = prev;
    }
}

void DeleteAtPosition(Node* &head, Node* &tail){
    if(!head){
        cout<<"List is empty... Deletion not possible";
        return;
    }
    int d, pos;
    cout<<"Enter position: ";
    cin>>pos;
    int len = CalculateLength(head);
    cout<<"Length is : "<<len<<endl;

    if(pos > len+1 || pos < 1){
        cout<<"Deletion not possible";
    }

    else if (pos == 1){
        DeleteAtHead(head, tail);
    }

    else if (pos == len){
        DeleteAtTail(head, tail);
    }

    else{
        Node* temp = head;
        Node* prev = head;
        int cnt = 1;

        while(cnt < pos){
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        prev->next = temp->next;
        temp->next = NULL;
        delete(temp);
    }
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // InsertAtHead(head, tail);
    // Traverse(head);

    // InsertAtHead(head, tail);
    // Traverse(head);

    // InsertAtTail(head, tail);
    // Traverse(head);
    
    // InsertAtTail(head, tail);
    // Traverse(head);

    // InsertAtPosition(head);
    // Traverse(head);

    // InsertAtPosition(head);
    // Traverse(head);

    int choice, len=0;

    do{
        cout<<"\n................Singly Linked List................\n"<<
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
            DeleteAtHead(head, tail);
            break;

            case 6:
            DeleteAtTail(head, tail);
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
