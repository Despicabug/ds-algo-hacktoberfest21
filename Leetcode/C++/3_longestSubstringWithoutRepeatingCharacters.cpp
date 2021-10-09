class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        if (s.length() <= 1)
        {
            return s.length();
        }
        if (s.length() == 2)
        {
            if (s[0] == s[1])
                return 1;
            else
                return 2;
        }

        int first = 0, second = 1;
        int currMax = 0, tempMax = 1;
        while (second < s.length())
        {
            if (s.find(s[second], first) == second)
            {
                tempMax += 1;
            }
            else
            {
                first += 1;
                second = first;
                currMax = max(currMax, tempMax);
                tempMax = 1;
            }
            second += 1;
        }
        return max(currMax, tempMax);
    }
};

// https://leetcode.com/problems/longest-substring-without-repeating-characters