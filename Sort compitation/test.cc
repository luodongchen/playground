#include <algorithm>
#include <cassert>
#include <iostream>
#include "insertSort.h"
#include "heapSort.h"
#include "quickSort.h"
#include "radixSort.h"
#include "hybridSort.h"
#include<vector>
#include<cmath>

void test(void (*fn)(std::vector<int>&, int), std::vector<int>&xs, int len) {
	fn(xs, len);
	for(int i : xs){
		std::cout<<i<<std::endl;
	}
	assert(std::is_sorted(xs.begin(), xs.begin() + len));
}

void run_tests_on(void (*fn)(std::vector<int>&, int)) {
	{
		std::vector<int> xs = {1, 7, 8, 3, 4, 2, 5, 6};
		int len = xs.size();

		test(fn, xs, len);
	}

	{
		std::vector<int> xs = {1, 2, 3, 4, 5, 6};
		int len = xs.size();

		test(fn, xs, len);
	}

	{
		std::vector<int> xs = {1, 3, -1,-5,9};
		int len = xs.size();

		test(fn, xs, len);
	}
}

int main() {
	//run_tests_on(heapSort);
	//run_tests_on(insertSort);
	//run_tests_on(quickSort);
	//run_tests_on(radixSort);
	run_tests_on(hybridSort);
	/*for(int i=0;i<32;i++){
		int num =pow(2,i);
		int n=((-5)&num) /num;
		std::cout<<n<<std::endl;
	}*/
}
