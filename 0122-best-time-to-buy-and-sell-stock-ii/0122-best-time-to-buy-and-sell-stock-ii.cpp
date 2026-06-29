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
        vector<vector<int>>dp( prices.size() , vector<int>(2 , -1));
        return f(0 , 1 , prices , dp);
    }
};