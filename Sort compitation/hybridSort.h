#ifndef HYBRIDSORT_H
#define HYBRIDSORT_H

#include<vector>
#include "insertSort.h"
#include "quickSort.h"

void hSort(std::vector<int>&arr,int begin,int end){
	if(end-begin<=100){
		for (int i = begin ; i <= end ; i++) {
			int val = arr[i];
			int cur = i;
			while (cur > begin && arr[cur - 1] > val) {
				arr[cur] = arr[cur - 1];
				cur--;
			}
			arr[cur] = val;
		}
	}else{
		if(begin<end){
			int key=arr[begin];
			int forward=begin;
			int backward=end;
			while(forward<backward){
				while(forward<backward && arr[backward]>=key){
					backward--;
				}
				if(forward<backward){
					arr[forward++]=arr[backward];
				}
				while(forward<backward && arr[forward]<key){
					forward++;
				}
				if(forward<backward){
					arr[backward--]=arr[forward];
				}
			}
			arr[forward]=key;
			hSort(arr,begin,forward-1);
			hSort(arr,forward+1,end);
		}
	}
	
}

void hybridSort(std::vector<int>&arr,int len){
	if(len==1){return;}
	hSort(arr,0,len-1);
	
}

#endif