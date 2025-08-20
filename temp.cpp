// -------------------------------------------------------------
// Competitive Programming: I/O + DEBUG Utilities (C++17)
// Toggle debug with:  -DLOCAL   (e.g., g++ -O2 -std=gnu++17 -DLOCAL)
// -------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <iterator>
#include <queue>

using namespace std;

// ========== FAST I/O (iostream) ==========
struct FastIO {
  FastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} fastio;

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

// ========== DEBUG TOOLBOX (enabled only with -DLOCAL) ==========
#ifdef LOCAL
    #define DBG(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

    inline const char* _skip_spaces(const char* s){
        while (*s==' ' || *s=='\t') ++s;
        return s;
    }

    // base
    inline void _dbg_impl(){ std::cerr << "\n"; }

    // recursive printer that keeps names aligned with values
    template<class T, class... Ts>
    void _dbg_impl(const char* names, const T& val, const Ts&... vs){
        // split on first comma
        const char* comma = std::strchr(names, ',');
        if (!comma){
            // last name -> print it all (trim leading spaces)
            names = _skip_spaces(names);
            std::cerr << names << " = " << val << " ";
            _dbg_impl();
        } else {
            // print current token [names .. comma)
            const char* start = _skip_spaces(names);
            std::cerr.write(start, comma - start) << " = " << val << " ";
            // skip comma and following spaces for the next token
            const char* next = _skip_spaces(comma + 1);
            if constexpr (sizeof...(vs) == 0){
                _dbg_impl();                   // finish line
            } else {
                _dbg_impl(next, vs...);        // recurse
            }
        }
    }

    template<class... Ts>
    void _dbg(const char* names, const Ts&... vs){
        std::cerr << "[DBG] ";
        _dbg_impl(names, vs...);
    }

    // ASSERT that prints where it failed
    #define ASSERT(expr) do { if(!(expr)){ \
        std::cerr << "[ASSERT FAIL] " << #expr << " at " << __FILE__ << ":" << __LINE__ << "\n"; \
        std::abort(); } } while(0)

    // Time a block scope
    struct Timer {
        std::string label;
        std::chrono::high_resolution_clock::time_point t0;
        Timer(std::string s = "T")
            : label(std::move(s)),  // <-- fully qualify move
              t0(std::chrono::high_resolution_clock::now()) {}
        ~Timer(){
            auto t1 = std::chrono::high_resolution_clock::now();
            auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
            std::cerr << "[TIMER] " << label << ": " << us/1000.0 << " ms\n";
        }
    };

    // Redirect from/to files quickly (handy for local testing)
    inline void freopen_local(const std::string& in="input.txt", const std::string& out="output.txt"){
        std::freopen(in.c_str(), "r", stdin);
        std::freopen(out.c_str(), "w", stdout);
    }
#else
    #define DBG(...) ((void)0)
    #define ASSERT(expr) ((void)0)
    struct Timer { Timer(std::string s=""){ (void)s; } };
    inline void freopen_local(const std::string& = "", const std::string& = "") {}
#endif

// ========== COMMON I/O UTILITIES ==========
template<class T> inline void read(T& x){ In.read(x); }
template<class T, class... Ts> inline void read(T& x, Ts&... xs){ In.read(x, xs...); }

template<class T> inline void read_vec(vector<T>& v){ for (auto& e: v) cin >> e; }
template<class T> inline void print_vec(const vector<T>& v){ Out.print_spaced(v); }

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


// ========== MAIN SKELETON ==========
void solve() {
  int n, k;
  cin >> n >> k;
}

int main() {
  int T=1;
  if (!(cin >> T)) return 0;
  while (T--) solve();
  return 0;
}