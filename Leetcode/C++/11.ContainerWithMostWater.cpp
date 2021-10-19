class Solution {
public:
    int maxArea(vector<int>& height) {
        int p,prod;int ans=0;
         int i=0;
        int j=height.size()-1;
         while(i<j)
        {        
             p=min(height[i],height[j]);
             prod=p*(j-i);
             ans=max(prod,ans);
              if(height[i]<height[j])
                  i++;
             else
                 j--;
             
      }
        return ans;
    }
};