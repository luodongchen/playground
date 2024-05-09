class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long sum = 0;
        int index=0;
        for(int i=happiness.length-1;i>=happiness.length-k;i--){
            happiness[i]=Math.max(happiness[i]-index++,0);
            sum+=happiness[i];
        }
        
        return sum;
    }
}
