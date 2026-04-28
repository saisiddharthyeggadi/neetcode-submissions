class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> ct(26, 0);
        for(char c : tasks) ct[c - 'A']++;

        int maxFreq = *max_element(ct.begin(), ct.end());

        int countMaxFreq = 0;
        for(int x : ct) {
            if(x == maxFreq) countMaxFreq++;
        }

        int part = (maxFreq - 1) * (n + 1) + countMaxFreq;

        return max((int)tasks.size(), part);
    }
};