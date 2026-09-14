class Solution {
public:

    int find( vector<int>&arr , int target){
        int l=0,r=0;
        int n = arr.size();
        int cnt = 0;
        int sumi = 0;
        while(r < n ){
            sumi+=arr[r];
            while(sumi > target){
                sumi-=arr[l];
                l++;
            }

            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

        vector<int>arr;
        for( int x : nums) {
            if(x%2 == 1 ) arr.push_back(1);
            else arr.push_back(0);
        }

        return find(arr,k)-find(arr,k-1);
    }
};