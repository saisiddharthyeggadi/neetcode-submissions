class Solution {
public:
    void combinations(int idx, vector<int> combination, vector<int>&nums, int target, vector<vector<int>> &ans){
        if(target == 0) {
            ans.push_back(combination);
            return;
        }else if(target == 1) return;
        
        for(int i=idx; i<nums.size(); i++){
            if(target-nums[i] < 0)break;
            combination.push_back(nums[i]);
            cout << nums[i] << endl;
            combinations(i, combination, nums, target-nums[i], ans);
            
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        combinations(0, {}, nums, target, ans);
        return ans;
    }
};
