class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char c : tasks) freq[c - 'A']++;

        priority_queue<int> pq;
        for(int f : freq) {
            if(f > 0) pq.push(f);
        }

        queue<pair<int,int>> cooldown; // {time, freq}
        int time = 0;

        while(!pq.empty() || !cooldown.empty()) {
            time++;

            if(!pq.empty()) {
                int f = pq.top(); pq.pop();
                f--;

                if(f > 0) {
                    cooldown.push({time + n, f});
                }
            }

            if(!cooldown.empty() && cooldown.front().first == time) {
                pq.push(cooldown.front().second);
                cooldown.pop();
            }
        }

        return time;
    }
};