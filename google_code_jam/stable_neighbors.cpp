#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

bool dfs(int* counts, vector<vector<int> >& adj_mat, stack<int>& s, int n, int start){

	int temp = s.top();
	if (s.size()==n){
		for (int i=0;i<adj_mat[temp].size();i++){
			if(adj_mat[temp][i]==start){
				return true;
			}
		}
		return false;
	}
	for (int i=0;i<adj_mat[temp].size();i++){
		int neighbor = adj_mat[temp][i];
		if (counts[neighbor]>0){
			counts[neighbor]--;
			s.push(neighbor);
			bool found = dfs(counts, adj_mat, s, n, start);
			if(!found){
				s.pop();
				counts[neighbor]++;
			}else{
				return true;
			}
		}
	}
	return false;
}

int main(){
	
	//ifstream in("B-small-practice.in");
	//streambuf *cinbuf = cin.rdbuf();
	//cin.rdbuf(in.rdbuf());
	
	//ofstream out("out.txt");
	//streambuf *coutbuf = cout.rdbuf();
	//cout.rdbuf(out.rdbuf());
	
	int t;
	cin>>t;
	char* map = new char[6];
	map[0]='R';
	map[1]='O';
	map[2]='Y';
	map[3]='G';
	map[4]='B';
	map[5]='V';
	for (int i=0;i<t;i++){
		cout<<i<<"\n";
		int n;
		int* counts = new int[6];
		cin>>n>>counts[0]>>counts[1]>>counts[2]>>counts[3]>>counts[4]>>counts[5];
		vector<vector<int> > adj_mat(6, vector<int>());
		adj_mat[0] = {4,2,3};
		adj_mat[1] = {4};
		adj_mat[2] = {0,4,5};
		adj_mat[3] = {0};
		adj_mat[4] = {0,1,2};
		adj_mat[5] = {2};
		stack<int> s;
	
		int start = 0;
		for (int k=0;k<6;k++){
			if(counts[k]>0){
				start=k;
				break;
			}
		}
		counts[start]--;
		s.push(start);
		bool possible = dfs(counts, adj_mat, s, n, start);
		if (!possible){
			cout<<"IMPOSSIBLE";
		} else{
			cout<<map[start]<<"";
			while(s.size()>1){
				cout<<map[s.top()]<<"";
				s.pop();
			}
		}
		cout<<"\n";
	}
}
