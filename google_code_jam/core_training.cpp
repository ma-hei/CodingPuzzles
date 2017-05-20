#include <iostream>
#include <iomanip> 
#include <fstream>

using namespace std;

bool sort_decreasing(float a, float b){
	return a>b;
}

int main(){

	ifstream in("C-small-practice-1.in");
	//streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	
	ofstream out("out.txt");
	//streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
	
	int t;
	cin>>t;
	for (int i=0;i<t;i++){
		int n,x;
		cin>>n>>x;
		float u;
		cin>>u;
		float* p = new float[n+1];
		p[0] = 1;
		for (int k=1;k<=n;k++){
			cin>>p[k];
		}
		sort(p,p+n,sort_decreasing);
		int k=n-1;
		while(k>=0 && u>0){
			float diff = p[k]-p[k+1];
			float temp = min(u, (float) diff*(n-k));
			float add = ((float) diff*(n-k))>u ? ((float) u/(n-k)) : diff;
			for (int j=n;j>k;j--){
				p[j]+=add;
			}
			u-=temp;
			k--;
		}
		float prob = 1;
		for (int k=0;k<=n;k++){
			prob*=p[k];
		}
		cout<<"Case #"<<(i+1)<<": "<<setprecision(9)<<prob<<"\n";
	}
}
