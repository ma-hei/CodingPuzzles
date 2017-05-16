#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){

	int n;
	cin>>n;
	string s;
	cin>>s;
	int max_length = 0;
	int cnt = 0;
	unordered_map<int,vector<int> > m;

	for (string::iterator it = s.begin(); it != s.end(); ++it){
		if (it!=s.begin() && *it!=*(it-1)){
			m[cnt].push_back(*(it-1));
		}
		cnt = (it==s.begin() || *it == *(it-1)) ? cnt+1 : 0;
		max_length = max(max_length,cnt);
	}
	cout<<"max length is: "<<max_length<<"\n";
	int a[] = {1,1,2,3,2,5,5};
	n = 7;
	int res = 0;
	for (int i=0;i<n;i++){
		res ^= a[i];
	}
	int d[] = {3,2,4,5,6,7,2,1}; 

	int number = 0;
	int new_number;
	while(d[number]!=number){
		cout<<"current number: "<<number<<"\n";
		for (int i=0;i<8;i++) cout<<d[i]<<", ";
		cout<<"\n\n";
		new_number = d[number];
		d[number] = number;
		number = new_number;
	}	
	cout<<number<<"\n";
}

