#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    cout <<'\n';
    while (t--) {
        int n, x;
        cin >> n >> x;
        int* a = new int[n];
        int maxa = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            maxa = max(a[i], maxa);
        }
        int count = 0;
        for (int i=0; i< n; i++) {
            if (a[i] == x) {
                count = 1;
            }
        }
        if (count == 0) {
            int temp = x/maxa;
            temp = maxa*temp < x ? temp+1 : temp;
            count = max(2, temp);
        }
        cout << count <<'\n';
    }
}
