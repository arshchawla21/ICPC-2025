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

// ========== PRINTERS ==========
struct Printer {
  template<class T>
  void println(const T& x){ cout << x << '\n'; }

  template<class T>
  void print_spaced(const vector<T>& v){
    for (int i=0;i<sz(v);++i){ if(i) cout << ' '; cout << v[i]; }
    cout << '\n';
  }

  // join any iterable by a delimiter (default space)
  template<class It>
  void join(It first, It last, const string& delim = " "){
    bool first_out = true;
    for (; first!=last; ++first){
      if (!first_out) cout << delim;
      first_out = false;
      cout << *first;
    }
  }
} Out;

// ========== STREAM OVERLOADS (pairs & containers) ==========
template<class A, class B>
ostream& operator<<(ostream& os, const pair<A,B>& p){
  return os << '(' << p.first << ',' << p.second << ')';
}
template<class T, class Alloc, template<class,class> class C>
ostream& _print_container(ostream& os, const C<T,Alloc>& v){
  os << '{';
  bool f = true;
  for (auto& x : v){ if(!f) os << ','; f=false; os << x; }
  return os << '}';
}
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){ return _print_container(os, v); }
template<class T> ostream& operator<<(ostream& os, const deque<T>& v){ return _print_container(os, v); }
template<class T> ostream& operator<<(ostream& os, const list<T>& v){ return _print_container(os, v); }
template<class T> ostream& operator<<(ostream& os, const set<T>& v){ return _print_container(os, v); }
template<class T> ostream& operator<<(ostream& os, const multiset<T>& v){ return _print_container(os, v); }
template<class K,class V> ostream& operator<<(ostream& os, const map<K,V>& v){ 
    os << '{'; bool f=true; for (auto& [k,val]: v){ if(!f) os << ','; f=false; os << k << "->" << val; } 
    return os << '}';
}

template<class T> inline void read_vec(vector<T>& v){ for (auto& e: v) cin >> e; }
template<class T> inline void print_vec(const vector<T>& v){ Out.print_spaced(v); }

// ========== MAIN SKELETON ==========
void solve() {
  int n, m;
  cin >> n >> m;

  // Read the m lists
  vector<vector<int>> list_pairs(m);
  for (int i = 0; i < m; ++i) {
    int k; cin >> k;
    list_pairs[i].resize(k);
    for (int j = 0; j < k; ++j) cin >> list_pairs[i][j];
  }

  // Build adjacency: nodes are 1..n
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i <= n; ++i) {
    int tmp; cin >> tmp;            // which list index (1..m)
    adj[i] = list_pairs[tmp - 1];   // copy neighbors
  }

  // BFS
  vector<int> dist(n + 1, -1);
  deque<int> q;
  dist[1] = 0;
  q.push_back(1);

  while (!q.empty()) {
    int u = q.front(); q.pop_front();
    if (u == n) break;
    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push_back(v);
      }
    }
  }

  cout << dist[n] << '\n';
}

int main() {
  solve();
  return 0;
}