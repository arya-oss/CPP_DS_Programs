#include <iostream>
#include <map>
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

void TopView(bptr root, map<int,int> & m, int value) {
    if(!root) return;
    m.insert(pair<int, int>(root->data, value));
    TopView(root->left, m, value-1);
    TopView(root->right, m, value+1);
}

int main () {
    bptr root=NULL;
    map<int,int> m;
    insert(root, 9);
    insert(root, 5);
    insert(root, 15);
    insert(root, 6);
    insert(root, 12);
    insert(root, 10);
    insert(root, 2);

    TopView(root, m, 0);
    map<int, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        cout << " " << it->first;
    }
    return 0;
}
