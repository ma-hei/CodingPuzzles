#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

bool func(long long int* a, long long int* b){
	return a[0]<b[0];
}

int main(){
	ifstream in("Postman-1000.in");
        streambuf *cinbuf = cin.rdbuf();
        cin.rdbuf(in.rdbuf()); 
 
	int n,k;
	cin>>n>>k;
	long long int** houses = new long long int*[n];
	for (int i=0;i<n;i++){
		houses[i] = new long long int[2];
		cin>>houses[i][0]>>houses[i][1];
	}

	sort(houses, houses+n, func);

	long long int time = 0;
	int index = 0;
	while(index<n && houses[index][0]<0){
		long long int walks = (houses[index][1]+(k-1))/k;
		time-=walks*houses[index][0]*2;
		long long int cap = walks*k;
		while(cap>0 && index<n && houses[index][0]<0){
			if (houses[index][1]<=cap){
				cap-=houses[index][1];
				index++;
			} else{
				houses[index][1]-=cap;
				break;
			}
		}
	}
	index=n-1;
	while(index>=0 && houses[index][0]>0){
		long long int walks = (houses[index][1]+(k-1))/k;
		time+=walks*houses[index][0]*2;
		long long int cap = walks*k;
		while(cap>0 && index>=0 && houses[index][0]>0){
			if (houses[index][1]<=cap){
				cap-=houses[index][1];
				index--;
			} else{
				houses[index][1]-=cap;
				break;
			}
		}
	}
	cout<<time<<"\n";
}
