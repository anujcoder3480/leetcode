class Solution {
    public int[] sortedSquares(int[] arr) {
        int n=arr.length;
        int[] arr2=new int[n];
        for(int i=0; i<n; i++){
            arr2[i]=arr[i]*arr[i];
        }
        Arrays.sort(arr2);
        return arr2;
    }
}