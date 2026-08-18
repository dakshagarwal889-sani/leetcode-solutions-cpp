/*
LeetCode 2050 - Parallel Courses III.
Topic: Kahn's Algorithm, BFS
Handled 1-indexed to 0-indexed graph conversion.

Optimized space and time by tracking the global maximum time dynamically during the BFS traversal instead of a separate final pass.

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> vis(n);
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        vector<int> maxTime(n,0);
        maxTime = time;
        queue<int> q;
        for(auto r:relations){
            int first = r[0]-1;
            int second = r[1]-1;
            adj[first].push_back(second);
            indegree[second]++;
        }
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans = max(ans, maxTime[node]);
            for(auto it: adj[node]){
                maxTime[it] = max(maxTime[it],maxTime[node] + time[it]);
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return ans;
    }
};
