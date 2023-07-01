#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>


using namespace std;

#define ll long long
#define int long long


void B0Ma() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


#ifndef ONLINE_JUDGE
    freopen("r.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
}

int n , mx = 0 , to = 0;
vector<vector<int> > adj;

void dfs(int i , int past , int cnt = 0){
	if(mx < cnt + 1){
		mx = max(mx , cnt);
		to = i;
		}
	
	for(auto &it : adj[i]){
		if(it != past)
		dfs(it , i , cnt + 1);
	}
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
    dfs(0 , -1 , 0);
    int from = to;
    mx =0;
    dfs(from , -1 , 0);
    cout <<  from + 1<< " " << to + 1 <<" "  <<  mx;
    

}

