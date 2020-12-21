#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fori(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
typedef vector<long long> vi;
typedef pair<long long, long long> pi;
typedef set<long long> si;

double eps = 1e-9;

using namespace std;

struct Item {
    char value;
    int frequency;
};

struct Node {
    int value;
    Item left;
    Item right;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < 10; ++i) {
        cout << s[i];
    }

    /* map<char, int> m; */

    /* for (char c : s) { */
    /*     m[c] += 1; */
    /* } */

    /* for (auto elem : m) { */
    /*     cout << elem.first << " " << elem.second << "\n"; */
    /* } */
}
