class Solution {
public:
      int f( int i , int  j , string&s1 , string &s2 ,vector<vector<int>>&dp){
        if( i<0 || j < 0 ) return 0;
        if(dp[i][j]!=-1 ) return dp[i][j];
        if( s1[i] == s2[j] ) return dp[i][j] = 1 + f(i-1 , j-1 , s1 ,s2 , dp);
        else return dp[i][j] =  0 + max(f(i-1 , j , s1 ,s2 , dp ) , f(i , j-1, s1 ,s2 , dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s2 = s;
        reverse(s2.begin() , s2.end());
        vector<vector<int>>dp( n ,vector<int>(n,-1));
        return f( n-1 , n-1 ,s , s2 ,  dp);
    }
};