#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

class MedianFinder {

public:

    int c;

    priority_queue<int, vector<int>, less<int> > m1;
    priority_queue<int, vector<int>, greater<int> > m2;

    MedianFinder() {
        cout << "initializing MedianFinder\n";
        c = 0;
    }

    void addNum(int num) {
        double current_median = findMedian();
        if (num > current_median) m2.push(num);
        else m1.push(num);
        int s1 = m1.size();
        int s2 = m2.size();
        if ((s1 - s2) == 2) { m2.push(m1.top()); m1.pop(); }
        else if (s2 > s1) { m1.push(m2.top()); m2.pop(); }
        
    }

    double findMedian() {
        int s1 = m1.size();
        int s2 = m2.size();
        if (s1 == 0) return 1000000.0;
        if (s2 == 0) return m1.top();
        if (s1 == s2) return ((double)(m1.top() + m2.top())) / 2;
        else return m1.top();
    }
};

int main(int argc, char** argv) {
    
    MedianFinder mf;
    for (int i=1; i<4; i++) {
        mf.addNum(i);
        cout << "current: " << mf.findMedian() << '\n';
    }
}
