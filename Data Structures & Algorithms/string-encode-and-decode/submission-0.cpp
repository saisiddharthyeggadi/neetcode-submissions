class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s : strs) {
            res += to_string(s.size());
            res += '#';
            res += s;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0, start = 0;
        int n = s.size();
        vector<string>res;
        while (i<n){
            while(s[i]!='#') i++;
            int word_l = stoi(s.substr(start, i-start));
            res.push_back(s.substr(i+1, word_l));
            start = i + word_l + 1;
            i = start;
        }
        return res;
    }
};
