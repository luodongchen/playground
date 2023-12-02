#ifndef RADIXSORT_H
#define RADIXSORT_H

#include<vector>
#include<cmath>

int getDigit(int num, int index){
    int n=pow(2,index);
    //int x=(n&num)/n;
    //std::cout<<num<<" "<<x<<" "<<index<<std::endl;
    return (n&num)/n;
}

void radixSort(std::vector<int>&arr,int len){
    std::vector<std::vector<int>> pos(2);
    std::vector<std::vector<int>> neg(2);
    for(int i=0;i<32;i++){
        pos[0].clear();
        pos[1].clear();
        neg[0].clear();
        neg[1].clear();
        
        for(int j=0;j<len;j++){
            if(arr[j]<0){
                neg[getDigit(arr[j],i)].push_back(arr[j]);
            }else{
                pos[getDigit(arr[j],i)].push_back(arr[j]);
            }
        }
        
        int index=0;
        for(int j=0;j<2;j++){
            for(int e:neg[j]){
                arr[index++]=e;
            }
        }
        for(int j=0;j<2;j++){
            for(int e:pos[j]){
                arr[index++]=e;
            }
        }
    }
    
}

#endif