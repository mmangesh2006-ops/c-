#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return NULL;
    }
    if (head->next == head) {
        delete head;
        return NULL;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    delete temp;
    return head;
}
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)\n";
}
int main() {
    Node* head = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};
    head->next = second;
    second->next = third;
    third->next = head;
    cout << "Original List:\n";
    display(head);
    head = deleteAtEnd(head);
    cout << "After Deletion at End:\n";
    display(head);
    return 0;
}
