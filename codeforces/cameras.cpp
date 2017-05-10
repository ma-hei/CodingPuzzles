#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
	int n,k,r;
	cin>>n>>k>>r;
	int* locations = new int[k];
	unordered_set<int> locations_;
	for (int i=0;i<k;i++){ cin>>locations[i]; locations_.insert(locations[i]);}
	
	int l_=0;
	int r_=r-1;
	int count = 0;
	for (int i=0;i<r;i++){
		if (locations_.count(i+1)==1){
			count++;
		}
	}
	vector<pair<int,int> >intervals;
	if(count<2) intervals.push_back(pair<int,int>(0,r-1));

	while(r_<n){
		if (locations_.count(r_+2)==1){
			count++;
		}
		if (locations_.count(l_+1)==1){
			count--;
		}
		l_++;
		r_++;
		if (count<2) intervals.push_back(pair<int,int>(l_,r_) );
	}
	for (pair<int,int>& p : intervals){
			
	}
	int e = intervals[0].second;
	count = 1;
	for (int i=0;i<intervals.size();i++){
		if (intervals[i].first>e){
			e=intervals[i].second;
			count++;
		}
	}
	cout<<count<<"\n";
}
