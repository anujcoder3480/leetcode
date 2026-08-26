class Solution {
    public int[] twoSum(int[] arr, int target) {
        int right=arr.length-1;
        int left=0;
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum==target) return new int[]{left+1,right+1};
            else if(sum>target){
                right--;
            }
            else left++;
        }
        return new int[]{};
    }
}