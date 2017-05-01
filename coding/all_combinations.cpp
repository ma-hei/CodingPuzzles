#include <iostream>

using namespace std;


void print_all_combinations(int* arr, int s, int n){
	
	if (s==n-1){
		for (int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}

	for (int i = s; i<n; i++){
		int temp = arr[i];
		arr[i] = arr[s];
		arr[s] = temp;
		print_all_combinations(arr, s+1, n);
		arr[s] = arr[i];
		arr[i] = temp;
	}

}

int main(){
	
	int n;
	cin>>n;
	int* arr = new int[n];

	for (int i=0;i<n;i++){
		arr[i]=i+1;
	}
	print_all_combinations(arr, 0, n);
}
