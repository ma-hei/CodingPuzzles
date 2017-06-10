#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int** mat = new int*[n];
	int sum = 0;
	for (int i=0;i<n;i++){
		mat[i] = new int[n];
		cin>>mat[i][i==n-1 ? 0 : i+1];
		sum+=mat[i][i==n-1 ? 0 : i+1];
	}
	for (int i=2;i<n-1;i++){
		for (int k=0;k+i<n;k++){
			int dest = k+i;
		       	int prev = k+i-1;
			mat[k][dest] = mat[k][prev] + mat[prev][dest];
			sum+=mat[k][dest];
		}
	}
	cout<<sum<<"\n";
}
