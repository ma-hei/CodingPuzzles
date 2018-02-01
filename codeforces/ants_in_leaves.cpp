#include <iostream>
#include <vector>

using namespace std;

int n;
int v[500000];
vector<int> g[500000];


void dfs(int i, int d, vector<int>& z){
  if (g[i].size()==1 && v[g[i][0]]==1) z.push_back(d);
  else {
    for (int k=0;k<g[i].size();k++){
      if (!v[g[i][k]]){
        v[i] = 1;
        dfs(g[i][k],d+1,z);
      }
    }
  }
}

int main(){

  cin>>n;
  for (int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }  
  
  vector<int> z;
  dfs(0,0,z);
  sort(z.begin(), z.end());
  for (int i=0;i<z.size();i++) cout<<z[i]<<' '; 

}
