#include <iostream>
#include <map>
#include <list>

using namespace std;

typedef struct bnode {
    int data;
    bnode * left, * right;
    bnode(int data){
        this->data = data;
        this->left = this->right = NULL;
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

void VerticalOrder(bptr root, map<int,list<int> > & m, int value) {
    if(!root) return;
    map<int, list<int> >::iterator it = m.find(value);
    if (it == m.end()) {
        list<int> l;
        l.push_back(root->data);
        m.insert(pair<int, list<int> >(value, l));
    } else {
        it->second.push_back(root->data);
    }
    VerticalOrder(root->left, m, value-1);
    VerticalOrder(root->right, m, value+1);
}
/*
 *               9
 *             /  \
 *            5    15
 *          /  \  / 
 *         2    6 12  
 *               /
 *              10
 *
 *  Vertical Order:
 *  2
 *  5 10
 *  9 6 12
 *  15
 */
int main () {
    bptr root=NULL;
    map<int, list<int> > m;
    insert(root, 9);
    insert(root, 5);
    insert(root, 15);
    insert(root, 6);
    insert(root, 12);
    insert(root, 10);
    insert(root, 2);

    VerticalOrder(root, m, 0);

    cout << "Vertical Order from left to right \n\n";
    for(map<int, list<int> >::iterator it = m.begin(); it != m.end(); it++) {
        for (list<int>::iterator lit = it->second.begin(); lit != it->second.end(); ++lit) {
            cout << *lit << " ";
        }
        cout << "\n";
    }
    return 0;
}
