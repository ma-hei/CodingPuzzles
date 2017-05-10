#include <iostream>
#include <queue>

using namespace std;

void bfs(int** grid, int n, int m){
	queue<pair<int, int> > q;
	q.push(pair<int,int>(n-1,m-1));
	int count = 1;
	grid[n-1][m-1] = 1;
	while(!q.empty()){
		pair<int,int> temp = q.front();
		q.pop();
		if (temp.first>0 && grid[temp.first-1][temp.second]==-1){
			grid[temp.first-1][temp.second] = ++count;
			q.push(pair<int,int>(temp.first-1,temp.second));
		}
		if (temp.second>0 && grid[temp.first][temp.second-1]==-1){
			grid[temp.first][temp.second-1] = ++count;
			q.push(pair<int,int>(temp.first,temp.second-1));
		}
	}
}

void print_plan(int** grid, int n, int m){
	for (int i=0;i<n;i++){
		for (int k=0;k<m;k++){
			cout<<grid[i][k];
		}
		cout<<"\n";
	}

}
int main(){
	int t;
	cin>>t;
	int n,m;
	cin>>n>>m;
	int** grid = new int*[n];
	for (int i=0;i<n;i++){
		grid[i] = new int[m];
		for (int k=0;k<m;k++){
			grid[i][k]=-1;
		}
	}
	
	bfs(grid, n, m);
	print_plan(grid,n,m);
}
