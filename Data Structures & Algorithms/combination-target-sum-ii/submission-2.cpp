class Solution {
public:
    void combinations(int idx, vector<int> &combination, int target, vector<int> &nums, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(combination);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]) continue; // skip duplicates

            if(nums[i] > target) break; // pruning

            combination.push_back(nums[i]);
            combinations(i+1, combination, target-nums[i], nums, ans);
            combination.pop_back();
        }        
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combination;
        combinations(0, combination, target, candidates, ans);
        return ans;
    }
};