#ifndef FSM_H
#define FSM_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


std::vector<std::unordered_map<char, int>> buildDFA(std::string& pattern) {
    int M = pattern.size(); 
    std::vector<std::unordered_map<char, int>> dfa(M + 1);

    dfa[0][pattern[0]] = 1; 

    int X = 0; 
    for (int j = 1; j < M; j++) {
       
        dfa[j] = dfa[X];
      
        dfa[j][pattern[j]] = j + 1;
       
        X = dfa[X][pattern[j]];
    }

    return dfa;
}


int match(std::vector<std::unordered_map<char, int>>& dfa, std::string& text) {
    int M = dfa.size() - 1;
    int N = text.size(); 
    int count = 0;

    int state = 0; 
    for (int i = 0; i < N; i++) {
        if (dfa[state].count(text[i])) {
            state = dfa[state][text[i]];
            if (state == M) {
                count++; 
                state=0;
            }
        } else {
            state = 0; 
        }
    }

    return count; 
}


int fsm(std::string& T, std::string& P){
    std::vector<std::unordered_map<char, int>> dfa = buildDFA(P);
    return  match(dfa,T);
}


#endif