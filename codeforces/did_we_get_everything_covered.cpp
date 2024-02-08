#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> all_possible;
unordered_set<string> to_add;
unordered_set<string> all_possible_length_n;

void get_all_possible_strings(string s, int max_l) {
    all_possible.clear();
    for (int i=0; i<s.length(); i++) {
        to_add.clear();
        string current(&s[i], 1);
        if (i==0) {
            all_possible.insert(current);
            continue;
        }
        for (auto s_ = all_possible.begin(); s_!=all_possible.end(); s_++) {
            string new_string(*s_);
            new_string += s[i];
            if (new_string.length() > max_l) continue;
            to_add.insert(new_string);
        }
        for (auto s_ = to_add.begin(); s_!=to_add.end(); s_++) {
            all_possible.insert(*s_);
        }
        all_possible.insert(current);
    }
    for (auto s_ = all_possible.begin(); s_!=all_possible.end(); s_++) {
        if ((*s_).length() == max_l) {
            all_possible_length_n.insert(*s_);
            cout << *s_ << '\n';
        }
    }
}

int main(int argc, char** argv) {
    int t;
    cin >> t;
    for (int t_=0; t_<t; t_++) {
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        get_all_possible_strings(s, k);
    }
}
