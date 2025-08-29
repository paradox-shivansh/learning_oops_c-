#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        //constructor
        Node(int data){
            this->data = data;   // Assigns the passed value to the object's data variable
            this->next = NULL;   // Initially, a node does not point anywhere
        }
};

int main(){

    cout<<"Hello World!"<<endl;

    Node* node1 = new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    return 0;
}