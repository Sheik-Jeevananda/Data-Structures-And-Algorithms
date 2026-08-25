class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        long i = k;
        while( true){
            if( find( nums.begin(),nums.end() , i) == nums.end()) return i;
            i = i + k;
        }
    }
};