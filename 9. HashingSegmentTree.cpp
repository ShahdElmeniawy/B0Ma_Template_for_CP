#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int long long
#define endl  "\n"
#define PI  3.14159265359
#define OO  50000000000
#define M0D 1000000007
#define sz(m)       (int)(m.size())
#define all(SHA)    SHA.begin(),SHA.end()
#define rall(SHA)   SHA.rbegin(),SHA.rend()
#define ordered_set     tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set      tree<int, null_type, greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>


template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (T &i: v) in >> i;
    return in;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (const T &x: v)
        out << x << ' ';
    return out;
}
const int  N = 1e7 + 5, base1 = 31, base2 = 37, mod1 = 1e7 + 7 , mod2 = 2e9 + 11;
int pw1[N] , pw2[N], n;

void init() {
    pw1[0] = pw2[0] = 1;
    for(int i = 1 ; i < N ; i++) {
        pw1[i] = (1LL * pw1[i - 1] * base1) % mod1;
        pw2[i] = (1LL * pw2[i - 1] * base2) % mod2;
    }
}
struct Hashing {
private:
    int h1, h2, len;
    string s;
    vector< pair < int , int > > seg;
    void segmenttree(int node = 1 , int start = 0 , int end = n - 1) {
        if(start == end) {
            seg[node].first = (s[start] - 'a' + 1);
            seg[node].second = (s[start] - 'a' + 1);
            return;
        }
        int mid = start + (end - start) / 2;
        segmenttree(node * 2 , start , mid);
        segmenttree(node * 2 + 1 , mid + 1 , end);
        seg[node].first = ( ( seg[node * 2].first * pw1[end - mid]) % mod1 + seg[node * 2 + 1].first ) % mod1;
        seg[node].second = ( ( seg[node * 2].second * pw2[end - mid]) % mod2 + seg[node * 2 + 1].second ) % mod2;
    }

public:
    Hashing(string s1) {
        h1 = h2 = len = 0;
        s = s1;
        int sz_sg = sz(s1) * 5 + 5;
        seg.assign(sz_sg , {0 ,0});
        segmenttree();
    }

    void updateseg(int node = 1 ,int start = 0, int end = n - 1, char c = 'a', int idx = 0) {
        if(start == end) {
            seg[node].first = (c - 'a' + 1);
            seg[node].second = (c - 'a' + 1);
            return;
        }
        int mid = start + (end - start) / 2;
        if(idx >= start && idx <= mid) {
            updateseg(node * 2 , start , mid , c , idx);
        }else {
            updateseg(node * 2 + 1 , mid + 1 , end , c, idx);
        }
        seg[node].first = ( ( seg[node * 2].first * pw1[end - mid]) % mod1 + seg[node * 2 + 1].first ) % mod1;
        seg[node].second = ( ( seg[node * 2].second * pw2[end - mid]) % mod2 + seg[node * 2 + 1].second ) % mod2;
    }

    pair < pair <int , int > , int > query(int node = 1 ,int start = 0, int end = n - 1, int l = 0, int r = 0) {
        if(l <= start && r >= end) {
            return {seg[node] , end - start + 1};
        }
        if(l > end || r < start) {
            return {{0 , 0} , 0};
        }
        int mid = start + (end - start) / 2;
        auto frh = query(node * 2 , start , mid , l , r);
        auto sch = query(node * 2 + 1 , mid + 1 , end , l , r);
        int frp = ( (frh.first.first * pw1[sch.second]) % mod1 + sch.first.first) % mod1;
        int scp = ((frh.first.second * pw2[sch.second]) % mod2 + sch.first.second) % mod2;
        return {{frp , scp}, frh.second + sch.second} ;

    }

};

void B0Ma(){
    int q;
    string s;
    cin >> n >> q >> s;
    Hashing pre(s);
    reverse(all(s));
    Hashing suf(s);
    while (q--) {
        int numq;
        cin >> numq;
        if(numq == 2) {
            int a , b;
            cin >> a >> b;
            if(pre.query(1 , 0 , n - 1 , a - 1 , b - 1).first ==
                suf.query( 1, 0, n - 1 , n - b  , n - a).first)
                cout << "YES\n";
            else cout << "NO\n";
        }else {
            int a;
            char c;
            cin >> a >> c;
            pre.updateseg(1 , 0 , n - 1, c , a - 1);
            suf.updateseg(1, 0 , n - 1 , c, n - a);
        }
    }



}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    init();
    while (tc--) {
        B0Ma();
    }
    return 0;
}
