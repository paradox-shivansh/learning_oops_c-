#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        //constructor
        Node(int data){
            this->data = data;   // ✅ fixed
            this->next = NULL;
            this->prev = NULL;
        }
};

// PRINTING THE LIST (outside class)
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int length(Node* head){
    Node* temp = head;
    int cnt =0;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    cout << "The length of the list is : "<< cnt << endl;
    
}

void insertAtHead(Node* &head , int d){
    Node* temp = new Node(d);
    temp->next = head;
    if (head != NULL)
    {
        head->prev = temp;
    }
    
    head = temp;
}

void insertAtTail(Node* &tail , int d){
    Node* temp = new Node(d);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail , int position , int d){
    // inserting at head
    if(position == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1 && temp->next != NULL){
        temp = temp->next;
        cnt++;
    }

    // inserting at tail
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }

    // inserting in middle
    Node* nodeTo = new Node(d);
    nodeTo->next = temp->next;
    nodeTo->prev = temp;
    temp->prev = nodeTo;
    temp->next = nodeTo;
}

void deletion(Node* &head, Node* &tail, int position){
    // deleting first or start node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }
    else{
        // deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(curr != NULL){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if(curr == NULL){
            cout << "Position is greater than the length of the list" << endl;
            return;
        }

        prev->next = curr->next;
        if(curr->next != NULL){
            curr->next->prev = prev;
        }
        else{
            // deleting last node
            tail = prev;
        }
        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
    }
}


int main(){
    cout << "Hello World" << endl;

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);  
    length(head);

    // cout<<endl;
    insertAtHead(head, 12);
    print(head);

    insertAtTail(tail, 14);
    print(head);

    insertAtPosition(head, tail, 2, 7);
    print(head);

    insertAtPosition(head, tail, 2, 15);
    print(head);
    insertAtPosition(head, tail, 1, 100);
    print(head);
    length(head);
    insertAtPosition(head, tail, 7, 200);
    print(head);
    length(head);
    return 0;
}
