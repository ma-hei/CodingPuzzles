#include <iostream>

using namespace std;

int main(){
	int k;
	int n;
	int m;
	cin>>k;
	cin>>n;
	cin>>m;
	string temp;
	int mars_cnt = 0;
	for(int i=0;i<k;i++){
		cin>>temp;
		if(temp!="Mars") mars_cnt++;
	}
	int need_to_buy_mars = (mars_cnt-m<0) ? -1*(mars_cnt-m) : 0;
	int mars_bars_used = (mars_cnt-m>0) ? m : mars_cnt;
	int bars_left = k-mars_bars_used;
	int need_to_buy_rest = (bars_left-n<0) ? -1*(bars_left-n) : 0;
	int buy_total = need_to_buy_mars + need_to_buy_rest;
	cout<<buy_total<<"\n";
}

