class Solution {
public:
    bool f( int i , int j , string &s1 , string &s2, vector<vector<int>>&dp){
        
        if( i<0 && j>=0 ) {
            for( int k=0;k<=j;k++) {
                if(s2[k]!='*') return false;
            }
            return true;
        }

        if(i<0 && j<0 ) return true;
        if(i>=0 && j<0) return false;
        if(dp[i][j]!=-1 ) return dp[i][j];
       if( s1[i] == s2[j] || s2[j] == '?') return dp[i][j] = f(i-1 , j-1 , s1 ,s2, dp);
       if( s2[j] == '*' ) return dp[i][j] = f( i,j-1 , s1 ,s2, dp ) || f(i-1 , j , s1 ,s2,dp);
       return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>>dp(n , vector<int>(m, -1));
        return f(n-1 , m-1 , s , p , dp);
    }
};