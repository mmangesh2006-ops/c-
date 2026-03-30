#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
void deleteAtBeginning(Node*& head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
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
    Node* n1 = new Node{10, NULL, NULL};
    Node* n2 = new Node{20, n1, NULL};
    Node* n3 = new Node{30, n2, NULL};
    n1->next = n2;
    n2->next = n3;
    head = n1;
    display(head);
    deleteAtBeginning(head);
    display(head);
    return 0;
}
