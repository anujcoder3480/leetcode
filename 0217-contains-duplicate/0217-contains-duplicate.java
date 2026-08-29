class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;
        int i=0;
        int j=1;
        while(j<n){
            if(nums[i]==nums[j]){
                return true;
            }
            j++;
            i++;
        }
        return false;
    }
}