#include<iostream>
#include<string>

using namespace std;

class Node
{
	friend class List;
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

class List
{
private:
	Node* head;
	Node* tail;
	int count;
public:
	List();
	Node* getHead();
	Node* getTail();
	int getCount();
	bool isEmpty();
	void add(int data);
	void view();//view the list
	void removeDup(Node*);// Remove duplicates from a linked list O(n^2). Can be remade using hash map, then it becomes O(n)
	void kthToLast(int);// get the kth to last element (iterative)
	int nthToLast(Node*, int);// get the nth to last element (recursive)
	bool delNode(Node* );//delete given node from list
	List sumLists(List, List);// method to take the sum of two linked lists. the lists are stored in reverse order
};

//Node class implementation
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
void Node::setNext(Node* next)
{
	this->next = next;
}
void Node::setData(int data)
{
	this->data = data;
}
// end Node implementation

//List class Implementation*********
List::List()
{
	this->head = NULL;
	this->tail = NULL;
	this->count = 0;
}
Node* List::getHead()
{
	return this->head;
}
Node* List::getTail()
{
	return this->tail;
}
int List::getCount()
{
	return this->count;
}
bool List::isEmpty()
{
	return this->count == 0;
}
void List::add(int o)
{
	if(isEmpty())
		this->head = this->tail = new Node(o, this->tail);// or head same thing really, cause both are null
	else
	{
		//this->head = new Node(o, this->head);
		this->tail->next = new Node (o, this->tail->next);
		this->tail = this->tail->next;
	}
	count++;
}
void List::view()
{
	Node* current = this->head;
	if(current == NULL)// chose to do this rather than function call isEmpty
			cout<<"reached end of the list"<<endl;
	while(current != NULL)
	{
		cout<<current->getData()/*<<endl*/;
		current = current-> getNext();
		if(current == NULL)
			cout<<endl<<"reached end of the list"<<endl;
	}
}

void List::removeDup(Node* start)// Interview Question 2.1
{
	if(start == NULL) return;
	Node* current = start;
	Node* runner;
	Node* temp;

	while(current/*->next*/ != NULL)
	{
		runner = current;
		while(runner->next != NULL)
		{
			if(current->data == runner->next->data)
			{
				temp = runner->next;
				runner->next = runner->next->next;
				delete temp;
			}
			else
				runner = runner->next;
		}
		current = current->next;
	}
}



void List::kthToLast(int k)
{
	int size = 1;
	int i = 1;
	Node* current = this->head;
	while(current->next != NULL)
	{
		current = current->next;
		size++;
	}
	cout<<"size of list is: "<<size<<endl;
	current = this->head;
	while(i < (size - k + 1 ))
	{
		current = current->next;
		i++;
	}
	cout<<"the "<<k<<"th to last element is: "<<current->data<<endl;
}

int List::nthToLast(Node* c, int k)
{
	if(c == NULL)
		return 0;
	int i = nthToLast(c->next, k) + 1;
	if(i == k){
		cout<<c->data<<endl;
	}
	return i;
}

//delete a node without access to any other node in list
bool List::delNode(Node* n)
{
	if(n == NULL || n->next == NULL)
		return false;
	Node* temp = n->next;
	n->data = n->next->data;
	n->next = n->next->next;
	delete temp;
	return true;
}


//get the sum of two linked lists i.e 1-0-2  + 2-0-1  = 3-0-2
List List::sumLists(List num1, List num2)// only works for if the lists are in reverse, i.e 61 = 1->6->null
{
	Node* n1;
	Node* n2;
	int result = 0;
	List newList = List();
	int carry  = 0;
	int num;

	n1 = num1.getHead();
	n2 = num2.getHead();
	while(n1 != NULL && n2 != NULL)
	{
		num = n1->getData() + n2->getData() + carry;
		if(num >= 10)
		{
			result = (num - 10);
			carry = 1;
		}
		else
		{
			result = num;
			carry = 0;
		}
		
		if(n2->getNext() == NULL && n1->getNext() != NULL)
		{
			num2.add(0);
		}
		if(n1->getNext() == NULL && n2->getNext() != NULL)
		{
			num1.add(0);
		}
		n1 = n1->getNext();
		n2 = n2->getNext();
		//newList.add(result); 
		newList.head = new Node (result, newList.getHead());
	}
	newList.head = new Node (carry, newList.getHead());


	return newList;
}
int main()
{
	List myList = List();
	List myList2 = List();
	List result = List();

	myList.add(0);
	myList.add(9);
	myList.add(9);
	myList.add(1);
	myList.add(5);
	myList.add(7);

	myList2.add(1);
	myList2.add(4);
	myList2.add(3);
	myList2.add(5);
	
	

	

	myList.view();

	cout<<endl<<endl;

	myList2.view();

	cout<<"result: "<<endl<<endl;
	List res = result.sumLists(myList2, myList);

	res.view();



	system("pause");
	return 0;
}
