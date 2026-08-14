/*
LeetCode 135 - Candy
Topic: Greedy,Array
Approach: Two-pass greedy

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        int n = ratings.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        for(int i = 0;i<ratings.size();i++){
            if(i == 0 || ratings[i]<=ratings[i-1]){
                left[i] = 1;
            }
            else if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        for(int i = ratings.size()-1;i>=0;i--){
            if(i == n-1 || ratings[i]<=ratings[i+1]){
                right[i] = 1;
            }
            else if(ratings[i] > ratings[i+1]){
                right[i] = right[i+1]+1;
            }
        }
        for(int i = 0;i<n;i++){
            ans+= max(left[i],right[i]);
        }
        return ans;
    }
};
