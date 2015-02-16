string removeDupChar(string mine){

//implememtation using an array buffer. each character is turned into an int and represents an index in buf
//when a character is reached it is asssigned from false to true, so if it is reached again we know its a duplicate
//and to remove it
	/*array<bool, 256>buf;//sake of 256 ascii characters
	//could just use stl map
	for (int i = 0; i < buf.size(); i++){
		buf[i] = false;
	}
	const int x = mine.size();
	string temp ="";

	for (int i = 0; i < mine.size(); i++){
		if (buf[mine[i]] == false){
			buf[mine[i]] = true;
			temp = temp + mine[i];
		}
	}
	return temp;*/

//implememnted using stl map, much shorter code and less space, why use 256 when we only need the size of the string
	string temp = "";
	map<char, bool>hash;
	for (int i = 0; i < mine.length(); i++){
		if (hash[mine[i]] == 0){
			//hash.insert(make_pair(mine[i], true));
			//hash.insert(pair<char, bool>(mine[i], true));
			hash[mine[i]] = true;// a direct assignment works, but insert() doesnt do the assignment correctly
			temp = temp + mine[i];
		}
	}
	return temp;
}
