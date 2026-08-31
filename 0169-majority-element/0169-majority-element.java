class Solution {
    public int majorityElement(int[] arr) {
        Arrays.sort(arr);
        int cnt=1;
        int n=arr.length;
        if(n==1) return arr[0];
        for(int i=0; i<arr.length; i++){
            if(arr[i]==arr[i+1]) cnt++;
            if(cnt>n/2) return arr[i];
            if(arr[i]!=arr[i+1]) cnt=1;
        }
        return cnt;
    }
}