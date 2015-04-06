#include <iostream>
using namespace std;

typedef struct bnode {
    int data;
    bnode * left, * right;
    bnode(int data){
        this->data = data;
        this->left = this->right = '\0';
    }
}* bptr;

void insert( bptr & T, int data) {
    if(!T){
        T = new bnode(data);
        return;
    }
    if (T->data > data)
        insert(T->left, data);
    else if (T->data < data)
        insert(T->right, data);
}

void print(bptr T) {
    if(!T) return;
    print(T->left);
    cout << " " << T->data;
    print(T->right);
}

int main () {
    bptr root=NULL;
    insert(root, 9);
    insert(root, 5);
    insert(root, 15);
    insert(root, 6);
    insert(root, 12);
    insert(root, 10);
    insert(root, 2);
    print(root);
    return 0;
}
