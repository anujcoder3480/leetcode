class Solution {
    public void moveZeroes(int[] nums) {
        int n=nums.length;
        int i=0;
        int a=0;
        while(i<n){
            if(nums[i]!=0){
                nums[a]=nums[i];
                a++;
            }
            i++;
        }
        while(a<i){
            nums[a]=0;
            a++;
        }
    }
}