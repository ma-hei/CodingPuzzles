#include <bits/stdc++.h>

using namespace std;

int main() {


    long long int i = 1;
    long long int k = i;
    while (i>0) {
        i = i << 1;
        if (i > 0) k = i;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long int a,b,r;
        cin >> a >> b >> r;
        if (a == b) {
            cout << "0\n";
            continue;
        }
        if (r == 0) {
            cout << abs(a-b) << '\n';
            continue;
        }
        long long int k_ = k;
        while (k_ > r) {
            k_ = k_ >> 1;
        }
        cout << "check: " << k_ << '\n';
        while ((a & k_) == (b & k_) ) {
            k_ = k_ >> 1;
        }
        if ((k_ > a) || (k_ > b)) {
            k_ = k_ >> 1;
        }
        long long int larger = a > b ? a : b;
        long long int smaller = a > b ? b : a;
        long long int r_ = 0;
        cout << "check2 " << k_ << " " << smaller << '\n';
        while (k_ > 0) {
            if (((k_ & smaller) == 0) && ((k_ & larger) == 1)) {
                r_ += k_;
            }
            k_ = k_ >> 1;
        }
        cout << r_ << '\n';
    }

}