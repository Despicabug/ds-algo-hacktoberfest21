class Solution
{
public:
    int getMax(vector<int> &nums, int partition)
    {
        if (partition == 0)
        {
            return INT_MIN;
        }
        return nums[partition - 1];
    }

    int getMin(vector<int> &nums, int partition)
    {
        if (partition == nums.size())
        {
            return INT_MAX;
        }
        return nums[partition];
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        int low = 0;
        int high = nums1.size();
        int totalLength = nums1.size() + nums2.size();

        while (low <= high)
        {
            int partitionX = (low + high) / 2;
            int partitionY = (totalLength + 1) / 2 - partitionX;

            int LeftX = getMax(nums1, partitionX);
            int RightX = getMin(nums1, partitionX);

            int LeftY = getMax(nums2, partitionY);
            int RightY = getMin(nums2, partitionY);

            if (LeftX <= RightY && LeftY <= RightX)
            {
                if (totalLength % 2 == 0)
                {
                    return (max(LeftX, LeftY) + min(RightX, RightY)) / 2.0;
                }
                return max(LeftX, LeftY);
            }

            if (LeftX > RightY)
            {
                high = partitionX - 1;
            }

            if (LeftY > RightX)
            {
                low = partitionX + 1;
            }
        }
        return -1;
    }
};

// https://leetcode.com/problems/median-of-two-sorted-arrays/