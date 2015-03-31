/**
 * A simple implementation of stack using
 * Generic Array of capacity 100
 */
#include <iostream>
using namespace std;
#define MAX 100
template<class T>
class stack {
    T element[MAX];
    int top=-1;
public:
    //returns true if top =-1 because there is no element in stack
    bool empty(){
        return top==-1;
    }
    //push an element into the stack
    void push(T data) {
        if ( top+1 == MAX) {
            cout << "Stack Overflow !\n";
            return;
        }
        element[++top] = data;
    }
    //return and pop top element from stack. if stack empty return -1.
    T pop(){
        if(empty()){
            cout << "Stack Underflow !\n";
            return '\0';
        }
        return element[top--];
    }
    //return peek element of stack. if stack empty return -1.
    T peek() {
        if(empty()){
            cout << "Stack Underflow !\n";
            return '\0';
        }
        return element[top];
    }
};

int main() {
    stack<char> * s;  char ch;
    s = new stack<char>();
    for(int i=0; i<5; i++) {
        cout << "Enter "<<i+1<<" Character : ";
        cin >> ch;
        s->push(ch);
    }
    //Printing stack elements
    cout << "\n Stack Elements Are : -- \n";
    while(!s->empty()) {
        cout << " " << s->pop();
    }
    return 0;
}
