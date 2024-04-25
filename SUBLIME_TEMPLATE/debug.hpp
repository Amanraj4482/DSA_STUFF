#include <bits/stdc++.h>
using namespace std;
template <typename _a1> void __f (const char* ___, _a1&& _b1) { cerr << ___ << " " << _b1 << endl; } template <typename _a1, typename... _a_> void __f (const char* __n, _a1&& _b1, _a_&&... _b_) {const char* _c = strchr (__n + 1, ','); cerr.write (__n, _c - __n) << " " << _b1 << ","; __f (_c + 1, _b_...); } template<class T, class S> ostream& operator << (ostream &o, const pair<T, S> &p) {return o << '(' << p.first << "," << p.second << ')'; } template<template<class, class...> class T, class... A> typename enable_if < !is_same<T<A...>, string>(), ostream& >::type operator << (ostream &o, T<A...> V) {o << "[ "; for (auto a : V) o << a << " "; return o << "]"; }
#ifndef ONLINE_JUDGE
template<class... T> void p(T && ...s) {((cerr << s << " "), ...); cerr << endl; };
#else
#define p(...)
#endif
#ifndef ONLINE_JUDGE
#define p(...)  __f (#__VA_ARGS__, __VA_ARGS__);
#define show(x) {cerr<<"Case "<<x<<": \n";};
#define bl cerr<<'\n';
#endif

