#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int q;
	cin>>q;
	pair<int,char>* p = new pair<int,char>[q];
	for (int i=0;i<q;i++){
		int k;
		char c;
		cin>>k>>c;
		p[i] = pair<int,char>(k,c);
	}
	for (int i=0;i<q;i++){
		char l = p[i].second;
		vector<pair<int,bool> > v;
		for (int k=0;k<s.length();k++){
			if ((k==0 || s[k-1]!=l) && s[k]==l){
				v.push_back(pair<int,bool>(1,true));
			} else if((k==0 || s[k-1]==l) && s[k]!=l){
				v.push_back(pair<int,bool>(1,false));
			} else {
				v[v.size()-1].first++;
			}	
		}
	}
}
