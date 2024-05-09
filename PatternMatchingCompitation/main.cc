#include <algorithm>
#include <bits/chrono.h>
#include <iostream>
#include <random>
#include <cassert>
#include <chrono>
#include<vector>
#include<string>
#include<fstream>

#include "BruteForce.h"
#include "RabinKarp.h"
#include "kmp.h"
#include "sunday.h"
#include "fsm.h"



long run(int (*fn)(std::string&, std::string&), std::string &T, std::string &P) {
	
	auto start = std::chrono::steady_clock::now();
	int t = fn(T, P);
	auto end = std::chrono::steady_clock::now();
	//std::cout << t << std::endl;
	return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int main() {

	std::string file_path = "PDG.txt";  

    
    std::ifstream file(file_path);

    
    if (!file.is_open()) {
        std::cerr << "fail to open：" << file_path << std::endl;
        return 1;
    }

    std::vector<std::string> text;

    std::string line;
    
    while (std::getline(file, line)) {
        text.push_back(line);
    }
    
	file.close();

	
	std::string P = "Dorian";

	const int times = 100;
	int limit=text.size();
	std::cout<<limit<<std::endl;
	std::cout << "size	Brute Force		Robin Karp		KMP			Sunday 			FSM" << std::endl;
	
		for (int size = 10 ; size < limit ; size+=100 ) {
			//std::cout<<size<<std::endl;
			long long BF = 0;
			long long RK = 0;
			long long KMP = 0;
			long long SUN = 0;
			long long FSM = 0;
			
			std::string T = "";
			for (int i = 0 ; i < size ; i++) {
					T+=text[i];
			}
			//std::cout<<T<<std::endl;
			for (int t = 0 ; t < times ; t++) {
				

				BF += run(BruteForce ,T ,P);
				//std::cout<<"BF completed!"<<std::endl;
				RK += run(RobinKarp,T ,P);
				//std::cout<<"RK completed!"<<std::endl;
				KMP += run(kmp,T ,P);
				//std::cout<<"KMP completed!"<<std::endl;
				SUN += run(Sunday,T,P);
				//std::cout<<"SUN completed!"<<std::endl;
				FSM += run(fsm,T,P);
				//std::cout<<"FSM completed!"<<std::endl;
				
			}

			//std::cout<<"*"<<std::endl;

			
			std::cout
				<< size << "	"
				<< BF / times << "			"
				<< RK / times << "			"
				<< KMP / times << "			"
				<< SUN / times << "			"
				<< FSM / times << "			"
				<< std::endl;
			
			
		}
	

	return 0;
}