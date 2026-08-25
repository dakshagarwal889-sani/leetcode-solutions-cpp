/*
LeetCode 787 - Cheapest Flights Within K Stops
Topic: Graphs
Approach: Breadth-First Search (BFS)
Time Complexity: O(E * k)
Space Complexity: O(V + E)

Where:
V - Number of Vertices (Cities)
E - Number of Edges (Flights)
k - Maximum number of stops allowed

Replaced the usual Priority Queue used in Dijkstra' Algorithm with normal queue which helps to reduce the time complexity.
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        queue<pair<int,pair<int,int>>> q;
        vector<pair<int,int>> adj[n];
        vector<int> cost(n,1e9);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        q.push({0,{src,0}});
        cost[src] = 0;
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cos = q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it:adj[node]){
                int adjNode = it.first;
                int diff = it.second;
                if(cos+diff<cost[adjNode]){
                    cost[adjNode] = cos+diff;
                    q.push({stops+1,{adjNode,cost[adjNode]}});
                }
            }
        }
        if(cost[dst] == 1e9) return -1;
        return cost[dst];
    }
};
