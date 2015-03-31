/**
 * A simple implementation of stack using
 * integer Array of capacity 100
 */
#include <iostream>
using namespace std;
#define MAX 100

class stack {
    int element[MAX];
    int top=-1;
public:
    //returns true if top =-1 because there is no element in stack
    bool empty(){
        return top==-1;
    }
    //push an element into the stack
    void push(int data) {
        if ( top+1 == MAX) {
            cout << "Stack Overflow !\n";
            return;
        }
        element[++top] = data;
    }
    //return and pop top element from stack. if stack empty return -1.
    int pop(){
        if(empty()){
            cout << "Stack Underflow !\n";
            return -1;
        }
        return element[top--];
    }
    //return peek element of stack. if stack empty return -1.
    int peek() {
        if(empty()){
            cout << "Stack Underflow !\n";
            return -1;
        }
        return element[top];
    }
};

int main() {
    stack * s;  int num;
    s = new stack();
    for(int i=0; i<5; i++) {
        cout << "Enter "<<i+1<<" number : ";
        cin >> num;
        s->push(num);
    }
    //Printing stack elements
    cout << "\n Stack Elements Are : -- \n";
    while(!s->empty()) {
        cout << " " << s->pop();
    }
    return 0;
}
