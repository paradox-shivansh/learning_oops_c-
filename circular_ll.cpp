#include<iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {   
        cout << "Memory freed for node with data " << this->data << endl;
    }
};

// Insert a new node after a given element
void insertNode(Node* &tail, int element, int d) {
    // Empty list
    if (tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode; // circular link
    } 
    else {
        Node* curr = tail;
        // Find the element
        while (curr->data != element) {
            curr = curr->next;
        }
        // Insert after curr
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

int main() {
    cout << "hello world" << endl;

    Node* tail = NULL;

    insertNode(tail, 0, 10);  // first node
    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    insertNode(tail, 10, 15); // insert after 10

    print(tail);

    return 0;
}
