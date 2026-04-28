class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1){
            return {nums};
        }

        vector<vector<int>> permutations;
        for(int i=0; i<nums.size(); i++){
            vector<int> temp = nums;
            temp.erase(temp.begin()+i);
            vector<vector<int>> curr_permutations = permute(temp);
            for(auto permutation : curr_permutations){
                permutation.insert(permutation.begin(), nums[i]);
                permutations.push_back(permutation);
            }
        }
        return permutations;
    }
};
