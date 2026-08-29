class Solution {
    public int[] twoSum(int[] arr, int target) {
        int n=arr.length;
        int i=0;
        int j=1;
        int[] arr2=new int[2];
        while(i<n-1){
            if(arr[i]+arr[j]==target){
                arr2[0]=i;
                arr2[1]=j;
                return arr2;
            }
            j++;
            if(j==n) {
                j=i+2;
                i=i+1;
            }
        }
        return arr2;
    }
}