class Solution {
public:
    int f( int i , int j , string &s1 , string &s2,vector<vector<int>>&dp){
        if( i ==  0 || j == 0 ) return 0;
        if(dp[i][j] !=-1) return dp[i][j];
        if( s1[i-1] == s2[j-1] ) return dp[i][j] =  1 + f( i-1 , j-1 , s1 ,s2,dp);
        else{
            return dp[i][j] =  0 + max(f(i , j-1 ,s1 ,s2,dp ) , f(i-1 , j , s1 ,s2,dp));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp( n+1, vector<int>(m+1 , -1));
        int lcs = f( n , m , word1 , word2  ,dp);
        int w1 = n-lcs;
        int w2 = m-lcs;
        return w1+w2;
    }
};