#include <iostream>
#include <algorithm>
using namespace std;

bool func(long long int* a, long long int* b){
	return a[0]<b[0];
}

int main(){

	int n,k;
	cin>>n>>k;
	long long int** houses = new long long int*[n];
	for (int i=0;i<n;i++){
		houses[i] = new long long int[2];
		cin>>houses[i][0]>>houses[i][1];
	}

	sort(houses, houses+n, func);

	long long int time=0;
	int index=0;
	while(index<n && houses[index][0]<0){
		long long int walks = houses[index][1]/k;
		time+= (long long int) walks*houses[index][0]*-2;
		long long int left = houses[index][1]-walks*k;
		index++;

		if (left>0){
			time -= (long long int) houses[index-1][0]*2;
			while(index<n && left>houses[index][1] && houses[index][0]<0){
				left-=houses[index][1];
				index++;
			}
			if(index<n && houses[index][0]<0)
				houses[index][1]-=left;
		}

	}

	index = n-1;
	while (index>=0 && houses[index][0]>0){
		long long int walks = houses[index][1]/k;
		time+=(long long int) walks*houses[index][0]*2;
		int left = houses[index][1]-walks*k;
		index--;

		if (left>0){
			time += (long long int) houses[index+1][0]*2;
			while(index>0 && left>houses[index][1] && houses[index][0]>0){
				left-= houses[index][1];
				index--;
			}
			if (index>=0 && houses[index][0]>0)
				houses[index][1]-=left;
		}
	}
	cout<<time<<"\n";
}
