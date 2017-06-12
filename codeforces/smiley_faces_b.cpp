#include <iostream>

using namespace std;

int main(){
	string in;
	cin>>in;
	int n = in.length();
	int* arr = new int[n];
	int* arr_ = new int[n];
	
	arr[0] = 0;
	for (int i=1;i<n;i++){
		arr[i] = (in[i-1]=='(' && in[i]==':') ? arr[i-1]+1 : arr[i-1];	
	}
	arr_[n-1] = 0;
	for (int i=n-2;i>=0;i--){
		arr_[i] = (in[i+1]==')' && in[i]==':') ? arr_[i+1]+1 : arr_[i+1];
	}

	int max_smileys = max(arr_[0],arr[n-1]);
	for (int i=1;i<n;i++){
		int add = (in[0]==':' && in[i]==')') ? 1 : 0;
		max_smileys = max(max_smileys, arr[i-1]+arr_[i]+add);
	}
	cout<<max_smileys<<"\n";
}
