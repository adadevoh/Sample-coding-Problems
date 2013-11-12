#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Node
{
	friend class Stack;
private:
	Node *next;
	int data;
public:
	Node(int, Node*);
	Node* getNext();
	int getData();
	void setNext(Node*);
	void setData(int);
};

class Stack//LIFO
{
public:
	Node* top;
	int size;
	Stack();
	int pop();
	void push(int);
	int peek();
};


Node::Node(int data, Node* next)
{
	this->data = data;
	this->next = next;
}
Node* Node::getNext()
{
	return this-> next;
}
int Node::getData()
{
	return this->data;
}

//Stack class implementation
Stack::Stack()
{
	this->top = NULL;
	this->size = 0;
}

void Stack::push(int o)
{
	this->top = new Node(o, this->top);//create new node, make it point to the last top node, then assign the new node to top
}
int Stack::pop()
{
	if(this->top == NULL)
	{
		cout<<"this list is empty"<<endl;
		return NULL;
	}
	Node* temp = this->top->next;
	int oldData = this->top->data;
	this->top->data = this->top->next->data;
	this->top->next = this->top->next->next;
	delete temp;

	return oldData;
}

int Stack::peek()
{
	if(this->top == NULL)
	{
		cout<<"this list is empty"<<endl;
		return NULL;
	}
	cout<<"this is the top of the stack: "<<this->top->data<<endl;
	return this->top->data;
}


int main()
{
	Stack myStack = Stack();
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.pop();

	myStack.peek();
	

	system("pause");
	return 0;
}
