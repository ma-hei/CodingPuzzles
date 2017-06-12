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
		if (!v[0].second){
			v.push_front(0,true);
		}	
		int p1 = 0;
		int p2 = 0;
		int sum = 0;
		int left = p[i].first;
		while(p2<v.size()){
			if (v[p1].second && v[p2].second && left>=0){
					int padding_left = p1==0 ? 0 : v[p1-1].first;
					int padding_right = p2<n-1 ? v[p2+1].first : 0;
					
					p2++;
			} else if (v[p2].second && left <0){
				if (v[p1].second){
					sum-=v[p1].first;
				} else {
					left+=v[p1].first;
					sum-=v[p1].first;
				}
				p1++;
			} else if (!v[p2].second){
				left-=v[p2].first;
				sum+=v[p2].first;
				p2++;
			} else if (v[p2].second){
				sum+=v[p2].first;
				p2++;
			}
		}
	}
}
