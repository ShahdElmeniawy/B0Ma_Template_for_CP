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
#define ordered_set     tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set      tree<ll, null_type, greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>


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
    freopen("r.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
}


vector <vector <int> > adj1 , adj2;

string getcanonical(int v , vector < vector <string> > &subcan){
	string s = "(";
	sort(all(subcan[v]));
	for(auto &it : subcan[v]) s += it;
	s += ")";
	return s;
	
}

string treecanonicalform(vector < vector <int> > adjlst){
	
	int n = sz(adjlst);
	queue <int> leaf;
	vector <int> deg(n , - 1);
	
	int remnode = n;
	
	for(int i =0 ; i < n ; i++){
		if(sz(adjlst[i]) <= 1) leaf.push(i);
		else deg[i] = sz(adjlst[i]);
	}
	
	vector < vector < string > > subcan(n);
	
	while(remnode > 2){
		int si = sz(leaf);
		while(si--){
			int v = leaf.front();
			leaf.pop();
			string nodecanonical = getcanonical(v , subcan);
			for(auto & it : adjlst[v]){
				subcan[it].push_back(nodecanonical);
				if(--deg[it] == 1){
					leaf.push(it);
				}
			}
			--remnode;
		}
	}
	
	int v1 = leaf.front();
	leaf.pop();
	int v2 = (leaf.empty() ? -1 : leaf.front());
	
	string s1 = getcanonical(v1 , subcan);
	
	
	if(v2 == -1) return s1;
	
	string s2 = (v2 == -1 ? "" : getcanonical(v2 , subcan));
	
	subcan[v1].push_back(s2);
	subcan[v2].push_back(s1);
	
	return  min(getcanonical(v1 , subcan) , getcanonical(v2 , subcan));
	
	
}

int32_t main() {
    B0Ma();
    tc{
		int n;
		cin >> n;
		adj1.assign(n , vector <int> () );
		adj2.assign(n , vector <int> () );
		for(int i =0 ; i < n - 1; i++){
			int x , y;
			cin >> x >> y;
			x-- , y--;
			adj1[x].push_back(y);
			adj1[y].push_back(x);
		
		}
		for(int i =0 ; i < n - 1; i++){
			int x , y;
			cin >> x >> y;
			x-- , y--;
			adj2[x].push_back(y);
			adj2[y].push_back(x);
		}
		cout << treecanonicalform(adj1) << endl;
		cout << treecanonicalform(adj2) << endl;
		cout << (treecanonicalform(adj1) == treecanonicalform(adj2)? "YES\n" : "NO\n");
	}
    

}

