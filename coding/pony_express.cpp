#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;


template<typename T> void floyd_warshall(T** g, int n){
	
	for (int k=0;k<n;k++){
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if((g[i][k]<LONG_MAX && g[k][j]<LONG_MAX)){
					if(g[i][j]>g[i][k]+g[k][j]){
						g[i][j] = g[i][k] + g[k][j];
					}
				}
			}
		}
	}	
}

int main(){
		
	ifstream in("C-large-practice.in");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	
	ofstream out("out.txt");
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
	
	int t;
	cin>>t;
	for (int i=0;i<t;i++){
		int n,q;
		cin>>n>>q;

		int** horses = new int*[n];
		for (int k=0;k<n;k++){
			horses[k] = new int[2];
			cin>>horses[k][0]>>horses[k][1];
		}
		long** g = new long*[n];
		for (int k=0;k<n;k++){
			g[k] = new long[n];
			for (int j=0;j<n;j++){
				cin>>g[k][j];
				g[k][j] = g[k][j]==-1 ? LONG_MAX : g[k][j];
			}
			g[k][k] = 0;
		}
		//for (int k=0;k<n;k++){
		//	for (int j=0;j<n;j++){
		//		cout<<g[k][j]<<" ";
		//	}
		//	cout<<"\n";
		//}
		int** q_ = new int*[q];
		for (int k=0;k<q;k++){
			q_[k] = new int[2];
			cin>>q_[k][0]>>q_[k][1];
		}
		floyd_warshall(g,n);
		//for (int k=0;k<n;k++){
		//	for (int j=0;j<n;j++){
		//		cout<<g[k][j]<<" ";
		//	}
		//	cout<<"\n";
		//}
		float** g_ = new float*[n];
		for (int k=0;k<n;k++){
			g_[k] = new float[n];
			for (int j=0;j<n;j++){
				g_[k][j] = g[k][j]<=horses[k][0] ? (float) g[k][j]/horses[k][1] : LONG_MAX;
			}
			g_[k][k] = 0;
		}
		//for (int k=0;k<n;k++){
		//	for (int j=0;j<n;j++){
		//		cout<<g_[k][j]<<" ";
		//	}
		//	cout<<"\n";
		//}
		floyd_warshall(g_,n);
		//for (int k=0;k<n;k++){
		//	for (int j=0;j<n;j++){
		//		cout<<g_[k][j]<<" ";
		//	}
			//cout<<"\n";
		//}
		cout<<"Case #"<<(i+1)<<": ";
		for (int k=0;k<q;k++){
			cout<<setprecision(9)<<g_[q_[k][0]-1][q_[k][1]-1]<<" ";
		}
		cout<<"\n";
	}
	
}
