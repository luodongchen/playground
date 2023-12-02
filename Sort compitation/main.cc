
#include <algorithm>
#include <bits/chrono.h>
#include <iostream>
#include <random>
#include <cassert>
#include <chrono>
#include<vector>

#include "heapSort.h"
#include "quickSort.h"
#include "insertSort.h"
#include "radixSort.h"
#include "hybridSort.h"



long run(void (*fn)(std::vector<int>&, int), std::vector<int> &xs, int len) {
	std::vector<int> cpy = xs;
	//std::copy_n(xs.data(), len, cpy.data());

	/*for (int i =  0 ; i < len ; i++) {
		std::cout << xs[i] << " ";
	}
	std::cout << std::endl;
		for (int i =  0 ; i < len ; i++) {
		std::cout << cpy[i] << " ";
	}
	std::cout << std::endl;
	*/
	auto start = std::chrono::steady_clock::now();
	fn(cpy, len);
	auto end = std::chrono::steady_clock::now();
	/*for (int i =  0 ; i < len ; i++) {
		std::cout << xs[i] << " ";
	}
	std::cout << std::endl;
		for (int i =  0 ; i < len ; i++) {
		std::cout << cpy[i] << " ";
	}
		std::cout << std::endl;*/
	assert(std::is_sorted(cpy.begin(), cpy.begin() + len));

	cpy.clear();

	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

int main() {
	std::random_device rd;
	std::mt19937 gen(rd());

	const int times = 100;

	std::cout << "size	HeapSort		InsertionSort		QuickSort	RadixSort 		HybridSort" << std::endl;
	for (int power = 1 ; power < 10'000 ; power *= 10) {
		for (int d = 1 ; d < 10 ; d++ ) {
			int size = d * power;
			std::uniform_int_distribution<> dist(-size, size);
			
			long long hea = 0;
			long long ins = 0;
			long long qui = 0;
			long long rad = 0;
			long long hyb = 0;
			
			/*long long hea_sorted = 0;
			long long ins_sorted = 0;
			long long qui_sorted = 0;
			long long rad_sorted = 0;*/
			
			std::vector<int> xs = std::vector<int>(size);
			
			for (int t = 0 ; t < times ; t++) {
				for (int i = 0 ; i < size ; i++) {
					xs[i]=dist(gen);
					
				}

				hea += run(heapSort, xs, size);
				ins += run(insertSort, xs, size);
				qui += run(quickSort, xs, size);
				rad += run(radixSort,xs, size);
				hyb += run(hybridSort,xs,size);
				
				/*for (int i = 0 ; i < size ; i++) {
					xs[i] = i;
				}

				hea_sorted += run(heapSort, xs, size);
				ins_sorted += run(insertSort, xs, size);
				qui_sorted += run(quickSort, xs, size);
				rad_sorted += run(radixSort, xs, size);
				*/
			}

			

			
			std::cout
				<< size << "	"
				<< hea / times << "			"
				<< ins / times << "			"
				<< qui / times << "			"
				<< rad / times << "			"
				<< hyb / times << "			"
				/*<< hea_sorted / times << "      "
				<< ins_sorted / times << "      "
				<< qui_sorted / times << "      "
				<< rad_sorted / times */<< std::endl;
			
			xs.clear();
		}
	}

	return 0;
}

