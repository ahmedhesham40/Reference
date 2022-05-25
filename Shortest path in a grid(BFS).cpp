void bfs()
{
    queue<pair<int, int>>q;
    q.push(st);
    vis[st] = 1;
    
    len[st] = 0;
    int dep;
    while (!q.empty()) {
        pair<int, int>cur = q.front(); q.pop();
        
        dep = len[cur];
        for (int i = 0; i < 4; ++i) {
            if (valid(cur.first + dx[i], cur.second + dy[i]) && !vis[{cur.first + dx[i], cur.second + dy[i]}]) {
                //cout << cur.first + dx[i] << ' ' << cur.second + dy[i] << endl;
                q.push({ cur.first + dx[i], cur.second + dy[i] });
                vis[{cur.first + dx[i], cur.second + dy[i]}] = 1;
                len[{cur.first + dx[i], cur.second + dy[i]}] = dep + 1;
                
                if (cur.first + dx[i] == en.first && cur.second + dy[i] == en.second) {
                    found = true;
                    break;
                }
            }
        }
        if (found)break;
    }
}
