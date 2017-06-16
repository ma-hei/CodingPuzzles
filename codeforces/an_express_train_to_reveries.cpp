#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i=0;i<2*n;i++){
		i<n ? cin>>a[i] : cin>>b[i-n];
	}
	int counter = 0;
	int idx;
	int idx_1;
	int idx_2;
	int* v = new int[n+1]();
	for (int i=0;i<n;i++){
		if (a[i]!=b[i]){
			counter++;
			counter==1 ? idx_1=i : idx_2=i;
		} else {
			v[a[i]]++;
			idx = v[a[i]]==2 ? i : idx;
		}
	}
	int filler = 0;
	for (int i=1;i<n+1;i++){
		filler = v[i]==0 ? i : filler;
	}

	if(counter==0){
		for (int i=0;i<n;i++){
			cout<<(i==idx ? filler : a[i])<<" ";
		}
	} else if (counter==1){
		for (int i=0;i<n;i++){
			cout<<(a[i]!=b[i] ? filler : a[i])<<" ";
		}
	} else if (counter==2){
		for (int i=0;i<n;i++){
			if (a[i]!=b[i]){
				if (v[a[idx_1]]==0 && v[b[idx_2]]==0){
					cout<<(i==idx_1 ? a[i] : b[i])<<" ";
				} else {
					cout<<(i==idx_2 ? a[i] : b[i])<<" ";
				}	
			 } else {
				 cout<<a[i]<<" ";
			 }
		}
	}
}
