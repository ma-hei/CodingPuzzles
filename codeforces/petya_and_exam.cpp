#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;

int main(){
  string good;
  cin>>good;
  int* good_letters = new int[26]; 
  for (int i=0;i<26;i++) good_letters[i]=0;
  for (auto c: good){
    good_letters['a'-c]=1;
  }
  string pattern;
  cin>>pattern;
  int n;
  cin>>n;
  for (int i=0; i<n; i++){
    string query;
    cin>>query;
    int** dp = new int* [query.length()+1];
    for (int k=0; k<query.length()+1; k++){
      dp[k] = new int[pattern.length()+1];
    }
    for (int k=0; k<query.length()+1; k++) dp[k][0] = 0;
    dp[0][0] = 1;
    for (int k=1; k<pattern.length()+1; k++) dp[0][k] = (pattern[k-1]=='*' && dp[0][k-1]==1) ? 1 : 0;
     
    for (int k=1; k<query.length()+1; k++){
      for (int j=1; j<pattern.length()+1; j++){
        dp[k][j] = ((pattern[j-1]=='*' && dp[k][j-1]==1) || (pattern[j-1]=='*' && dp[k-1][j-1]==1 && good_letters['a'-query[k-1]]==0) || (dp[k-1][j-1]==1 && query[k-1]==pattern[j-1]) || (dp[k-1][j-1]==1 && good_letters['a'-query[k-1]]==1 && pattern[j-1]=='?') || (dp[k-1][j]==1 && pattern[j-1]=='*' && good_letters['a'-query[k-1]]==0)) ? 1 : 0;
      } 
    }
    if (dp[query.length()][pattern.length()]==1) cout<<"YES\n";
    else cout<<"NO\n";
  }
}







