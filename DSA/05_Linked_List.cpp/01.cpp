#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
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
}

void insertAtBeg(Node* &head, int val){
    Node* node = new Node(val);
    node->next = head;
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

void insertAtPosition(Node* &head, int pos, int val){
    Node* node = new Node(val);

    if(pos == 1){
        node->next = head;
        head = node;
        return;
    }

    Node* temp = head;
    for(int i = 1; i < pos - 1 && temp  != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }

    node->next = temp->next;
    temp->next = node;
}

void deleteAtEnd(Node* &head){

    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }
    
    delete temp->next;
    temp->next = NULL;
}

void deleteAtBeg(Node* &head){
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}
 
int main()
{
    Node* head = NULL;
    insertAtEnd(head, 2);
    insertAtEnd(head,3);
    insertAtEnd(head, 4);
    insertAtBeg(head, 1);
    insertAtPosition(head, 10,100);

    printList(head);
    
}