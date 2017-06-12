#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;



ll res(int n, int k, int* a, ll* b){
  
  for (int i=0;i<n;i++){
	b[i] = a[i] + (i+1) * (ll) (k+1);
  }
  sort(b, b+n);
  ll ans = 0;
  for (int i=0; i<(k+1); i++){
	ans += b[i];
  }
  return ans;
}

int main(){
  int n;
  int s;
  cin>>n>>s;
  int* a = new int[n];
  ll* b = new ll[n];
  for (int i=0;i<n;i++){
	cin>>a[i];
  } 
  int l=0,r=n-1;
  int max_found = 0;
  while(l<=r){
	int m = (l+r)/2;
	if (res(n,m,a,b)<= s){
	  l = m+1;
	} else {
	  r = m-1;
	}	
  }
  ll ans = res(n,l-1,a,b);
  cout<<l<<' '<<ans<<"\n";  
}
