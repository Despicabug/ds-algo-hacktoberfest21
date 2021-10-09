class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> st;
        int i = 0, ans = 0, n = height.size();

        while (i < n)
        {
            while (!st.empty() and height[st.top()] < height[i])
            {
                int curr = st.top();
                st.pop();
                if (st.empty())
                {
                    break;
                }

                int diff = i - st.top() - 1;
                ans += (min(height[st.top()], height[i]) - height[curr]) * diff;
            }
            st.push(i++);
        }
        return ans;
    }
};

// https://leetcode.com/problems/trapping-rain-water/