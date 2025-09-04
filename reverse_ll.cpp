#include<iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtHead(Node* &head , int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail , int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse(Node* &head ){

    Node* prev = NULL;
    Node* curr = head;
    Node* forward;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev= curr;
        curr= forward;
    }

    head = prev;
    print(head);


}

int main() {
    cout << "hello world" << endl;

    Node* node1= new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 12);
    insertAtHead(head, 15);

    print(head);

    reverse(head);

    return 0;
}   