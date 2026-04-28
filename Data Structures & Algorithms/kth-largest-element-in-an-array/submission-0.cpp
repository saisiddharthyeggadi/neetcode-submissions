class Solution {
public:
    //merge function = a function which merges 2 sorted vectors
    vector<int> merge(vector<int> a, vector<int> b){
        int n = a.size(), m = b.size();
        if(n == 0) return b;
        else if(m == 0) return a;

        vector<int> res; int i = 0, j = 0;
        while(i<n && j<m){
            if( a[i] >= b[j]) {
                res.push_back(a[i]);
                i++;
            }else {
                res.push_back(b[j]);
                j++;
            }
        }
        while(i<n){
            res.push_back(a[i]);
            i++;
        }
        while(j<m){
            res.push_back(b[j]);
            j++;
        }
        return res;
    }
    /*
    2 3 1  5 4
    n is 5, n/2 is 2
    2 3 1 | 5 4

    */
    vector<int> merge_sort(vector<int> v){
        int n = v.size();
        if(n <= 1) return v;
    
        int mid = n/2;
        vector<int> left(v.begin() , v.begin() + mid);
        vector<int> right(v.begin() + mid, v.end());
        left = merge_sort(left);
        right = merge_sort(right);
        v = merge(left, right);
        return v;
    }
    int findKthLargest(vector<int>& nums, int k) {
        nums = merge_sort(nums);
        return nums[k-1];
    }
};
