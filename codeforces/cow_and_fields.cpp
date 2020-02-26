#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bfs(vector<vector<int> > roads, int* dist, int s) {
    int* visited = new int[roads.size()];
    for (int i=0; i<roads.size(); i++) {visited[i] = 0;}
    int* q = new int[roads.size()];
    int qt = 0;
    int ql = 1;
    q[0] = s;
    dist[s] = 0;
    visited[s] = 1;
    while(qt<ql) {
        int x = q[qt++];
        vector<int> r = roads[x];
        for (int r_:r) {
           if (!visited[r_]) { 
               dist[r_] = dist[x] + 1; 
               q[ql++] = r_; 
           }
           visited[r_] = 1; 
        }        
    }
}

int main() {
     int n, m, k;
     cin >> n >> m >> k;
     int* a = new int[k];
     vector<vector<int> > roads(n, vector<int>());
     int* distFromZero = new int[n];
     int* distFromN = new int[n];
     for (int i=0; i<k; i++) {
         cin >> a[i];
         a[i]--;
     }
     for (int i=0; i<m; i++) {
         int x, y;
         cin >> x >> y;
         x--;
         y--;
         roads[x].push_back(y);
         roads[y].push_back(x); 
     }
     bfs(roads, distFromZero, 0); 
     bfs(roads, distFromN, n-1); 
     vector<pair<int,int> > data;
     for (int i=0; i<k; i++) { 
         data.push_back(pair<int,int>(distFromZero[a[i]] - distFromN[a[i]], a[i])); 
     }
     sort(data.begin(), data.end());
     int best = 0;
     int max = -1*(1e9); 
     for (auto d:data) {
         int r = d.second;
         best = std::max(best, max+distFromN[r]);
         max = std::max(max, distFromZero[r]);
     }
     cout << std::min(distFromZero[n-1], best+1) << '\n';
}
