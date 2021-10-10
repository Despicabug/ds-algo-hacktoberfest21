class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        vector<vector<int>> mat(numRows, vector<int>(s.length(), -1));
        int i = 0, j = 0, counter = 0;
        string ans;

        while (counter < s.length())
        {
            while (i < numRows and counter < s.length())
            {
                mat[i][j] = counter++;
                i++;
            }

            if (counter >= s.length())
            {
                break;
            }

            j++;
            i = numRows - 2;
            while (i >= 0 and counter < s.length())
            {
                mat[i][j] = counter++;
                i--;
                j++;
            }
            i = 1;
            j--;
        };

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] > -1)
                {
                    ans += s[mat[i][j]];
                }
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/zigzag-conversion/