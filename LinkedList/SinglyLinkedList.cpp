#include <iostream>

using namespace std;

 typedef struct node {
    int data;
    node * next;
    node(int data){
        this->data = data;
        next = NULL;
    }
}* nptr;



int main() {
    nptr * root = NULL;

    return 0;
}
