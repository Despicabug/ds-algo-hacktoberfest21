class Solution {
public:
    unordered_map<int,bool>m;
    bool help(vector<int>&nums, int curr)
    {
        if(curr>=nums.size()-1)
            return true;
        if(m.find(curr)!=m.end())
            return m[curr];
        bool t=false;
        bool temp;
        for(int i=1;i<=nums[curr];i++)
        {  temp=help(nums,curr+i);
                 t=t||temp;
        }
        m[curr]=t;
        return m[curr];
    }
    bool canJump(vector<int>& nums) {
        return help(nums,0);
    }
};