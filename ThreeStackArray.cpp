#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<map>

using namespace std;

class stack
{
public:
	int* stackPtr[3];
	int *buffer;
	int stackSize;
	
	stack(int size)
	{
		this->stackSize = size;
		buffer = new int [size *3];
		stackPtr[0] = NULL;
		stackPtr[1] = NULL;
		stackPtr[2] = NULL;

		
	}
	bool isEmpty(int stackNum)
	{
		return this->stackPtr[stackNum] == NULL;
	}
	void push(int stackNum, int data)
	{
		int loc;
		if(isEmpty(stackNum))
		{
			loc = ((stackNum+1)*stackSize) - 1;
			stackPtr[stackNum] = &buffer[loc];
			*stackPtr[stackNum] = data;
		}
		else
		{
			--stackPtr[stackNum];
			if(stackPtr[stackNum] < &buffer[stackSize*stackNum] )//if stack[1] < buffer[100] then it is full and is entering stack [0]
			{
				cout<<"Stack is out of space"<<endl;
				++stackPtr[stackNum];
			}
			else
			{
				*stackPtr[stackNum] = data;
			}			
		}
	}

	void peek(int stackNum)//either empty or full. No need to check if it is full, just print the top element
	{
		if(isEmpty(stackNum))
			cout<<"this stack is empty"<<endl;
		else
			cout<<"top of stack: "<<*stackPtr[stackNum]<<endl;
	}

	int pop(int stackNum)
	{
		int value;
		if(isEmpty(stackNum))
			cout<<"this stack is empty"<<endl;
		else
		{
			value = *stackPtr[stackNum];
			*stackPtr[stackNum]= 0;
			++stackPtr[stackNum];
		}
		return value;
	}
};


int main()
{
	stack myStack = stack(3);
	
	myStack.push(1, 8);
	myStack.push(1, 5);
	myStack.push(1, 3);
	myStack.push(1, 2);

	myStack.peek(1);
	cout<<"popped "<<myStack.pop(1)<<endl;
	myStack.peek(1);





	
	system("pause");
	return 0;
}
