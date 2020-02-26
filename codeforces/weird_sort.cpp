#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int arr[200];
int p[200];
int N;
int n, m;

int main() {
    cin >> T;
    for (int i=0; i < T; i++) {
        cin >> n >> m;
        for (int k = 0; k < n; k++) {
            cin >> arr[k];
        }
        for (int k = 0; k < m; k++) {
            cin >> p[k];
            p[k]--;
        }
        sort(p, p+m);
        vector<pair<int, int>*> segments;
        pair<int, int>* current = new pair<int, int>(-1, -1);
        for (int k = 0; k < m; k++) {
            if (k==0) {
                current->first = p[k];
            }
            else if (p[k-1]!=p[k]-1) {
                current->second = p[k-1]+1;
                segments.push_back(current);
                current = new pair<int, int>(p[k], -1);
            }
            if (k==m-1) {
                current->second = p[k]+1;
                segments.push_back(current);
            }
        }
        for (auto p : segments) {
            sort(arr + (p->first), arr + (p->second)+1);
        }
        bool sorted = true;
        for (int i=0;i<n-1;i++) {
            if (arr[i]>arr[i+1]){ sorted = false; break;}
        }
        if (sorted) 
            cout<<"YES\n";
        else 
            cout<< "NO\n";
    }
}
