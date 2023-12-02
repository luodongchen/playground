#ifndef HEAPSORT_H
#define HEAPSORT_H

#include<vector>
#include<iterator>
#include<algorithm>


bool isHeap(std::vector<int>&arr,int len,int index){
    if(index>=len/2 && index<len){
        return true;
    }else{
        if(2*index+1==len-1){
		 	if(arr.at(index)>=arr.at(2*index+1)){
                return false;
            }else{
                return isHeap(arr,len,2*index+1);
			}  
		}
		if(!(arr.at(index)<=arr.at(2*index+1) && arr.at(index)<=arr.at(2*index+2))){
			return false;
		}else{
			return isHeap(arr,len,2*index+1) && isHeap(arr,len,2*index+2);
		}    
	} 
}


void heapMaker(std::vector<int>&arr,int len,int index){

	int mark=index;
	if(2*index+1<len && arr.at(mark)<arr.at(2*index+1)){
		mark=2*index+1;
	}
	if(2*index+2<len && arr.at(mark)<arr.at(2*index+2)){
		mark=2*index+2;
	}
	if(mark!=index){
		std::iter_swap(arr.begin()+index,arr.begin()+mark);
		heapMaker(arr,len,mark);
	}
	

}
	

void fixHeap(std::vector<int>&arr,int len){
	for(int index=len/2-1;index>=0;index--){
		heapMaker(arr,len,index);
	}
}


void heapSort(std::vector<int>&arr,int len){
	fixHeap(arr,len);
	for(int index=len-1;index>=0;index--){
		std::iter_swap(arr.begin(),arr.begin()+index);
		heapMaker(arr,index,0);
	}	
}


#endif
