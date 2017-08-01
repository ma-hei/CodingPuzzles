#include <iostream>
#include <vector>

using namespace std;

int dp[101][101][11];

int main(){
  
  int n,q,c;
  cin>>n>>q>>c;
  for (int i=0;i<n;i++){
    int x,y,s;
    cin>>x>>y>>s;
    dp[y][x][s]++;
  } 
  for (int i=1;i<=100;i++){
    for (int k=1;k<=100;k++){
      for (int j=0;j<=10;j++){
        dp[i][k][j] += dp[i-1][k][j] + dp[i][k-1][j] - dp[i-1][k-1][j];
      }
    }
  }
  for (int i=0;i<q;i++){
    int t,x1,y1,x2,y2;
    cin>>t>>x1>>y1>>x2>>y2;
    int temp = 0;
    for (int k=0;k<=c;k++){
      temp += (dp[y2][x2][k]-dp[y1-1][x2][k]-dp[y2][x1-1][k]+dp[y1-1][x1-1][k])*((k+t)%(c+1));
    }
    cout<<temp<<"\n";
  }
}
