#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define ll long long
#define int long long
#define endl  "\n"
#define PI  3.14159265359
#define OO  2000000000
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
//__builtin_popcount(x) num of ones



/* B0Ma
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      لو كان سهلاً لفعله الجميع....
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
vector<vector<int> > adj;


pair<int, int> diameter(int i, int x) {
    int diam = 0;
    int mxhights[3] = {-1, -1, -1};
    for (auto &it: adj[i]) {
        if (it != x) {
            pair<int, int> ret = diameter(it, i);
            diam = max(diam, ret.first);
            mxhights[0] = ret.second + 1;
            sort(mxhights, mxhights + 3);
        }
    }
    for (int j = 0; j < 3; j++) {
        if (mxhights[j] == -1) mxhights[j] = 0;
    }
    diam = max(diam, mxhights[1] + mxhights[2]);
    return make_pair(diam, mxhights[2]);
}

int32_t main() {
    B0Ma();
    cin >> n;
    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    pair<int, int> ou = diameter(0, -1);
    cout << ou.first;


}
