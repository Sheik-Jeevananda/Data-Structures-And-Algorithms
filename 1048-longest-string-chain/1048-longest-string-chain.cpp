class Solution {
public:
    bool check( string &s1 , string &s2){
        if(s1.length() != s2.length()+1 ) return false;

        int first = 0;
        int second = 0;

        while( first < s1.length()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }else{
                first++;
            }
        }

        if(first == s1.length() && second == s2.length()) return true;
        else return false;
    }
    static bool comp( string &s1  , string &s2){
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int>dp(n , 1);

        sort(words.begin() , words.end() , comp);
        int maxi = 1;
        for( int i=0;i<n;i++){
            for( int prev=0;prev<i;prev++){
                if(check(words[i] , words[prev]) && dp[prev]+1 > dp[i]){
                   dp[i] = 1 + dp[prev];
                }
            }
            maxi = max( maxi , dp[i]);
        }
        return maxi;
    }
};