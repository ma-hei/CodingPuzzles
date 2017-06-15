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
		vector<pair<int,bool> >v(n);
		int count=0;
		for (int k=0;k<s.length();k++){
			if ((k==0 || s[k-1]!=l) && s[k]==l){
				v[count++] = pair<int,bool>(1,true);
			} else if((k==0 || s[k-1]==l) && s[k]!=l){
				v[count++] = pair<int,bool>(1, false);
			} else {
				v[count-1].first++;
			}	
		}
		if (!v[0].second){
			v.insert(v.begin(),pair<int,bool>(0,true));
			count++;
		}	
		
		int p1 = 0;
		int p2 = 0;
		int sum = v[0].first;
		int left = p[i].first;
		int max_sum = 0;
		while(p2<v.size()){
			if (v[p1].second && v[p2].second && left>=0){
					int padding_left = p1==0 ? 0 : v[p1-1].first;
					int padding_right = p2<count-1 ? v[p2+1].first : 0;
					int total = min(padding_left+padding_right,left) + sum;
  					max_sum = max(max_sum, total);
					p2++;
					sum += p2<n ? v[p2].first : 0;
					left -= p2<n ? (v[p2].second ? 0 : v[p2].first) : 0;
			} else if (v[p2].second && left <0){
			  sum -= v[p1].first;
			  left += v[p1].second ? 0 : v[p1].first;
			  p1++;
			} else{
			  p2++;
			  sum += v[p2].first;
			  left -= v[p2].second ? 0 : v[p2].first;
			} 
		}
	  cout<<max_sum<<"\n";
	}
}
