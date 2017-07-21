#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int* arr = new int[n];
	for (int i=0;i<n;i++)cin>>arr[i];
	int state=1;
	for (int i=1;i<n;i++){
		if (state==1 && arr[i]>arr[i-1]) continue;
		else if (state==1 && arr[i]==arr[i-1]){ state=2; continue;}
		else if (state==2 && arr[i]==arr[i-1]) continue;
		else if (arr[i]<arr[i-1]){ state=3; continue;}
		else {
			cout<<"NO\n";
			return 0;
		}
		cout<<i<<"\n";
	}
	cout<<"YES\n";
	return 0;
}		
