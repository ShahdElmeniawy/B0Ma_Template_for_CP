struct Edge {
    int to, from, cost;
};

int n, v, t, m;
vector<Edge> edges;
const int INF = 1000000000;


int32_t main() {
    B0Ma();
    cin >> n >> m >> v >> t;
    edges.assign(n, {0, 0, 0});
    for (int i = 0; i < n; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }
    vector<int> d(m + 1, INF);
    d[v] = 0;
    vector<int> p(m + 1, -1);
    int x;
    for (int i = 0; i < 2 * n; ++i) {
        bool any = false;
        x = -1;
        for (Edge e: edges)
            if (d[e.from] < INF) {
                if (d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = d[e.from] + e.cost;
                    p[e.to] = e.from;
                    any = true;
                    x = e.to;
                }
            }

        if (!any)
            break;
    }
    if (x == -1) {

        if (d[t] == INF)
            cout << "No path from " << v << " to " << t << ".";
        else {
            vector<int> path;
            for (int cur = t; cur != -1; cur = p[cur])
                path.push_back(cur);
            reverse(path.begin(), path.end());

            cout << "Path from " << v << " to " << t << ": ";
            for (int u: path)
                cout << u << ' ';
        }
    } else {
        int y = x;
        for (int i = 0; i < n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur = y;; cur = p[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());

        cout << "Negative cycle: ";
        for (int u: path)
            cout << u << ' ';
    }
}
