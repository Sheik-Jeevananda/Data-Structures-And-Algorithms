class Solution {
public:
    int f( int i , int buy , int c , int k , vector<int>&prices , vector<vector<vector<int>>>&dp ){
        if( i == prices.size() ) return 0;
        if( c >= k ) return 0;
        if(dp[i][buy][c]!=-1 ) return dp[i][buy][c];
        if( buy ){
            return dp[i][buy][c] = max( -prices[i] + f(i+1 , 0 , c , k ,prices, dp), 0 + f( i+1 , 1 , c , k, prices,dp));
        }else{
            return dp[i][buy][c] = max( +prices[i] + f(i+1 , 1 , c+1, k, prices,dp ) , 0 + f(i+1 , 0 , c , k, prices,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp( n+1 , vector<vector<int>>(2 , vector<int>(k+1 , -1)));
        return f( 0 , 1 , 0 , k , prices , dp); 
    }
};