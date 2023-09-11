#include <iostream>

using namespace std;

void solve();

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

void solve() {
    int n, m;
    cin >> n;

    int fila_india[n];

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fila_india[i] = x;
    }

     cin >> m;

     int comandantes[m], subordinados[m];

     for (int i = 0; i < m; i++) {
        int c, s;
        cin >> c >> s;
        comandantes[i] = c;
        subordinados[i] = s;
     }

}