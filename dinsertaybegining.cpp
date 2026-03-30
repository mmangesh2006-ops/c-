#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main() {
    Node* head = NULL;
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);
    display(head);
    return 0;
}
