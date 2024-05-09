#ifndef SUNDAY_H
#define SUNDAY_H

#include <iostream>
#include <string>
#include <unordered_map>



std::unordered_map<char, int> computeSkipTable(std::string& P) {
    std::unordered_map<char, int> skipTable;
    int n = P.length();

    for (int i = 0; i < n; ++i) {
        skipTable[P[i]] = n - i;
    }

    return skipTable;
}


int Sunday(std::string& T, std::string& P) {
    int m = T.length();
    int n = P.length();
    int count = 0;
    
    std::unordered_map<char, int> skipTable = computeSkipTable(P);
    
    int i = 0;
    while (i <= m - n) {
        int j = 0;
        while (j < n && P[j] == T[i + j]) {
            j++;
        }
        if (j == n) {
            count++;
            i++;
        } else {
            char nextChar = T[i + n];
            if (skipTable.find(nextChar) != skipTable.end()) {
                i += skipTable[nextChar];
            } else {
                i += n + 1;
            }
        }
    }
    return count;
}



#endif