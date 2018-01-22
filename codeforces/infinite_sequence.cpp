#include <iostream>

using namespace std;

int main(){
  long long n;
  long long n_ = 1;
  long long temp = 1;
  cin>>n;
  while(n_+temp <= n){ n_+=temp; temp++;}
  long long res=1;
  for (long long i = n_; i!=n; i++){
    res++;
  }
  cout<<res<<'\n';
}
