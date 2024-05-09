#ifndef RABINKARP_H
#define RABINKARP_H
#include <iostream>
#include <string>
//#include <cmath>


const int prime = 101; 
const int digit = 51;

int pow(int d, int p) {
    int r =1;
    for(int i=0; i<p; i++) {
        r = r*d % prime;
    }
    return r;
}



int calculateHash(std::string& str) {
    int len = str.length();
    int hash = 0;
    for (int i = 0; i < len; ++i) {
        hash = (hash +   ( (int)str[len-i-1]    * pow(digit, i) )%prime )%prime;
    }
    return hash;
}


int updateHash(int oldHash, char oldChar, char newChar, int XXX) {
    int newHash = 0;
    newHash = (oldHash- (int)(oldChar*  XXX ))%prime;
    newHash = (newHash*digit + newChar)%prime;
    newHash = (newHash+prime)%prime;
    return newHash;
}


int RobinKarp(std::string& T, std::string& P) {
    int count = 0;
    int m = T.length();
    int n = P.length();
    int patternHash = calculateHash(P);
    std::string str = T.substr(0,n);
    int textHash = calculateHash(str);
    int XXX = pow(digit,n-1);

    for (int i = 0; i <= m - n; ++i) {
        if (patternHash == textHash) {
            int j;
            for (j = 0; j < n; ++j) {
                if (T[i + j] != P[j])
                    break;
            }
            if (j == n) {
                count++;
            }
        }
        if (i < m - n) {
            textHash = updateHash(textHash, T[i], T[i + n], XXX);
        }
    }
    return count;
}



#endif