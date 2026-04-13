#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
class Queue {
private:
    char arr[MAX];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    void enqueue(char ch) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = ch;
    }
    char dequeue() {
        if (front == -1 || front > rear) {
            return '\0';
        }
        return arr[front++];
    }
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
};
int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;
    Queue q;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        q.enqueue(str[i]);
    }
    bool isPalindrome = true;
    for (int i = len - 1; i >= 0; i--) {
        char ch = q.dequeue();
        if (ch != str[i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << "Palindrome\n";
    else
        cout << "Not a Palindrome\n";

    return 0;
}
