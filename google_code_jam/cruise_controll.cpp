#include <iostream>
#include <fstream>
#include <iomanip> 
using namespace std;

int main(){
	
	ifstream in("A-large-practice.in");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	
	ofstream out("out.txt");
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
	

	int t;
	cin>>t;
	for (int i=0;i<t;i++){
		int d,n;
		cin>>d>>n;
		int** ks = new int*[n];
		for (int k=0;k<n;k++){
			ks[k] = new int [2];
			cin>>ks[k][0]>>ks[k][1];
		}
		float t_dest=0;
		float actual=0;
		float prev = 0;
		for (int k=n-1;k>=0;k--){
			t_dest = (float) (d-ks[k][0])/ks[k][1];
			actual = k==n-1 ? t_dest : max(prev, t_dest);
			prev = actual;
		}
		cout<<"Case #"<<(i+1)<<": "<<setprecision(9)<<(float)d/prev<<"\n";
	}
}
