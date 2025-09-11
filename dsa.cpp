// -------------------------------------------------------------
// Competitive Programming: I/O + DEBUG Utilities (C++17)
// Toggle debug with:  -DLOCAL   (e.g., g++ -O2 -std=gnu++17 -DLOCAL)
// -------------------------------------------------------------
#include <bits/stdc++.h>
#include <queue>

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

// ========== SCANNER (robust, works with spaces/newlines) ==========
struct Scanner {
  template<class T> bool read(T& x) { return bool(cin >> x); }

  template<class T, class... Ts>
  bool read(T& x, Ts&... xs) {
    if (!(cin >> x)) return false;
    return read(xs...);
  }

  // read whole line (including spaces); consumes trailing '\n' if needed
  bool getline(string& s) {
    s.clear();
    if (!std::getline(cin, s)) return false;
    if (s.empty() && cin.good()) return true;
    return true;
  }

  // read vector of size n
  template<class T>
  vector<T> read_vec(int n){
    vector<T> v(n);
    rep(i,0,n) cin >> v[i];
    return v;
  }

  // read matrix n x m
  template<class T>
  vector<vector<T>> read_mat(int n, int m){
    vector<vector<T>> a(n, vector<T>(m));
    rep(i,0,n) rep(j,0,m) cin >> a[i][j];
    return a;
  }
} In;

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

// ========== COMMON I/O UTILITIES ==========
template<class T> inline void read(T& x){ In.read(x); }
template<class T, class... Ts> inline void read(T& x, Ts&... xs){ In.read(x, xs...); }

template<class T> inline void read_vec(vector<T>& v){ for (auto& e: v) cin >> e; }
template<class T> inline void print_vec(const vector<T>& v){ Out.print_spaced(v); }

template <typename T>
void print_mat(const vector<vector<T>>& matrix) {
  for (const auto& row : matrix) {
    for (const auto& elem : row) {
      cout << elem << " ";
    }
    cout << "\n";
  }
}

// Read graph edges (no algorithms; just I/O)
struct Edge { int u,v; };
vector<vector<int>> read_graph_undirected(int n, int m, bool one_indexed=true){
  vector<vector<int>> g(n);
  rep(i,0,m){
    int a,b; cin>>a>>b;
    if (one_indexed) a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  return g;
}

struct MyCustomComparator {
  bool operator()(const vector<int>& o1, const vector<int>& o2) const {
    return o1[2] > o2[2];
    // comparison logic, return true if o1 should come before o2
  }
};
// priority_queue<vector<int>, vector<vector<int>>, MyCustomComparator> pq;

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);
    
    while (end != std::string::npos) {
      tokens.push_back(str.substr(start, end - start));
      start = end + 1;
      end = str.find(delimiter, start);
    }
    
    tokens.push_back(str.substr(start));
    return tokens;
}

std::priority_queue<ll, std::vector<ll>, std::greater<ll>> queue;

// ========== MAIN SKELETON ==========
void solve() {
  int n, k;
  cin >> n >> k;
}

int main() {
  priority_queue<vector<int>, vector<vector<int>>, MyCustomComparator> pq;

  pq.push

  int T=1;
  if (!(cin >> T)) return 0;
  while (T--) solve();
  return 0;
}