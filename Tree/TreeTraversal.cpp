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

void preorder(bptr T) {
    if(!T) return;
    cout << " " << T->data;
    preorder(T->left);
    preorder(T->right);
}

void inorder(bptr T) {
    if(!T) return;
    inorder(T->left);
    cout << " " << T->data;
    inorder(T->right);
}

void postorder(bptr T) {
    if(!T) return;
    postorder(T->left);
    postorder(T->right);
    cout << " " << T->data;
}

int height(bptr T) {
    if(!T) return -1;
    return 1+min(height(T->left), height(T->right));
}
void level(bptr T, int lev) {
    if(!T) return;
    if(lev == 0){
        cout << " " << T->data;
    } else {
        level(T->left, lev-1);
        level(T->right, lev-1);
    }
}
void levelorder(bptr T) {
    int h = height(T);
    for(int i=0; i<=h; i++) {
        level(T, i);
    }
}

int main () {
    bptr root=NULL;
    root=new bnode(4);
    root->left=new bnode(2);
    root->left->left = new bnode(1);
    root->left->right = new bnode(3);
    root->right = new bnode(6);
    root->right->left = new bnode(5);
    root->right->right = new bnode(7);
    cout<< "\nInorder Traversal : ";
    inorder(root);
    cout<< "\nInorder Traversal : ";
    inorder(root);
    cout<< "\npreorder Traversal : ";
    preorder(root);
    cout<< "\npostorder Traversal : ";
    postorder(root);
    cout<< "\nLevel oreder Traversal : ";
    levelorder(root);
    cout<< "\n\n";
    return 0;
}
