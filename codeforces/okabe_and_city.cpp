#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
#define FOR(i,a) for (int i=0;i<a;i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define pb push_back
#define f first
#define s second

int n,m,k;
vector<pii> lights;
map<pii,int> label;
priority_queue<pii> todo;
int dist[10000];
vi rows[10000];
vi cols[10000];
int dr[10000];
int dc[10000];
int xdir[4] = {-1,0,0,1}, ydir[4] = {0,1,-1,0};

void add_row(int idx, int val){
  if (idx>=0 && idx<n && dr[idx]==0){
    dr[idx]=1;
    for (int x : rows[idx]) //if (val<dist[idx])
    {
      dist[x] = val;
      todo.push({-dist[x], x});
    }
  }
}

void add_col(int idx, int val){
  if (idx>=0 && idx<m && dc[idx]==0){
    dc[idx]=1;
    for (int x : cols[idx]) //if (val<dist[idx])
    {
      dist[idx] = val;
      todo.push({-dist[idx], idx});
    }
  }
}

void ad(int x, int y, int val){
  if (label.find(pii(x,y)) != label.end())
    if (dist[label[pii(x,y)]] > val){
      dist[label[pii(x,y)]] = val;
      todo.push(pii(-val, label[pii(x,y)]));
    }
}

int main(){
  cin>>n>>m>>k; 
  FOR(i,k){
    int r,c; 
    cin>>r>>c;
    lights.pb(pii(r-1,c-1));
    rows[r-1].pb(i);
    cols[c-1].pb(i);
    label[pii(r-1,c-1)]=i;
  }
  FOR(i,k) dist[i] = 100000001;
  
  if (label.find(pii(n-1,m-1))==label.end()){
    add_row(n-2,1);
    add_row(n-1,1);
    add_col(m-1,1);
    add_col(m,1);
  } else todo.push(pii(0,label[pii(n-1,m-1)]));
  
  while(todo.size()){
    auto a = todo.top(); todo.pop();
    a.f = -a.f;
    FOR(i,4) ad(lights[a.s].f+xdir[i], lights[a.s].s+ydir[i], a.f);
    for (int i=lights[a.s].f-2; i<lights[a.s].f+3; i++) add_row(i,a.f+1);
     
    for (int i=lights[a.s].s-2; i<lights[a.s].s+3; i++) add_col(i,a.f+1);
  } 
  if (dist[0]!=100000001)cout<<dist[0]<<"\n";
   else cout<<-1; 
}
