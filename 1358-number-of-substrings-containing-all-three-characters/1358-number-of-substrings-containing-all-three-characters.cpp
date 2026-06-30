class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int last[3] = {-1, -1 ,-1};
        for( int i=0;i<s.length();i++){
            last[s[i]-'a'] = i;
            cnt = cnt + 1 + min(last[0] , min(last[1],last[2]));
        }
        return cnt;
    }
};