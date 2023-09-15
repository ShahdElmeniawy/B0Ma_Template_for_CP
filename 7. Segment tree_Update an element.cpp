#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define ll long long
#define int ll
#define endl  "\n"
#define nl  "\n"
#define PI  3.14159265359
#define OO  50000000000
#define M0D 1000000007
#define sz(m)       (ll)(m.size())
#define all(SHA)    SHA.begin(),SHA.end()
#define rall(SHA)   SHA.rbegin(),SHA.rend()
#define TIME        cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define cin2(m)     for(auto& it : m){for(auto& jt : it ){ cin>>jt; } }
#define cout2(m)    for(auto& it : m){for(auto& jt : it ){ cout<<jt << " "; } cout<<endl; }
#define cin(m)     for(auto& it : m)cout<<it
#define cout(m)     for(auto& it : m)cout<<it
#define ordered_set     tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set      tree<ll, null_type, greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>


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

//ordered_set s
//s.order_of_key( Thekey )
//s.find_by_order( indx )
//__builtin_popcountll(x) num of ones



/* B0Ma
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      لو كان سهلاً لفعله الجميع...
                                      Don't tell people your plans, show them your results.
*/

void B0Ma() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int n;
vector<int> v, seg(1e6 + 5);

void segtree(int node = 1, int start = 0, int end = n - 1) {
    if (start == end) {
        seg[node] = v[start];
        return;
    }
    int mid = (start + end) / 2;
    segtree(node * 2, start, mid);
    segtree(node * 2 + 1, mid + 1, end);
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}

int query(int node, int start, int end, int l, int r) {
    if (l > end or r < start) return LONG_LONG_MAX;
    if (start >= l and end <= r) return seg[node];
    int mid = (start + end) / 2;
    return min(query(node * 2, start, mid, l, r), query(node * 2 + 1, mid + 1, end, l, r));

}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        seg[node] = val;
        v[idx] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx >= start and idx <= mid) update(node * 2, start, mid, idx, val);
    else update(node * 2 + 1, mid + 1, end, idx, val);
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);

}

int32_t main() {
    B0Ma();
    cin >> n;
    v.assign(n, 0);
    cin >> v;
    int q;
    cin >> q;
    segtree();
    while (q--) {
        char c;
        cin >> c;
        int l, r;
        cin >> l >> r;
        if (c == 'U') {
            int val;
            cin >> val;
            update(1, 0, n - 1, r, val);
        } else cout << query(1, 0, n - 1, l, r) << endl;
    }

}