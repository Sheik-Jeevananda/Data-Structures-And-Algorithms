class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt = 0;  
        int n = nums.size();
        for( int j=0;j<n;j++){  
            int tarCnt = 0;
             for( int i =j;i<n;i++){
            // till i , is we get count(target) > len/2;
                   if( nums[i] == target ) tarCnt++;
                    int len = i - j + 1;
                    if (tarCnt > len / 2) cnt++;
             }
        }
        return cnt;
    }
};