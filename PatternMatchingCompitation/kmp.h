#ifndef KMP_H
#define KMP_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> computeLPS(string pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;

    lps[0] = 0; 

    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int kmp(string& text, string& pattern) {
    int count = 0;
    int n = text.length();
    int m = pattern.length();

    
    vector<int> lps = computeLPS(pattern);

    int i = 0; 
    int j = 0; 

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            count++;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return count;
}



#endif