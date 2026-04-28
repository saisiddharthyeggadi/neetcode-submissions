class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> p;
        for(auto &temp : points){
            int dist = temp[0]*temp[0] + temp[1]*temp[1];
            p.push_back(make_pair(dist, temp));
        }
        sort(p.begin(), p.end());
        vector<vector<int>> ans;
        for(int i=0; i<k; i++) ans.push_back(p[i].second);

        return ans;
    }
};
