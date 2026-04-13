#include <iostream>
using namespace std;
#define MAX 5
class Queue {
private:
    int arr[MAX];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    bool isFull() {
        return (rear == MAX - 1);
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << value << " inserted\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[front] << " removed\n";
        front++;
    }
    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    q.enqueue(15);
    q.enqueue(25);
    q.enqueue(35);
    q.display();
    q.peek();
    q.dequeue();
    q.display();
    return 0;
}
