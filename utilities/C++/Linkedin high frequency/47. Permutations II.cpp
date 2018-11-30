class Solution {
// 47. Permutations II
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// Example:

// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> unique_nums;
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        vector<int> count;
        for(int item:nums){
            m[item]++;
        }
        for(auto it:m){
            unique_nums.push_back(it.first);
            count.push_back(it.second);
        }
        vector<int> cur;
        dfs(unique_nums, count, cur, res, nums.size());
        return res;
        
    }
    void dfs(vector<int>& nums, vector<int>& count, vector<int> cur, vector<vector<int>>& res, int total){
        if(cur.size()==total){
            res.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(count[i]>0){
                count[i]--;
                cur.push_back(nums[i]);
                dfs(nums, count, cur, res, total);
                cur.pop_back();
                count[i]++;
            }
        }
        
    }
};