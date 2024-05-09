class Solution(object):
    def maximumHappinessSum(self, happiness, k):
        happiness.sort(reverse=True)
        i=0
        sum=0

        while k>0:
            happiness[i]= max(happiness[i]-i,0)
            sum+=happiness[i]
            i+=1
            k-=1
        
        return sum
        
