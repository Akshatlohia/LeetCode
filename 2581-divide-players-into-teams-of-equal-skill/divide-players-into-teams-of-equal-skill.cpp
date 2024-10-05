class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        int sum = 0;
        for(int s : skill){
            sum+=s;
        }
        if(sum%(n/2) != 0)return -1;
        int target = sum/(n/2);

        unordered_map<int, int> mpp;
        for(int s : skill){
            mpp[s]++;
        }
        long long ans=0;

        for(int s : skill){
            if(mpp[s]==0) continue;

            long long pair = target - s;
            if(mpp[pair]==0) return -1;

            ans+= (long long)s * pair;
            mpp[s]--;
            mpp[pair]--;
        }

        return ans;

    }
};