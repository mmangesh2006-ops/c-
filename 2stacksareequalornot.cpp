#include <iostream>
#include<stack>
using namespace std;
#define MAX 100
class Stack {
public:
    int arr[MAX];
    int top;

    Stack() {
        top = -1;
    }
    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Overflow\n";
            return;
        }
        arr[++top] = x;
    }
};
bool areEqual(Stack s1, Stack s2) {
    if (s1.top != s2.top)
        return false;

    for (int i = 0; i <= s1.top; i++) {
        if (s1.arr[i] != s2.arr[i])
            return false;
    }
    return true;
}
int main() {
    Stack s1, s2;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s2.push(10);
    s2.push(20);
    s2.push(30);
    if (areEqual(s1, s2))
        cout << "Stacks are Equal\n";
    else
        cout << "Stacks are Not Equal\n";
    return 0;
}
