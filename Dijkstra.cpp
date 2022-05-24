struct edge {
    int from, to, w;
    edge(int from, int to, int w) : from(from), to(to), w(w) {}
    bool operator < (const edge& e)const {
        return w > e.w;
    }
};
int Dijkstra(vector<vector<edge>>adjList, int src, int dest = -1) {
    int n = sz(adjList);
    vector<int>dist(n, 1e9), prev(n, -1);
    dist[src] = 0;
    priority_queue<edge>q;
    q.push(edge(-1, src, 0));
    while (!q.empty()) {
        edge e = q.top(); q.pop();
        if (e.w > dist[e.to]) continue;
        prev[e.to] = e.from;
        for (int j = 0; j < sz(adjList[e.to]); ++j) {
            edge ne = adjList[e.to][j];
            if (dist[ne.to] > dist[ne.from] + ne.w) {
                ne.w = dist[ne.to] = dist[ne.from] + ne.w;
                q.push(ne);
            }
        }
    }
    return dest == -1 ? -1 : dist[dest];
}
