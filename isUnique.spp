bool isUnique(int myArr[], const size_t SIZE){
//can be implemented using an stl map -> better space management
	array<bool, 256>mine;
	for (int i = 0; i < mine.size(); i++){
		mine[i] = false;
	}
	

	int temp = 0;
	for (int i = 0; i < SIZE; i++){
		temp = myArr[i];
		if (mine[temp] == false){
			cout << "at i = "<<i<<"and myArr = "<<temp<<endl;
			mine[temp] = true;
		}
		else{//this was all just for test, only thing needed is the 'return false'
			cout << "entered else" << endl;
			cout << "i: " << i << endl;
			cout <<"mine[myArr[i]]: "<< mine[temp]<<endl;
			cout << "myArr[i]: " << temp << endl;
			return false;
		}
	}
	//alternatively you could just check for negativity in the if statement, and return false once encountered
	//save a few lines and key strokes :)
	
	return true;
}
