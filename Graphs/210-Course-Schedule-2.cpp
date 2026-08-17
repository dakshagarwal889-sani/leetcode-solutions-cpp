/*
LeetCode 210 - Course Scedule 2
Topic: Cycle Detection, Topological sort

Time Complexity: O(m + n)
Space Complexity: O(m + n)
*/
class Solution {
    private:
    bool dfs(int node,vector<vector<int>> &adj,vector<int> &vis,stack<int> &st,vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,st,pathVis) == true) return true;
            }
            else if(pathVis[it] == true) return true;
        }
        st.push(node);
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        vector<vector<int>> adj(numCourses);
        stack<int> st;
        vector<int> ans;
        for(auto p :prerequisites){
            int second = p[0];
            int first = p[1];
            adj[first].push_back(second);
        }
        for(int i = 0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,st,pathVis)){
                    return {};
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
