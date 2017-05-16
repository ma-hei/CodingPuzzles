#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int rec_find(int* order, int* strengths, int n, int puffer, int idx, unordered_map<string, int>& hash){

	if (n-idx==2){
		return puffer==2 ? strengths[order[idx+1]-1] + strengths[order[idx]-1] : max(strengths[order[idx+1]-1], strengths[order[idx]-1]);
	}

	string temp = to_string(puffer)+" "+to_string(idx+2);
	int res_1 = hash.count(temp)>0 ? hash[temp] : rec_find(order, strengths, n, puffer, idx+2, hash);
	hash[temp] = res_1;
	res_1+=max(strengths[order[idx]-1], strengths[order[idx+1]-1]);

	temp = to_string(puffer+2)+" "+to_string(idx+2);
	int res_2 = hash.count(temp)>0 ? hash[temp] : (rec_find(order, strengths, n, puffer+2, idx+2, hash));
	hash[temp] = res_2;

	int res_3 = 0;
	if (puffer>=2){
		temp = to_string(puffer-2)+" "+to_string(idx+2);
		res_3 = hash.count(temp)>0 ? hash[temp] : rec_find(order,strengths, n, puffer-2, idx+2, hash); 
		hash[temp] = res_3;
		res_3+=strengths[order[idx]-1] + strengths[order[idx+1]-1];
	}

	return max(res_1, max(res_2, res_3));
	
}

int main(){

	int n;
	cin>>n;
	int* strengths = new int[n];
	int* order = new int[n];
	int total_sum = 0;
	for (int i=0;i<n;i++){ cin>>strengths[i]; total_sum+=strengths[i];}
	for (int i=0;i<n;i++) cin>>order[i];
	
	unordered_map<string, int> hash;
	
	int max_strength = rec_find(order,strengths,n,0,0, hash);
	int result = 2*max_strength-total_sum;
	cout<<result<<"\n";
}

