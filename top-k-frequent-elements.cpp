
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        vector<vector<int>>buckets(nums.size()+1);
        for(auto p:mpp){
            buckets[p.second].push_back(p.first);
        }
        vector<int> ans;
        for(int i=nums.size(); i>0 && ans.size()<k; i--){
            for(int num:buckets[i]){
                ans.push_back(num);
                if(ans.size()==k) break;
            }
        }
        return ans;
    }
};