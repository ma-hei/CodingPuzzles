#include <iostream>
#include <algorithm>
using namespace std;

int main(){
<<<<<<< HEAD
  int n;
  cin>>n;
  int* arr = new int[n];
  long long sum=0;
  for (int i=0;i<n;i++){
	cin>>arr[i];
	sum+=arr[i];
  }	
  long long res = 0;
  int b=0;
  long long temp = 0;
  while(b<n && temp+arr[b] <= sum-(temp+arr[b])){
	temp+=arr[b];
	b++;
  }
  int e = n-1;
  temp=0;
  while(e>=1 && temp+arr[e-1] <= sum-(temp+arr[e-1])){
	temp+=arr[e-1];
	e--;
  }
  int left = n-1-b;
  //cout<<"b: "<<b<<"\n";
  //cout<<"e: "<<e<<"\n";
  for (int i=0;i<n-1;i++){
	long long backward_1 = i<e && e>1? e-1-i : 0;
	long long forward_1 = i<b ? (b-i)*(i+1) : 0;
	long long forward_2 = i>=e && i<=b ? left*(i-e+1) : 0;
	long long forward_3 = i>b ? (i-e+1)*(n-1-i) : 0;
	long long backward_2 = i>b ? e*(i-b) : 0;
	res+=(long long)arr[i]*(forward_1+forward_2+forward_3+backward_1+backward_2);
  }
  long long last_one=e>0 ? e*left :0;
}
