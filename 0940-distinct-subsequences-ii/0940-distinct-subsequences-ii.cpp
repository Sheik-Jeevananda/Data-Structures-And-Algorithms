class Solution {
public:
    int f(int i, string &s, vector<int>&prev, vector<int>&dp){
        if(i < 0) return 1;

        if(dp[i] != -1) return dp[i];

        long long pick = f(i-1, s, prev, dp);
        long long notPick = f(i-1, s, prev, dp);

        long long ans = pick + notPick;

        if(prev[i] != -1){
            ans -= f(prev[i]-1, s, prev, dp);
        }

        return dp[i] = ans % 1000000007;
    }

    int distinctSubseqII(string s) {
        int n = s.length();

        vector<int> lastseen(26, -1);
        vector<int> prev(n, -1);

        for(int i = 0; i < n; i++){
            prev[i] = lastseen[s[i]-'a'];
            lastseen[s[i]-'a'] = i;
        }

        vector<int> dp(n, -1);

        int mod = (int)(1e9 + 7);

        int ans = f(n-1, s, prev, dp);

        return (ans - 1 + mod) % mod;
    }
};