#ifndef INSERTSORT_H
#define INSERTSORT_H

#include <algorithm>
#include <vector>

void insertSort(std::vector<int>&arr, int len) {
	for (int i = 1 ; i < len ; i++) {
		int val = arr[i];
		int cur = i;

		while (cur > 0 && arr[cur - 1] > val) {
			arr[cur] = arr[cur - 1];
			cur--;
		}

		arr[cur] = val;
	}
}

#endif
