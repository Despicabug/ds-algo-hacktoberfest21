#include <iostream>
#include <vector>
class Solution {
public:
    int arr[1000001][2][2];
    int help(vector<int>&prices,int curr,bool canbuy, int t)
    {
        if(curr>=prices.size()|| t==0)
            return 0;
        if(arr[curr][canbuy][t]!=-1)
            return arr[curr][canbuy][t];
        if(canbuy==true)
        {
            int idle=help(prices,curr+1,canbuy,t);
            int buy=-prices[curr]+help(prices,curr+1,false,t);
            arr[curr][canbuy][t]=max(idle,buy);
    
        }
        else
        {
            int idle=help(prices,curr+1,canbuy,t);
            int sell=prices[curr]+help(prices,curr+1,true,t-1);
            arr[curr][canbuy][t]= max(idle,sell);
        
        }
        return arr[curr][canbuy][t];
    }
    int maxProfit(vector<int>& prices) {
         memset(arr,-1,sizeof(arr));
      return help(prices,0,true,1);
    }
};