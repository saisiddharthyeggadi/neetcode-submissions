class Twitter {
public:
    unordered_map<int, vector<int>> followers;
    unordered_map<int, vector<int>> following;
    unordered_map<int, vector<vector<int>>> posts;
    int timestamp;

    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> q;

        // include own posts
        for(auto post : posts[userId]) q.push(post);
        for(auto following_accs : following[userId]){
            for(auto post : posts[following_accs]){
                q.push(post);
            }
        }
        vector<int> res;
        while(res.size()<10 && !q.empty()){
            res.push_back(q.top()[1]);
            q.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        for(auto followee : following[followerId]) if(followee == followeeId) return;
        following[followerId].push_back(followeeId);
        followers[followeeId].push_back(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        int n = following[followerId].size();
        for(int i=0; i<n; i++){
            if(following[followerId][i] == followeeId) {
                following[followerId].erase(following[followerId].begin()+i);
                break;
            }
        }

        int m = followers[followeeId].size();
        for(int i=0; i<m; i++){
            if(followers[followeeId][i] == followerId) {
                followers[followeeId].erase(followers[followeeId].begin()+i);
                break;
            }
        }
    }
};