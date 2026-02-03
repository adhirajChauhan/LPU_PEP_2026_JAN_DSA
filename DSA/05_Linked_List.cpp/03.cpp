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
        head -> next = head;
        return;
    }

    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = node;
    node->next = head;
}

void insertAtBeg(Node* &head, int val){
    Node* node = new Node(val);
    if(head == NULL){
        head = node;
        head->next = head;
        return;
    }

    Node* temp= head;

    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = node;
    node->next = head;
    head = node;
}

void printList(Node* head){
    Node* temp = head;
    do{
        cout << temp->data << " -> ";
        temp = temp->next;
    } while(temp!=head);
    
}
 
int main()
{
 Node* head = NULL;

 insertAtBeg(head, 1);
 insertAtEnd(head, 2);
 insertAtEnd(head, 3);
 insertAtEnd(head, 4);

 printList(head);

}