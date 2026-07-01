class Solution {
public:
    int f( int ind , int buy , int trans , vector<int>&prices , vector<vector<vector<int>>>&dp){
        if(trans == 0 ) return 0;
        if( ind == prices.size()) return 0;

        if(dp[ind][buy][trans]!=-1 ) return dp[ind][buy][trans];

        if(buy){
            return dp[ind][buy][trans] =  max( -prices[ind]+f(ind+1 ,0 , trans , prices,dp) , 0 + f(ind+1 , 1 , trans ,prices,dp));
        }
        else{
           return dp[ind][buy][trans] =  max( +prices[ind] + f(ind+1 ,1 , trans-1 ,prices,dp) , 0 + f(ind+1 , 0 , trans,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp( n , vector<vector<int>>( 2 , vector<int>(3 , -1)));
        return f(0 , 1 , 2 , prices , dp);
    }
};