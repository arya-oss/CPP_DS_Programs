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
void inorder(bptr T){
	if(!T) return;
	inorder(T->left);
	cout<<" "<<T->data;
	inorder(T->right);
}
int height(bptr root){
	if(!root) return 0;
	return 1+max(height(root->left), height(root->right));
}
void levelorder(bptr T, int lev){
	if(!T) return;
	if(lev == 0)
		cout<<" "<<T->data;
	else{
		levelorder(T->left, lev-1);
		levelorder(T->right, lev-1);
	}
}
int getIndex(string str, int st,int end, char ch){
	for (int i = st; i <= end; ++i)
		if(str[i] == ch)
			return i;
	return 0;
}
bptr create(string in, string pre, int start, int end){
	static int i=0;
	bptr t=NULL;
	if(end < start)
		return t;
	//cout<<"Hello\n";
	t = new node(pre[i]);
	int mid = getIndex(in, start, end, pre[i++]);
	t->left = create(in, pre, start, mid-1);
	t->right = create(in, pre, mid+1, end);
	return t;
}

int main(){
	bptr root = NULL;
	string in="1234567";
	string pre="4213657";
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
	root=create(in,pre,0, len-1);
	inorder(root);
	int k = height(root);
	for (int i = 0; i < k; ++i)
	{
		cout<<"\n";
		levelorder(root, i);
	}
	return 0;
}