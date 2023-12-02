#ifndef QUICKSORT_H
#define QUICKSORT_H

#include<vector>
#include<iostream>
#include<stdlib.h>


void Partition(std::vector<int>&arr,int begin,int end){
	if(begin<end){
		int key=arr[begin];
		int pivot=begin;
		int backward=end;
		while(pivot<backward){
			while(pivot<backward && arr[backward]>=key){
				backward--;
			}
			if(pivot<backward){
				arr[pivot++]=arr[backward];
			}
			while(pivot<backward && arr[pivot]<key){
				pivot++;
			}
			if(pivot<backward){
				arr[backward--]=arr[pivot];
			}
		}
		arr[pivot]=key;
		Partition(arr,begin,pivot-1);
		Partition(arr,pivot+1,end);
	}
	
}

void quickSort(std::vector<int>&arr,int len){
	Partition(arr,0,len-1);
}


#endif