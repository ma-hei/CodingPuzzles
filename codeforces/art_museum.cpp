#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool order_by_start(pair<int,int> a, pair<int,int> b){ return a.first<b.first;}

bool order_by_end(pair<int,int> a, pair<int,int> b){ return a.second<b.second;}

int main(){

	int n;
	cin>>n;
	vector<pair<int,int> > v;
	int a,b;
	for (int i=0;i<n;i++){
		cin>>a;
		cin>>b;
		v.push_back(make_pair(a,b));
	}
	vector<pair<int,int> > s,e;
	s = v;
	e = v;
	
	sort(s.begin(), s.end(), order_by_start);
	sort(e.begin(), e.end(), order_by_end);
	//(1,3) (2,10) (5,12) 
	int idx_s = -1;
	int idx_e = -1;
	int cnt = 0;
	int max_cnt = 0;
	while (idx_s<((int)s.size()-1)){
		if (s[idx_s+1].first<e[idx_e+1].second){ idx_s++; cnt++; max_cnt = max(max_cnt, cnt); }
		else { idx_e++; cnt--;}
	}
	cout<<max_cnt<<"\n";

}

