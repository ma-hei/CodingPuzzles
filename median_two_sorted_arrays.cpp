#include <iostream>

using namespace std;

int find(int n, int m, int* arr_n, int* arr_m, int l_n, int r_n, int l_m, int r_m, int x){
  if (l_n==r_n && l_m==r_m){
    return (x==1 ? min(arr_n[l_n],arr_m[l_m]) : max(arr_n[l_n],arr_m[l_m]) );
  }else if (l_n==r_n){
    if(x==1) return min(arr_n[l_n],arr_m[l_m]);
    if (arr_m[l_m+x-1]<=arr_n[l_n]) return arr_m[l_m+x-1];
    return arr_m[l_m+x-2]>arr_n[l_n] ? arr_m[l_m+x-2] : arr_n[l_n]; 
  }else if (l_m==r_m){
    if(x==1) return min(arr_n[l_n],arr_m[l_m]);
    if (arr_n[l_n+x-1]<=arr_m[l_m]) return arr_n[l_n+x-1];
    return arr_n[l_n+x-2]>arr_m[l_m] ? arr_n[l_n+x-2] : arr_m[l_m]; 
  }
  int middle_idx_n = (l_n+r_n)/2;
  int middle_idx_m = (l_m+r_m)/2;
  int middle_elem_n = arr_n[middle_idx_n];
  int middle_elem_m = arr_m[middle_idx_m];
  int sum = middle_idx_n - l_n + middle_idx_m - l_m + 2;
  if (x <= sum){
    if (middle_elem_n <= middle_elem_m){
      return find(n,m,arr_n,arr_m,l_n,r_n,l_m,middle_idx_m,x);
    } else {
      return find(n,m,arr_n,arr_m,l_n,middle_idx_n,l_m,r_m,x);
    }
  } else {
    if (middle_elem_n <= middle_elem_m){
      return find(n,m,arr_n,arr_m,middle_idx_n+1,r_n,l_m,r_m,x-(middle_idx_n-l_n+1));
    } else {
      return find(n,m,arr_n,arr_m,l_n,r_n,middle_idx_m+1,r_m,x-(middle_idx_m-l_m+1));
    }
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  
  int* arr_n = new int[n];
  int* arr_m = new int[m];
  for (int i=0;i<n;i++) cin>>arr_n[i];
  for (int i=0;i<m;i++) cin>>arr_m[i];
 
  float median;
  if ((n+m)%2==0) median = (float) ( find(n,m,arr_n,arr_m,0,n-1,0,m-1,((n+m)/2)+1) + find(n,m,arr_n,arr_m,0,n-1,0,m-1,((n+m)/2)) )/2;
  else median = find(n,m,arr_n,arr_m,0,n-1,0,m-1,((n+m)/2)+1);

  cout<<median<<"\n";
}
