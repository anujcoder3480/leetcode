class Solution {
    public int maximumWealth(int[][] accounts) {
        int sum=0;
        int temp=0;
        for(int i=0; i<accounts.length; i++){
            for(int j=0; j<accounts[0].length; j++){
                temp=accounts[i][j]+temp;
            }
            if(sum<temp) sum=temp;
            temp=0;
        }
        return sum;
    }
}