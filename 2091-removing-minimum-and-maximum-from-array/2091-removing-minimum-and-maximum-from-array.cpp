class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        vector<int>target(2 ,0);
        int mini = nums[0];
        int maxi = nums[0];
        int n = nums.size();

        for( int i=0;i<n;i++){
            if( nums[i] > maxi ) {
                target[0] = i;
                maxi = nums[i];
            }
            if( nums[i] < mini ){
                target[1] = i;
                mini = nums[i];
            }

        }

        if( target[0] == target[1] ) return 1;

        sort(target.begin() , target.end());

        int op = n;
   
        op = min(target[1]+1 , op);

        op = min(op , n-target[0]);

        op = min(op , target[0]+1 + n-target[1]);


        return op;

    }
};