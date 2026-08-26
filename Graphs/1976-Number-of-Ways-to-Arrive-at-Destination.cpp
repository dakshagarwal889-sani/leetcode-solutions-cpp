
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<vector<pair<int,long long>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> ways(n,0);
        vector<long long> dist(n,1e18);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            int node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();
            if (dis > dist[node]) continue;
            for(auto it:adj[node]){
                int adjNode = it.first;
                long long weight = it.second;
                if(dis + weight<dist[adjNode]){
                    dist[adjNode] = dis + weight;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dist[adjNode] == dis + weight){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};
