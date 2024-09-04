class Solution {
public:
    // vector<int> key(string s){
    //     vector<int> count(26, 0);

    //     for(char i : s){
    //         count[i - 'a']++;
    //     }

    //     return count;
    // }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(auto it : strs){
            vector<int> count(26, 0);
            for(char c : it){
                count[c - 'a']++;
            }
            mp[count].push_back(it);
        }

        vector<vector<string>> ans;

        for(auto i : mp){
            ans.push_back(i.second);
        }

        return ans;

    }
};