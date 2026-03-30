#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* head = NULL;
void insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteAtPosition(int pos) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    if (pos == 1) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
        return;
    }
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        delete temp;
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    cout << "Before deletion:\n";
    display();
    deleteAtPosition(3);
    cout << "After deletion (position 3):\n";
    display();
    return 0;
}
