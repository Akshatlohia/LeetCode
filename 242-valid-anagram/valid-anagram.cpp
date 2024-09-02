class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(auto it : s) mp[it]++;

        for(auto i : t){
            if(mp.find(i) == mp.end()){
                return false;
            }
            else{
                mp[i]--;
            }
        }

        for(auto i : mp){
            if(i.second != 0)return false;
        }
        return true;
    }
};