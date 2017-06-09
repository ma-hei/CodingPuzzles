#include <iostream>
#include <algorithm>
using namespace std;

bool pair_order(pair<long,int>& a, pair<long,int>& b){
  return a.first+a.second<b.first+b.second;
}

int main(){
  int n;
  long b;
  cin>>n;
  cin>>b;
  pair<long,int>* prices = new pair<long,int>[n];
  for (int i=0;i<n;i++){
	int temp;
	cin>>temp;
	prices[i] = pair<long,int>(temp,i+1);
  } 
  sort(prices, prices+n, pair_order); 
  long* to_add = new long[n];
  long* price_sum = new long[n];
  
  for (int i=0;i<n;i++){
	//cout<<"->"<<prices[i].first<<" "<<prices[i].second<<"\n";
	to_add[i] = i==0 ? prices[0].second : to_add[i-1]+prices[i].second;
	price_sum[i] = i==0 ? prices[0].first : price_sum[i-1]+prices[i].first;
  } 
  int l=0;
  int r=n-1;
  int total_items = 0;
  long max_cost = 0;
  while(l<=r){
	int middle = (l+r)/2;
	long total_cost = price_sum[middle] + (middle+1)*to_add[middle];
	//cout<<price_sum[middle]<<" "<<to_add[middle]<<"\n";
	//cout<<middle<<" "<<total_cost<<"\n";
	if (total_cost<=b){
	  total_items = middle+1;
	  max_cost = total_cost;
	  l = middle + 1;
	} else {
	  r = middle-1;	  
	}
  }
  cout<<total_items<<" "<<max_cost<<"\n";
}
