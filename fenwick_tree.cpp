#include <bits/stdc++.h>
using namespace std;

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;

  // Constructor for initialization of size 
  fenwick(int _n) : n(_n + 1) {
    fenw.resize(n);
  }

  // to modify , add value at index x
  void modify(int x, T v) {
    while (x <= n) {
      fenw[x] += v;
      x += (x & -x);
    }
  }

  // To get sum of prefix ending at x
  T get(int x) {
    T v{};
    while (x > 0) {
      v += fenw[x];
      x -= (x & -x);
    }
    return v;
  }
};