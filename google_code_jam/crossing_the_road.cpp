#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int compute_time(const pair<int,int>& a,const pair<int,int>&b, vector<vector<vector<int> > >& v, int t){
  vector<int> i = v[a.first/2][a.second/2];
  int s = i[0];
  int w = i[1];
  int t_ = i[2];
  int temp = (t+((s+w)-(t_%(s+w))))%(s+w);
  int sn = temp < s ? 1 : (s+w)-temp+1;
  int ew = temp > s ? 1 : s-temp+1;
  cout<<a.first<<" "<<a.second<<"; "<<b.first<<" "<<b.second<<" -- "<<t<<" -> sn: "<<sn<<" ew: "<<ew<<"("<<temp<<")\n";
  if (b.first==a.first+1){
    if ((a.first%2)==0){
      return sn;
    } else {
      return 2;
    }
  } else if (b.first==a.first-1){
    if ((a.first%2)==1){
      return sn;
    } else {
      return 2;
    }
  } else if (b.second==a.second+1){
    if ((a.second%2)==0){
      return ew;
    } else {
      return 2;
    }
  } else {
    if ((a.second%2)==1){
      return ew;
    } else {
      return 2;
    }
}
} 

int belman_ford(vector<vector<vector<int> > >& v){
int n = 2*v.size()*2*v[0].size();
  //cout<<n<<" vertices\n"; 
  vector<vector<int> > dist(2*v.size(), vector<int>(2*v[0].size(), INT_MAX) );
  dist[v.size()*2-1][0] = 0;
  for (int i=0;i<n-1;i++){
    for (int y=0;y<2*v.size();y++){
      for (int x=0;x<2*v[0].size()-1;x++){
        if (dist[y][x]<INT_MAX){
          int w = compute_time(make_pair(y,x), make_pair(y,x+1), v, dist[y][x]);
          dist[y][x+1] = min(dist[y][x+1],dist[y][x]+w);    
        }
      }
    }
    for (int y=0;y<2*v.size();y++){
      for (int x=v[0].size()-1;x>0;x--){
        if (dist[y][x]<INT_MAX){
          int w = compute_time(make_pair(y,x), make_pair(y,x-1), v, dist[y][x]);
          dist[y][x-1] = min(dist[y][x-1],dist[y][x]+w);
        }
      }
    }
    for (int x=0;x<2*v[0].size();x++){
      for (int y=0;y<2*v.size()-1;y++){
        if (dist[y][x]<INT_MAX){
          int w = compute_time(make_pair(y,x), make_pair(y+1,x), v, dist[y][x]);
          dist[y+1][x] = min(dist[y+1][x],dist[y][x]+w);
        }
      }
    }
    for (int x=0;x<2*v[0].size();x++){
      for (int y=2*v.size()-1;y>0;y--){
        if (dist[y][x]<INT_MAX){
          int w = compute_time(make_pair(y,x), make_pair(y-1,x), v, dist[y][x]);
          dist[y-1][x] = min(dist[y-1][x],dist[y][x]+w);
        }
      }
    }
  }
  return dist[0][v[0].size()*2-1];
}

int main(){
 // ifstream in("B-small-practice.in");
	//streambuf *cinbuf = cin.rdbuf();
	//cin.rdbuf(in.rdbuf());
	//ofstream out("out.txt");
	//streambuf *coutbuf = cout.rdbuf();
	//cout.rdbuf(out.rdbuf());
	  int T;
  cin>>T;
  for (int tc=1;tc<=T;tc++){
    int n,m;
    cin>>n>>m;
    vector<vector<vector<int> > > v (n, vector<vector<int> >(m, vector<int> (3,0)));
    for (int i=0;i<n;i++)
      for (int k=0;k<m;k++){
        int s,w,t;
        cin>>s>>w>>t;
        v[i][k][0]=s;
        v[i][k][1]=w;
        v[i][k][2]=t;
      }
    cout<<"Case #"<<tc<<": "<<belman_ford(v)<<"\n";
  }
}
