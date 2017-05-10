#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	char** grid = new char* [n];

	for (int i=0;i<n;i++) grid[i] = new char[m];

	for (int i=0;i<n;i++){
		string temp;
		cin>>temp;
		for (int k=0;k<m;k++) grid[i][k] = temp[k];
	}

	int lowest;
	for (int i=0;i<m;i++){
		lowest=-1;
		for (int k=n-1;k>=0;k--){
			if (grid[k][i]=='.' && lowest==-1) lowest = k;
			if (grid[k][i]=='#') lowest = -1;
			if (grid[k][i]=='o' && lowest!=-1){
				grid[lowest][i] = 'o';
				grid[k][i]='.';
				lowest--;
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int k=0;k<m;k++){
			cout<<grid[i][k];
		}
		cout<<"\n";
	}
}
