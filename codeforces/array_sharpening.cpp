#include<iostream>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    int* answers = new int[t];
    for (int t_ = 0; t_<t; t_++) {
        cin >> n;
        int maxPrefix = -1; 
        int maxSuffix = n+1;
        for (int n_ = 0; n_ < n; n_++) {
            int a;
            cin >> a;
            if (a>=n_ && maxPrefix == n_-1) maxPrefix = n_;
            if (a>=(n-n_-1)) {
                if (maxSuffix == n+1)
                    maxSuffix = n_;
            } else {
                maxSuffix = n+1;
            }
        }
        if (maxPrefix >= maxSuffix) answers[t_] = true;
        else answers[t_] = false;
    }
    for (int t_ = 0; t_<t; t_++) {
        if (answers[t_]) cout << "Yes\n";
        else cout << "No\n";
    }
}
