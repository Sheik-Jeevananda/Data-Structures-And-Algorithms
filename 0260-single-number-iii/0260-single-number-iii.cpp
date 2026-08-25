class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long x = 0;
        for( int i=0;i<nums.size();i++) x = x ^ nums[i];

        int rightMost = ( x & x-1)^ x;

        int b1 =0;
        int b2 =0;

        for( int i=0;i<nums.size();i++){
            if( nums[i]&rightMost ) b1 = b1^nums[i];
            else b2 = b2 ^ nums[i];
        }

        return {b1,b2};
    }
};