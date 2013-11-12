#include<iostream>
#include<string>
#include<iomanip>
#include<map>
#include<vector>

using namespace std;

class Node
{
	friend class List;
public:
	Node(int, Node*);
	Node* next;
	int data;
	bool visited;
};

Node::Node(int data, Node* next)
{
	this->next = next;
	this->data = data;
	this->visited = false;
}


class List
{
public:
	Node* head;
	Node* tail;
	int count;
	List();
	void Add(int);
	void view();
	bool isEmpty();
};

List::List()
{
	this->head = this->tail = NULL;
	this->count = 0;
}

bool List::isEmpty()
{
	return this->count == 0;
}

void List::Add(int o)
{
	if(isEmpty())
		this->head = this->tail = new Node(o, this->tail);
	else
	{//append to tail
		this->tail->next = new Node(o,this->tail->next );
		this->tail = this->tail->next;
	}
	this->count++;
}

void List::view()
{
	Node* current = this->head;
	if(current == NULL)// chose to do this rather than function call isEmpty
			cout<<"reached end of the list"<<endl;
	while(current != NULL)
	{
		cout<<current->data/*<<endl*/;
		current = current->next;
		if(current == NULL)
			cout<<endl<<"reached end of the list"<<endl;
	}
}

//check for cycle
bool checkCycle(Node* n)
{
	Node* current = n;
	while(current != NULL)
	{
		if(current->visited == true)
		{
			cout<<"there is a cycle"<<endl;
			return true;
		}
		else
		{
			current->visited = true;
			current = current->next;
		}
	}
	cout<<"no loop in list"<<endl;
	return false;
}
bool checkForDuplicates(Node* n)
{
	map <int, bool> myMap;
	Node* current = n;

	while(current->next != NULL)
	{
		if(myMap[current->data] == true )
		{
			cout<<"duplicate found: "<<current->data<<endl;
			return true;
		}
		else
		{
			myMap[current->data] = true;
			current = current->next;
		}
	}
	cout<<"No duplicates found"<<endl;
	return false;
}

int main()
{
	List myList = List();
	List myList2 = List();
	myList.Add(1);
	myList.Add(2);
	myList.Add(3);
	myList.Add(4);
	myList.Add(5);
	myList.Add(6);

	myList2.Add(1);
	myList2.Add(2);
	myList2.Add(3);
	myList2.Add(4);
	myList2.Add(5);
	myList2.Add(6);

	myList.tail->next = myList.head->next;

	checkForDuplicates(myList2.head);
	

	system("pause");
	return 0;
}
