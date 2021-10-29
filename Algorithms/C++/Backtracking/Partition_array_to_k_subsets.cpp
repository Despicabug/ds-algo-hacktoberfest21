#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
  
  
  bool solution(int* a , int n , int k , int target , vector<int> vec , int index , vector<bool> visited  , int subset_index){
      
      if(subset_index == k){
          for(int i=0 ; i<n ; i++){
              if(visited[i] == false){
                  return false;
              }
          }
          return true;
      }
      
      if(index==n){
          if(vec[subset_index] == target){
              return solution(a , n , k , target , vec , 0 , visited , subset_index+1);
          }
          return false;
      }
      
      

         
         if(visited[index] == false){
            vec[subset_index] += a[index];
            visited[index] = true;
             if(solution(a , n , k , target , vec , index+1 , visited , subset_index)){
                  return true;
              }
            vec[subset_index] -= a[index];
            visited[index] = false;
         }
         

          
        if(solution(a , n , k , target , vec , index+1 , visited , subset_index)){
              return true;
         }
 
      
      return false;
      
  }
  
  
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
         
         int sum = 0;
         for(int i=0 ; i<n ; i++){
             sum += a[i];
         }
         
         if(k>n){
             return false;
         }
         
         if(k==1){
             return true;
         }
         
         if(sum%k != 0){
             return false;
         }
         
         vector<int> vec(k,0);
         for(int i=0 ; i<k ; i++){
             vec[i] = 0;
         }
         vector<bool> visited(n,false);
        for(int i=0 ; i<n ; i++){
             visited[i] = false;
         }
         return solution(a , n , k , sum/k , vec , 0 , visited , 0);
         
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  