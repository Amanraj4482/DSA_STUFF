<snippet>
	<content><![CDATA[
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define bl cerr<<"\n";
#define en cout<<"\n";
#define int long long

#define AmanRaj ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);freopen("error.txt", "w", stderr);
#define dash cerr << "-------------------";bl
#define cserror(i) cerr << "Case " << i << ": ";bl
#define csoutput(i) cout << "Case " << i << ": ";en
typedef long double lld;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vc> vcc;
typedef vector<vb> vbb;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef vector<pii> vpi;
typedef vector<pci> vpc;

#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mk make_pair
#define ff first
#define mid(i,j) (i+(j-i)/2)
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define mine(x) *min_element(all(x))
#define maxe(x) *max_element(all(x))
#define input(x,n) for(int i=0;i<n;i++){cin>>x[i];}
#define each(x) for(auto it:x){cout<<it<<" ";}cout<<endl;
#define tr(it, mp) for(auto it = mp.begin(); it != mp.end(); ++it)

#define OL4(_1, _2, _3, _4, name, ...) name
#define L1(n) for (int UN = 0; UN < (n); ++UN)
#define L2(i, n) for (int i = 0; i < (n); ++i)
#define L3(i, a, b) for (int i = (a); i < (b); ++i)
#define L4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define L(...) OL4(__VA_ARGS__, L4, L3, L2, L1)(__VA_ARGS__)
#define R1(n) for(int i = (n-1);i >=0;--i)
#define R2(i,k) for(int i = (k-1);i >=0;--i)
#define R3(i,j,k) for(int i = (j-1);i >(k);--i)
#define R4(i,j,k,c) for(int i = (j-1); i >=(k) ;i -= c)
#define R(...) OL4(__VA_ARGS__, R4, R3, R2, R1)(__VA_ARGS__)

void _print(int t) {cerr << t;} void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;} void _print(bool t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);

template<class... T> void out(T && ... s) {((cout << s << endl), ...); }; /*endl*/
template<class... T> void outs(T && ... s) {((cout << s << " "), ...); en }; /*space*/

#define OL5(_a,_b,_c,_d,_e,f, ...) f
#define p1(x) cerr<<#x<<" "; _print(x); bl
#define p2(x,y) cerr<<"("<<#x<<" "<<x<<" "<<#y<<" "<<y<<")";bl
#define p3(x,y,a) cerr<<"("<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#a<<" "<<a<<")";bl
#define p4(x,y,a,b) cerr<<"("<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#a<<" "<<a<<" "<<#b<<" "<<b<<")";bl
#define p5(x,y,a,b,c) cerr<<"("<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<")";bl

#ifndef ONLINE_JUDGE
#define p(...) OL5(__VA_ARGS__,p5, p4, p3, p2, p1)(__VA_ARGS__)
#else
#define p(...) void(0);
#endif

template <class T, class V> void _print(map <T, V> v); template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define CountSetBit(x) cout<<__builtin_popcountll(x);en
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int digitSum(int n) {int ret = 0; while (n) {ret += n % 10; n /= 10;} return ret;}
int sumarr(vi & v, int n) {int d = 0; for (int i = 0; i < n; i++)d += v[i]; return d;}
void printBinaryNum(int x) {for (int i = 10; i >= 0; i--)cout << ((x >> i) & 1); en}
bool checkPrime(int a) { if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return 0; return 1; }
bool isPalindrome(string s) {int i = 0, j = sz(s) - 1; while (i <= j) {if (s[i] != s[j])return 0; i++; j--; } return 1;}
//int countDigits = log10(num) + 1; /*12345->5*/

int BitPow(int a, int b) {int ans = 1; while (b) {if (b & 1) {ans  = (ans * a);} b >>= 1; a = (a * a);} return ans;}
int BitPowMod(int a, int b, int mod) {int ans = 1; while (b) {if (b & 1) {ans  = (ans * a) % mod;} b >>= 1; a = (a * a) % mod;} return ans % mod;}

int ceil_div(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}
void DeleteItem(vi &v, int x) { /*deletes element from vec*/
	int index = lower_bound(all(v), x) - v.begin();
	v.erase(v.begin() + index);
}

//Sorting
bool sorta(pii &a, pii &b) {return (a.ss < b.ss);}
bool sortd(pii &a, pii &b) {return (a.ss > b.ss);}

bool isPerfectSquare(int x) {if (x >= 0) {int sr = sqrt(x); return (sr * sr == x);} return false;}

int isSubstring(string a, string b) { /*check a is substr of b */
	if (b.find(a) != string::npos)return b.find(a);
	return -1;
}

void solve() {
	$0
}

signed main() {
	AmanRaj
	$1
	return 0;
}


]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>code</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>
