#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
void insertAtPosition(int value, int pos) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == NULL) {
        if (pos != 1) {
            cout << "Invalid position\n";
            return;
        }
        newNode->next = newNode;
        head = newNode;
        return;
    }
    if (pos == 1) {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;

        if (temp->next == head) {
            cout << "Invalid position\n";
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
}
int main() {
    insertAtPosition(10, 1);
    insertAtPosition(20, 2);
    insertAtPosition(30, 3);
    insertAtPosition(25, 3);

    display();

    return 0;
}
