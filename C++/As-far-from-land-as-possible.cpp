/*
Problem:  https://leetcode.com/problems/as-far-from-land-as-possible/

Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.


*/

// Time Complexity: O(N^2)
// Space Complexity: O(N^2) 


#include <bits/stdc++.h>
using namespace std;

  //We traverse the grid 2 times, first from left up -> bottom right, second bottom right -> left up.

    int maxDistance(vector<vector<int>>&a) {
        int n=a.size();
        int m=a[0].size();
        
        vector<vector<int>>dp=a;

      //In the first loop, we update the minimum distance to reach a '1' from the current position either keep going left or going upward. Here's a
      //small trick, i pick 201 as the max value, cuz per the problem description, the # of rows won't exceed 100, so the length 
      //  of longest path in the matrix will not exceed 200
      
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==1){
                    continue;
                }
                dp[i][j]=201;
                if(i>0){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                }
                if(j>0){
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                }
            }
        }
        int ans=0;
      
        // In the second loop, we go from bottom right to up left to update the min distance from another side. At the end, please not that res is not the value we want,
        // if there's no '1's in the matrix, all the entry will be set to 201 in such
        // a case, we should return -1 instead of 201; if there are '1's in the matrix, as mentioned at the begining, res is the maximum distance + 1, so we need res-1.
      
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(dp[i][j]==1){
                    continue;
                }
                if(i<n-1){
                    dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
                }
                if(j<m-1){
                    dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans==201?-1:ans-1;
        
    }



int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a;
    a.resize(n);
    for(int i=0;i<n;i++){
        a[i].resize(m);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int cnt=maxDistance(a);
    cout<<cnt;

}

  
  
  
  
