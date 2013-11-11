#include<iostream>
#include<iomanip>
#include<string>
#include<map>
#include<vector>

using namespace std;

/*This implementation is ok, but you'll need to first iterate through one of the
*lists entirely to initialize the mapping, and then through the other one to find intersection
*plus you still had to convert both lists to vectors (before calling function) if not yet done
*/
vector<int>getIntersection(vector<int>a, vector<int>b)
{
	map<int, bool> myMap;
	vector<int> newMap;
	string message = "No intersection";
	for(int i = 0; i<a.size(); i++)
		myMap[a[i]]= true;

	for(int i= 0; i<b.size(); i++)
	{
		if(myMap[b[i]] == true)
		{
			cout<<"value found: "<<b[i]<<endl;
			cout<<"insert into newMap location "<<i<<endl;//noting the position of the element in the newMap
			newMap.push_back(b[i]);
			//message = "this is the intersection";
		}
	}
	cout<<message<<endl;
	return newMap;
}

void intersection(vector<int>a, vector<int>b)//only for ordered lists
{
	int i = 0, j = 0;
	while(i< a.size() && j< b.size())
	{
		if(a[i] == b[j])
		{
			cout<<"this is a common element: "<<a[i]<<endl;
			i++;
			j++;
		}
		else if(a[i] < b[j])
			i++;
		else
			j++;
	}
}
/*// best so far (for unordered list), identifies the smaller list, then initializes map and checks for
*duplicates at the same time, and runs only as long as the smaller list O(n).
*still needs the list to be converted to vectors if not one already.
*This function can also be adited to return a new list of all the intersected elements
*/
void listIntersection(vector<int>a, vector<int>b)
{
	int *smaller;
	int *larger;
	map<int, bool>myMap;

	if(a.size()< b.size())
	{
		smaller = &a[0];
		larger = &b[0];
	}
	else
	{
		smaller = &b[0];
		larger = &a[0];
	}
	int i = 0;
	while(i< a.size() || i<b.size())
	{
		myMap.insert(pair<int, bool>(*smaller, true ));

		if(myMap[*larger] == true)
			cout<<"intersection found: "<<*larger<<endl;

		i++;
		smaller++;
		larger++;
	}
}



int main()
{
	vector<int>l1;
	vector<int>l2;
	l1.push_back(2);
	l1.push_back(5);
	l1.push_back(1);
	l1.push_back(7);
	l1.push_back(9);

	
	l2.push_back(4);
	l2.push_back(2);
	l2.push_back(1);
	l2.push_back(3);
	l2.push_back(9);
	l2.push_back(5);
	l2.push_back(6);
	l2.push_back(7);
	l2.push_back(8);
	

	vector<int>temp;
	//test getIntersection
	cout<<"getIntersection()"<<endl;
	temp = getIntersection(l1, l2);

	//intersection(l1, l2);
	cout<<endl<<endl<<"listIntersection()"<<endl;
	//test list Intersection
	listIntersection(l1, l2);


	system("pause");
	return 0;
}
