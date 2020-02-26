#include <iostream>
#include <algorithm>
using namespace std;

int N,D,a[105];

int main(){
  int T; cin>>T;
  while (T--){
    cin>>N>>D;
    for (int i=0;i<N;i++)
      cin>>a[i];
    int sum = N > 0 ? a[0] : 0;
    int dist = 1;
    while (D > 0 && dist<N) {
      int m = min(D/dist, a[dist]);
      D -= m*dist;  
      sum+=m;
      dist++;
    }
    cout << sum <<'\n';
  }
}
