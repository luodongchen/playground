#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include<string>



int BruteForce(std::string& T,std::string& P){
    //std::cout<<"text:"<<T<<"pattern:"<<P<<std::endl;
    int count = 0;
    int m=T.length(), n=P.length();
    int i=0,j=0;
    while(i<m){
            if(P[j]==T[i]){
                if(j==n-1) {
                    count++;
                    i = i-(j-1);
                    j = 0;
                    }
                else {
                    i++;
                    j++;
                }
            }else{
                i=i-(j-1);
                j=0;
            }
    }
    return count;      
}










#endif