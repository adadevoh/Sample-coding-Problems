string replaceSpace(string a){
	string b = "";
	for (int i = 0; i < a.length(); i++){
		if (a[i] == ' '){
			b = b + "%20";
		}
		else
			b = b + a[i];			
	}
	return b;
}
