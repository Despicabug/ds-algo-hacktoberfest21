class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), tmp = 0, res = 0;
        unordered_map<int, int> mp;
        mp[0] = mp[0]+1;
        for(int i = 0; i<n; i++){
            tmp += nums[i];
            res += mp[tmp - k];
            mp[tmp]++;
        }
        return res;
    }
};
//https://leetcode.com/problems/subarray-sum-equals-k/