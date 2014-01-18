
#include<iostream>
#include<string>

using namespace std;

//Typically I'd have these class definitions in a seperate file but for simplicities sake I just wrote it all in one file
class Node{
	friend class C_Buffer;
    public:
    Node( string d): data(d), next(0){
    }
    private:
    Node* next;
    string data;
};
    
    class C_Buffer{
        public:
        C_Buffer(int size): buffer_max_size(size), head(0), tail(0), loc(0), size(0){
        }
        
        void add(string o){
			Node* temp;
            if(this->size == 0){
                head = tail = loc = new Node(o);
				size++;
            }
			else if(this->size <this->buffer_max_size){
				temp = new Node(o);
				tail->next = temp;
				tail = tail->next;
				tail->next = head;
				size++;
			}
			else if(this->size>= this->buffer_max_size){
				cout<<"max size exceeded, rewriting first elements"<<endl;
				loc->data = o;
				loc = loc->next;
			}			
        }

		void removeNode(){
			Node* temp;
			if(this->size == 0)
				cout<<"buffer is empty"<<endl;
			else{
				temp = head->next;
				head->data = head->next->data;
				head->next = head->next->next;
				delete temp;
			}
			size--;
		}

		void print(){
			int i = 0;
			Node* temp = head;
			if(this->size == 0) cout<<"Buffer is empty"<<endl;
			while(i< size){
				cout<<temp->data<<endl;
				temp = temp->next;
				i++;
			}
		}

		//I wrote these purely for test purposes. Typically these methods are unnecessary because the client might not necessarily need access to them
		/*string getTaillNext(){
			return this->tail->next->data;
		}
        
		string HeadData(){
			return this->head->data;
		}
		Node* Head(){
			return this->head;
		}
		Node* Tail(){
			return this->tail;
		}
		string TailData(){
			return this->tail->data;
		}*/
        
        private:
        Node*  head;
        Node* tail;
		Node* loc;
        int size;// current size
        int buffer_max_size;// maximum user defined size
    };
    
    
	void appendToBuffer(C_Buffer &buff, int num_lines){
		int i = 0;
		string input;
		while(i< num_lines){
			cout<<"Enter string: ";
			cin>>input;
			buff.add(input);
			i++;
		}
	}

	void deleteFromBuffer(C_Buffer &buff, int num_lines){
		int i = 0;
		while(i<num_lines){
			buff.removeNode();
			i++;
		}
	}
    
    
    
    int main(){
		int b_size;
		cout<<"Enter Buffer Size: ";cin>>b_size;

		C_Buffer buffer = C_Buffer(b_size);

		int num_lines;
		char command;
		bool exit = false;

		while(!exit){
			cout<<endl<<"Enter A to add"<<endl
				<<"Enter R to remove"<<endl
				<<"Enter L to list"<<endl
				<<"Enter Q to quit"<<endl;
            cin>>command;
            if(command == 'Q')
                exit = true;
            else {
                if(command == 'A'){
					cout<<"Number of lines to append: ";
                    cin>>num_lines;
                    appendToBuffer(buffer, num_lines);
                }
                
                if(command == 'R'){
					cout<<"Number of lines to remove: ";
                    cin>>num_lines;
                    deleteFromBuffer(buffer, num_lines);
                }
                if(command == 'L'){
                    buffer.print();
                }
            }
        }
        
        system("pause");
        return 0;
}
