#include<utility> //pair
#include<queue> //queue
#include<functional> //greater
#include<cstring> //memset

const int MAXN = 10005;
const int MAXM = 20005;
int head[MAXN], nxt[MAXM], to[MAXM], weight[MAXM], dist[MAXM];
bool vis[MAXN];

void dijkstra(int start){
	memset(vis, 0, sizeof(vis)); //多次调用初始化 
	memset(dist, 0x3f, sizeof(dist));
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, start});
	while (!pq.empty()){
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = head[u];i ; i = nxt[i]){
			int v = to[i];
			int w = weight[i];
			if (dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
				
			}
		}
	}
}