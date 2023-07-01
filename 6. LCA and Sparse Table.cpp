#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define ll long long
#define int long long
#define endl  "\n"
#define PI  3.14159265359
#define sz(m)       (ll)(m.size())
#define all(SHA)    SHA.begin(),SHA.end()
#define rall(SHA)   SHA.rbegin(),SHA.rend()
#define tc          ll testcase;   cin>>testcase;   while(testcase--)



void B0Ma() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


#ifndef ONLINE_JUDGE
    freopen("r.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
}

int dp[100100][32] , depth[100100];
vector < vector <int> > adj;

void dfs(int node , int parent){
	dp[node][0] = parent;
	for(auto &it : adj[node]){
		if(it == parent) continue;
		depth[it] = depth[node] + 1;
		dfs(it , node);
	}
}
	
int lca(int u , int v){
	if(depth[u] < depth[v])
		swap(u , v);
	for(int i = 30 ; i >= 0 ; i--){
		if(depth[u] - (1 << i) >= depth[v])
			u = dp[u][i];
	}
	if(u == v) return u;
	for(int i = 30 ; i >= 0 ; i--){
		if(dp[u][i] != dp[v][i])
			u = dp[u][i] , v=dp[u][i];
	}
	return dp[u][0];
		
}

int32_t main() {
    B0Ma();
    int n;
    cin >> n;
    adj.assign(n + 1, vector<int>());
    for(int i = 0 ; i < n - 1 ; i++){
		int x , y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(dp , -1 , sizeof dp);
	dfs(1 , -1);
	
	for(int i = 1 ; i < 30 ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(dp[j][i - 1] != -1)
				dp[j][i] = dp[dp[j][i - 1]][i - 1];
		}
	}
	
	cout << lca(2 , 3) ;
	
	
		
    
    

}

