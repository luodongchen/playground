class Solution {
    public int matrixScore(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int sum=(1<<(n-1))*m;

        for(int j=1;j<n;j++){
            int val=1<<(n-1-j);
            int set=0;

            for(int i=0;i<m;i++){
                if(grid[i][j]==grid[i][0]){
                    set++;
                }
            }
            sum+=Math.max(set,m-set)*val;
        }

       
        
        return sum;
    }
}
