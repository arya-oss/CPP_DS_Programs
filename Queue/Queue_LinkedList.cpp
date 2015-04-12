#include <iostream>
#include <stdio.h>
using namespace std;

template<class T>
class LinkedList
{
	struct node
	{
		int data;
		node * prev, * next;
		node(){ prev = next = NULL; }
	};
	node * head;
	int size;
public:
	Queue(){ 
		size = 0;
		head = NULL;
	}
	void push_front(T data){
		node * t = new node();
		t->data = data;
		t->prev = t;
		if(!head)
			head = t;
		else{
			t->next = head;
			t->prev = head->prev;
			head->prev = t;
			head = t;
		}
		size++;
	}
	void push_back(T data){
		node * t = new node();
		t->data = data;
		t->prev = t;
		if(!head)
			head = t;
		else{
			head->prev->next = t;
			t->prev = head->prev;
			head->prev = t;
		}
		size++;
	}
	void pop_front(){
		if(empty())
			return;
		if(!head->next){
			head = NULL;
			--size;
			return;
		}
		head->next->prev = head->prev;
		head = head->next;
		--size;
	}
	void insert(T data, int pos){
		if(pos > size+1){
			cout<<"\nError ! pos greater than length !\n";
			return;
		}
		node * tmp = head;
		while(pos-- > 1)
			tmp = tmp->next;
		tmp->next
	}
	void pop_back(){
		if(empty())
			return;
		if(!head->next){
			head = NULL;
			--size;
			return;
		}
		head->prev->prev->next = head->prev->next;
		head->prev = head->prev->prev;
		--size;
	}
	
	T front(){
		if(!empty())
			return head->data;
	}
	
	T rear(){
		if(!empty())
			return head->prev->data;
	}
	
	bool empty(){
		return head == NULL;
	}

	void print(){
		while(head){
			cout<<" "<<head->data;
			head = head->next;
		}
	}
};
//Main Function
//Checking Class
int main(){
	LinkedList<int> * q;
	q = new LinkedList<int>();
	q->push_back(1);
	q->push_back(2);
	q->push_back(3);
	q->push_back(4);
	q->push_front(5);
	q->push_front(6);
	q->push_front(7);
	q->pop_front();
	q->pop_back();
	q->pop_front();
	q->pop_back();
	cout<<q->front();
	cout<<"\n"<<q->rear()<<"\n";
	q->print();
	getchar();
	return 0;
}