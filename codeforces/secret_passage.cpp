#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char> > marsmap;

void print_map(marsmap& m, vector<pair<int,int> >& p){
	for (int i=0;i<m.size();i++){
		for (int k=0;k<m[0].size();k++){
			cout<<m[i][k];
		}
	}
}

vector<pair<int,int> > next_nodes(pair<int,int>& p, vector<vector<int> >& v, marsmap& m){
	for (int i=(p.first==0 ? 0 : p.first-1);i<(p.first==v.size()-1 ? v.size()-1 : p.first+1);i++){
		for (int k=(p.second==0 ? 0 : p.second-1);k<(p.second==v[0].size()-1 ? v[0].size()-1 : p.second+1);k++){
			
		}
	}
}

void bfs(marsmap& m){
	vector<vector<int> > visited(m.size(), vector<int>(m[0].size(), 0));
	queue<pair<int,int> > q;
	q.push(pair<int,int>(0,0));
	visited[0][0]=1;
	pair<int,int> temp;
	while(!q.empty()){
		temp = q.front();
		q.pop();
	}
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	marsmap map(n, vector<char>(m));
	string temp;
	for (int i=0;i<n;++i){
		cin>>temp;
		for (int k=0;k<m;++k){
			map[i].push_back(temp[k]);
		}
	}
	vector<pair<int,int> > passes;
	int tempa, tempb;
	for (int i=0;i<k;i++){
		cin>>tempa>>tempb;
		passes.push_back(pair<int,int>(tempa, tempb));
	}
		
}
