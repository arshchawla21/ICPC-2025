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
  int r, c;
  cin >> r >> c;

  string top;
  cin >> top;

  vector<int> score(c);
  for (int i = 0; i < c; ++i) {
    score[i] = 1;
  }

  rep(i, 1, r) {
    string tmp = "";
    cin >> tmp;
    rep(k, 0, c) {
      if (tmp[k] != top[k]) {
        score[k] = 0;
      }
    }
  }

  int max_score = 0;
  int running = 0;

  rep(i, 0, c) {
    if (score[i] == 0) {
      running = 0;
    } else {
      running++;
      max_score = max(max_score, running);
    }
  }

  cout << max_score << endl;

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // int T=1;
  // if (!(cin >> T)) return 0;
  // while (T--) solve();
  solve();
  return 0;
}