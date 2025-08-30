#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next; // this means the next is a pointer which points to the next node

        //constructor
        Node(int data){
            this->data = data;   // Assigns the passed value to the object's data variable
            this->next = NULL;   // Initially, a node does not point anywhere
        } 

        //destructor
        ~Node(){   
            int value = this->data;
            //memory free
            if (this->next != NULL)
            {
                delete next;
                this->next = NULL;
            }
            cout << "memory is free for node with data " << value << endl;
         }
};

void insertAtHead(Node* &head, int d){
    //& refrence is taken to make changes in the original head pointer not in the copy of it    
    //new node create
    Node* temp = new Node(d);
    temp->next = head; // (*temp).next = head
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insert(Node* &head , int position , int d){
    Node* temp = head;
    int cnt = 1;

    if (position == 1) {
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = head;
    head = nodeToInsert;
    return;
    }

    if (temp->next == NULL) {
    Node* nodeToInsert = new Node(d);
    temp->next = nodeToInsert; // attach new node at end
    return;
    }


    

    while (cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    
} 

void print( Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
}

void deleteNode(Node* &head , int position){

    int cnt = 1;
    Node* temp = head;     // temp points to first node

    //deleting  first node ..
    if (position == 1)
    {
        head = head->next;     // head moves to second node (13)
        //memory free
        temp->next = NULL;     // disconnect the first node from the list
        delete temp;           // free memory of first node
        return;
    }

    while ( cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;    
    nodeToDelete->next = NULL;
    delete nodeToDelete;


    
    
}


int main(){

    cout<<"Hello World!"<<endl;

    Node* node1 = new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    Node* head = node1;
    Node* tail = node1;
    print(head);
    cout << endl;
    
    insertAtHead(head, 11);
    insertAtHead(head, 12);
    insertAtHead(head, 13);
    insertAtHead(head, 14);
    print(head);
    cout << endl;
    
    insertAtTail(tail, 9);
    print(head);
    cout << endl;
    
    insert(head, 3, 100);
    print(head);
    cout << endl;

    insert(head, 5, 103);
    print(head);
    cout << endl;

    // insert(head, 10, 105);
    print(head);
    cout << endl;

    deleteNode(head, 1);
    print(head);
    cout << endl;


    return 0;
}