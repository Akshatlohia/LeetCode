class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for(auto it : strs){
            string s = it;
            sort(s.begin(), s.end());
            mp[s].push_back(it);
        }

        vector<vector<string>> ans;

        for(auto i : mp){
            ans.push_back(i.second);
        }

        return ans;

    }
};