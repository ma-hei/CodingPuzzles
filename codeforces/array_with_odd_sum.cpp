#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int* ans = new int[t];
    for (int t_ = 0; t_ < t; t_++) {
        int n;
        cin >> n;
        int odd = 0;
        int even = 0;
        for (int n_ = 0; n_ < n; n_++) { 
            int a;
            cin >> a;
            if (a%2 == 0) even++;
            else odd ++;
        }
        if ((odd%2 == 1) || (odd > 0 && even > 0)) ans[t_] = 1;
        else ans[t_] = 0;
    }
    for (int t_ = 0; t_ < t; t_++) 
        if (ans[t_]) cout << "YES\n";
        else cout << "NO\n";
}
