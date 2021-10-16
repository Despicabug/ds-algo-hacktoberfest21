// Question Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution
{
private:
    int findPivot(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0, e = n - 1;
        while (s <= e)
        {
            int m = s + ((e - s) / 2);
            if (m > 0 && nums[m] < nums[m - 1])
                return m;
            if (m < n - 1 && nums[m] > nums[m + 1])
                return m + 1;
            if (nums[s] == nums[m] && nums[m] == nums[e])
            {
                if (s < n - 1 && nums[s] > nums[s + 1])
                    return s + 1;
                s++;
                if (e > 0 && nums[e] < nums[e - 1])
                    return e;
                e--;
            }
            else if (nums[s] < nums[m] || (nums[s] == nums[m] && nums[m] > nums[e]))
                s = m + 1;
            else
                e = m - 1;
        }
        return -1;
    }

public:
    int findMin(vector<int> &nums)
    {
        int pivot = findPivot(nums);
        if (pivot == -1)
            return nums[0];
        else
            pivot %= nums.size();
        return nums[pivot] < nums[0] ? nums[pivot] : nums[0];
    }
};