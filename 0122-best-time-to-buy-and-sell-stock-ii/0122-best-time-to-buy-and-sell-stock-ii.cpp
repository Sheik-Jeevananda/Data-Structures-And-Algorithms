class Solution {
public:
    int f( int i , int buy , vector<int>&arr ,  vector<vector<int>>&dp){
        if( i == arr.size() ) return 0;
        int profit = 0;
        if(dp[i][buy]!=-1 ) return dp[i][buy];
        if(buy){    
            profit = max( -arr[i]+f(i+1, 0 , arr, dp) , 0 + f(i+1 , 1 , arr, dp));
        }else{
            profit = max( +arr[i]+f(i+1 , 1 , arr , dp), 0 + f(i+1 , 0 , arr , dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp( prices.size()+1 , vector<int>(2 , 0));
        int n = prices.size();
        dp[n][0] = dp[n][1] = 0;
        for( int i=n-1;i>=0;i--){
            for( int buy=1;buy>=0;buy--){
            int profit = 0;
            if(buy){    
                profit = max( -prices[i]+dp[i+1][0] , 0 + dp[i+1][1] );
            }else{
                profit = max( +prices[i]+dp[i+1][1], 0 + dp[i+1][0]);
             }
            dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};