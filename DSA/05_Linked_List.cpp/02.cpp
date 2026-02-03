#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtEnd(Node* &head, int val){
    Node* node = new Node(val);

    if(head == NULL){
        head = node;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = node;
    node->prev = temp;

}

void insertAtBeginning(Node* &head, int val){
    Node* node = new Node(val);
    if (head == NULL) {
        head = node;
        return;
    }
    node->next = head;
    head ->prev = node;
    head = node;
}

void printList(Node* head){

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

void insertAtPosition(Node* &head, int val, int pos){
    
}


 
int main()
{
    Node*  head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtBeginning(head, 10);
    printList(head);
    
}