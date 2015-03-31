/**
 * This program implements stack using linked list
 * this code is integer stack
 */
#include <iostream>
using namespace std;
struct node{
    int data;
    node * next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class stack {
    node * head;
public:
    stack(){ head = NULL; }
    // if head is null then stack is empty
    bool empty(){
        return head == NULL;
    }
    // removes top element, if stack is empty return -1
    int pop(){
        if(empty()){
            cout << "\nStack Underflow !\n";
            return -1;
        }
        int tmp = head->data;
        head = head->next;
        return tmp;
    }
    // if stack is empty return -1
    int peek(){
        if(empty()){
            cout << "\nStack Underflow !\n";
            return -1;
        }
        return head->data;
    }
    // push an element in top of stack
    void push(int data){
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
    stack * s;  int num;
    s = new stack();
    for(int i=0; i<5; i++) {
        cout << "Enter "<<i+1<<" number : ";
        cin >> num;
        s->push(num);
    }
    //Printing stack elements
    cout << "\n Stack Elements Are : - \n";
    while(!s->empty()) {
        cout << " " << s->pop();
    }
    return 0;
}
