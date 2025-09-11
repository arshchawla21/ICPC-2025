// -------------------------------------------------------------
// Competitive Programming: I/O + DEBUG Utilities (C++17)
// Toggle debug with:  -DLOCAL   (e.g., g++ -O2 -std=gnu++17 -DLOCAL)
// ------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

// ========== TYPE ALIASES & MACROS ==========
using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
#define rep(i,a,b) for (int i=(a); i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second

// ========== MAIN SKELETON ==========
void solve() {
  int n;
  cin >> n;
  
  vector<int> A(n);
  for (auto &elem : A) {
    cin >> elem;
  }

  vector<int> ops;
  int iter = 0;

  while (iter < n) {
    int i = 0;
    cout << "moving: " << A[i] << endl;
    int cur_elem = A[i];
    int cnt = 0;
    rep(j, 1, sz(A)) {
      cout << "comparing: " << A[j] << ", " << A[j-1] << endl;
      if (cur_elem > A[j]) {
        cnt++;
        // swap 
        int tmp = A[j];
        A[j] = cur_elem;
        A[j-1] = tmp;
      }
    }
    if 
    ops.push_back(cnt);
    iter++;
  }

  rep(i, 0, sz(ops)) {
    cout << ops[i] << ", ";
  }
  cout << endl;

}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);

  // int T=1;
  // if (!(cin >> T)) return 0;
  // while (T--) solve();
  solve();
  return 0;
}