/**
 * This program implements stack using linked list
 * this code is Generic stack
 */
#include <iostream>
using namespace std;
template<class T>
class stack {
    struct node{
        T data;
        node * next;
        node(T data){
            this->data = data;
            this->next = NULL;
        }
    };
    node * head;
public:
    stack(){ head = NULL; }
    // if head is null then stack is empty
    bool empty(){
        return head == NULL;
    }
    // removes top element, if stack is empty return -1
    T pop(){
        if(empty()){
            cout << "\nStack Underflow !\n";
            return '\0';
        }
        int tmp = head->data;
        head = head->next;
        return tmp;
    }
    // if stack is empty return -1
    T peek(){
        if(empty()){
            cout << "\nStack Underflow !\n";
            return '\0';
        }
        return head->data;
    }
    // push an element in top of stack
    void push(T data){
        node * tmp;
        tmp = new node(data);
        if(!head){
            head = tmp;
        } else {
            tmp->next = head;
            head = tmp;
        }
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
    cout << "\n Stack Elements Are : - \n";
    while(!s->empty()) {
        cout << " " << s->pop();
    }
    return 0;
}
