class Solution {
public:
    long long sumAndMultiply(int n) {
        if(!n) return 0;
        string ans = "";
        long long sum = 0;

        while (n) {
            if (n % 10 != 0) {
                sum += n % 10;
                ans += char('0' + n % 10);
            }
            n /= 10;
        }

        reverse(ans.begin(), ans.end());

        return stoll(ans) * sum;
    }
};