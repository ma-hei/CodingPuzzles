#include <iostream>

using namespace std;

void set_one(string& s, int l, int r){
  for (int i=l;i<=r;i++) s[i] = '1';
}

void set_zero(string& s, int l, int r){
  for (int i=l;i<=r;i++) s[i] = '0';
}

int find_zero(int n){
  string s(n,'0');
  int hamming;
  cout<<s<<'\n';
  fflush(stdout);
  cin>>hamming;
  int l = 0;
  int r = n-1;
  int idx = -1;
  while(l<r){
    int mid = (l+r)/2;
    cout<<"l: "<<l<<" r:"<<r<<" m:"<<mid<<"\n";
    set_one(s,l,mid);
    cout<<s<<'\n';
    fflush(stdout);
    int hamming_;
    cin>>hamming_;
    if ((hamming_-hamming)==(mid-l)+1){ break;}
    else if ((hamming-hamming_)==(mid-l)+1) l = mid+1;
    else r = mid;
    set_zero(s,l,mid);
  }
  return l;
}

int main(){
  int n;
  cin>>n;
  cout<<find_zero(n);
}
