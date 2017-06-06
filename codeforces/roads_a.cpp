#include <iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  int* arr = new int[n];
  long long sum=0;
  for (int i=0;i<n;i++){
	cin>>arr[i];
	sum+=arr[i];
  }	
  long long res = 0;
  int e = 0;
  long long temp;
  while (e+1<=n && temp+arr[e]<sum-(temp+arr[e])){
	temp += arr[e];
	e++;
  }
  long long res = 0;
  for (int i=0;i<e;i++){
	res += arr[i]*e;;
  } 
  if (e+1!=n){	
  } 
}

