bool isAnagram(string a, string b){
	//use stl map
	if (a.length() != b.length())//cause different lengths means different words
		return false;
	map<char, bool>hash;

	for (int i = 0; i < a.length(); i++){
		hash.insert(make_pair(a[i], true));
		//hash.insert(pair<char, bool>(a[i], true));
		//hash[a[i]] = true;
	}

	for (int i = 0; i < b.length(); i++){
		if (!hash[b[i]])
			return false;
	}

	return true;
}
