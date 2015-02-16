string compress(string a){
	int count = 1;
	string temp = "";

	for (int i = 0; i < a.length(); i++){
		if (a[i] == a[i + 1]){
			count++;
		}
		if (a[i] != a[i + 1]){
			temp = temp + a[i] + to_string(count);
			count = 1;
		}
	}

	return temp;
}
