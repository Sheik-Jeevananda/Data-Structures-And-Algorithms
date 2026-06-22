class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        for (char ch : text) {
                freq[ch - 'a']++;
        }

        int cnt = 0;

        while (true) {
            if (freq['b' - 'a'] < 1 ||
                freq['a' - 'a'] < 1 ||
                freq['l' - 'a'] < 2 ||
                freq['o' - 'a'] < 2 ||
                freq['n' - 'a'] < 1)
                break;

            cnt++;

            freq['b' - 'a']--;
            freq['a' - 'a']--;
            freq['l' - 'a'] -= 2;
            freq['o' - 'a'] -= 2;
            freq['n' - 'a']--;
        }

        return cnt;
    }
};