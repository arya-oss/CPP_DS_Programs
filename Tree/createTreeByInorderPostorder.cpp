#include <iostream>
#include <string>
using namespace std;
typedef struct node{
	char data;
	node * left, * right;
	node(){
		left = right = NULL;
	}
	node(int data){
		this->data = data;
		left = right = NULL;
	}
}* bptr;
/* insert function for BST */
void insert(bptr & T, int data){
	if(!T){
		T = new node(data);
		return;
	}
	if(T->data > data)
		insert(T->left, data);
	else if(T->data < data)
		insert(T->right, data);
}
/* function for printing inorder */
void inorder(bptr T){
	if(!T) return;
	inorder(T->left);
	cout<<" "<<T->data;
	inorder(T->right);
}
/* function for calculating height */
int height(bptr root){
	if(!root) return 0;
	return 1+max(height(root->left), height(root->right));
}
/* function for printing node at level => lev */
void levelorder(bptr T, int lev){
	if(!T) return;
	if(lev == 0)
		cout<<" "<<T->data;
	else{
		levelorder(T->left, lev-1);
		levelorder(T->right, lev-1);
	}
}
/* function seacrches a char into given inorder string */
int getIndex(string str, int st,int end, char ch){
	for (int i = st; i <= end; ++i)
		if(str[i] == ch)
			return i;
	return 0;
}

/* main recursive function that creates tree from given inorder and postorder */
bptr createPost(string in, string post, int start, int end){
	static int i=in.length()-1;
	bptr t=NULL;
	if(end < start)
		return t;
	//cout<<"Hello\n";
	t = new node(post[i]);
	int mid = getIndex(in, start, end, post[i--]);
	t->right = createPost(in, post, mid+1, end);
	t->left = createPost(in, post, start, mid-1);
	return t;
}
// Main function
int main(){
	bptr root = NULL;
	/* Give valid inorder and postorder for creating a tree */
	string in="1234567";
	string post="1325764";

	int len = in.length();
	/*
	insert(root, '4');
	insert(root, '2');
	insert(root, '1');
	insert(root, '3');
	insert(root, '6');
	insert(root, '5');
	insert(root, '7');
	*/
	root = createPost(in, post, 0, len-1);
	/* printing inorder */
	inorder(root);
	/* Printing Level Order */
	int k = height(root);
	for (int i = 0; i < k; ++i)
	{
		cout<<"\n";
		levelorder(root, i);
	}
	return 0;
}