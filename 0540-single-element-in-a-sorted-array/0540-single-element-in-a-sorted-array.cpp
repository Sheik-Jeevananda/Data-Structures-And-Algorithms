class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

       int low = 0;
       int high = nums.size()-1;
        if( nums.size() <= 1 ) return nums[0];
        if(nums[0]!=nums[1] ) return nums[0];

        while( low<=high){
            
            int mid = (low+high)/2;

            if( (nums[mid]!=nums[mid-1]) && (nums[mid]!=nums[mid+1])) return nums[mid];

            if( nums[mid] == nums[mid-1] ){
                if( (mid-1)%2 == 1 ) high = mid-1;
                else low = mid+1;  
            }else{
                if( (mid+1)%2 == 1 ) low = mid+1;
                else high = mid-1;
            }

        }
        return -1;
    }
};