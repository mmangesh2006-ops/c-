#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* deleteAtPosition(Node* head, int pos) {
    if (head == NULL) {
        cout << "List is empty\n";
        return NULL;
    }
    if (pos == 1) {
        if (head->next == head) {
            delete head;
            return NULL;
        }
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        Node* temp = head;
        last->next = head->next;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            cout << "Position out of range\n";
            return head;
        }
    }
    prev->next = temp->next;
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
    Node* fourth = new Node{40, NULL};
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;
    cout << "Original List:\n";
    display(head);
    int pos = 3;
    head = deleteAtPosition(head, pos);
    cout << "After Deletion at Position " << pos << ":\n";
    display(head);
    return 0;
}
