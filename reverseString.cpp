string reverseString(string mine){
	int j = mine.size() - 1;
	char temp = ' ';
	for (int i = 0; i < j; i++){
		temp = mine[i];
		mine[i] = mine[j];
		mine[j] = temp;
		j--;
	}

	return mine;
}
