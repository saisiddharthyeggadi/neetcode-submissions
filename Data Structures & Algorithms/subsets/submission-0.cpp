class Solution {
public:
//number of unique subsets
    void uniques(vector<int> subset, int idx, vector<vector<int>> &ans, vector<int> &nums){
        if(idx >= nums.size()){
            ans.push_back(subset);
            return;
        }
        //notTake
        uniques(subset, idx+1, ans, nums);
        //take
        subset.push_back(nums[idx]);
        uniques(subset, idx+1, ans, nums);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        uniques({}, 0, ans, nums);
        return ans;
    }
};
