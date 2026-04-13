#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Queue {
private:
    Node* rear;
public:
    Queue() {
        rear = NULL;
    }
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (rear == NULL){
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " inserted\n";
    }
    void dequeue() {
        if (rear == NULL) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = rear->next;
        if (rear == temp) {
            cout << temp->data << " removed\n";
            delete temp;
            rear = NULL;
        } else {
            cout << temp->data << " removed\n";
            rear->next = temp->next;
            delete temp;
        }
    }
    void display() {
        if (rear == NULL) {
            cout << "Queue is Empty\n";
            return;
        }
        Node* temp = rear->next; 
        cout << "Queue elements: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << endl;
    }
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
