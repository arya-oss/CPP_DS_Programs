#include <iostream>
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
	LinkedList(){
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
struct lnode {
    int index;
    lnode * next;
    LinkedList<int> L;
};
class Graph {
    lnode * head;
    int vertexcount;
public:
    Graph() {
        head = NULL;
        vertexcount = 0;
    }
    void addVertex() {
        lnode * t= new lnode();
        t->index = vertexcount;
        t->next = NULL;
        if(!head)
            head = t;
        else{
            lnode * tmp=head;
            while(tmp->next)
                tmp = tmp->next;
            tmp->next = t;
        }
        ++vertexcount;
    }
    void addEdge(int src, int dest){
        lnode * tmp = head;
        while(tmp->index != src)
            tmp = tmp->next;
        tmp->L.push_back(dest);
    }
    void print(){
        lnode * tmp = head;
        while(tmp){
            cout<<"["<<tmp->index<<"] -> ";
            tmp->L.print();
            cout<<"\n";
            tmp = tmp->next;
        }
    }
};

int main() {
    Graph * g;
    g = new Graph();
    g->addVertex();
    g->addVertex();
    g->addVertex();
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 2);
    g->addEdge(2, 0);
    g->print();
    return 0;
}
